// Time complexity O(V+E)
// Space complexity O(V)

#include<bits/stdc++.h>
using namespace std;

void file_i_o() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("../Input.txt","r",stdin);
    freopen("../Output.txt","w",stdout);
  #endif
}

void bfs(vector<vector<int>>adj, int src, int n) {
  queue<int>q;
  vector<bool>visited(n,0);
  q.push(src);
  visited[src] = true;
  while(!q.empty()) {
    int node = q.front();
    cout<<node<<" ";
    q.pop();
    for(auto x: adj[node]) {
      if(!visited[x]) {
        visited[x] = true;
        q.push(x);
      }
    }
  }
}

// Parent
vector<int>bfs_p(vector<vector<int>>adj, int src, int n) {
  queue<int>q;
  vector<bool>visited(n,0);
  q.push(src);
  visited[src] = true;
  vector<int>parent(n,-1);
  parent[src] = -1;
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    for(auto x: adj[node]) {
      if(!visited[x]) {
        parent[x] = node;
        visited[x] = true;
        q.push(x);
      }
    }
  }
  return parent;
}

// Distance
vector<int> bfs_d (vector<vector<int>>adj, int src, int n) {
  queue<int>q;
  vector<bool>visited(n,0);
  q.push(src);
  visited[src] = true;
  vector<int>distance(n,-1);
  distance[src] = 0;
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    for(auto x: adj[node]) {
      if(!visited[x]) {
        distance[x] = distance[node] + 1;
        visited[x] = true;
        q.push(x);
      }
    }
  }
  return distance;
}

// Print Path
void printPath(vector<int>d, vector<int>p, int cur) {
  int i = cur;
  if(d[cur] == -1) 
    cout<<i<<"\t"<<"No Path\n";
  else{
    vector<int>path;
    while(cur!=-1) {
      path.push_back(cur);
      cur = p[cur];
    }
    reverse(path.begin(), path.end());
    cout<<i<<" -> ";
    for(int x: path)
      cout<<x<<" ";
    cout<<endl;
  }
}

int main(int argc, char** argv) {   
  file_i_o();
  //write your code here Als
  int n, m;
  cin>>n>>m;
  vector<vector<int>>adj(n);
  while(m--) {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
  }

  bfs(adj, 0, n);
  cout<<endl;

  vector<int> p = bfs_p(adj, 0, n);
  for(int i=0; i<p.size(); i++)
    cout<<p[i]<<" ";
  cout<<endl;

  vector<int> d = bfs_d(adj, 0, n);
  for(int i=0; i<d.size(); i++)
    cout<<d[i]<<" ";
  cout<<endl;

  for(int i=0; i<n; i++) 
    printPath(d,p,i);

  return 0;
}