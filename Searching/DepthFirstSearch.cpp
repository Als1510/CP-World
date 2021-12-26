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

void dfs(vector<vector<int>>adj, int src, vector<bool>&visited){
	visited[src] = true;
	cout<<src<<" ";
	for(auto x: adj[src]) {
		if(!visited[x]) {
			visited[x] = true;
			dfs(adj, x, visited);
		}
	}
}

void dfs_p(vector<vector<int>>adj, int src, vector<bool>&visited, vector<int>&parent) {
	visited[src] = true;
	for(auto x: adj[src]) {
		if(!visited[x]) {
			parent[x] = src;
			visited[x] = true;
			dfs_p(adj, x, visited, parent);
		}
	}
}

void dfs_d(vector<vector<int>>adj, int src, vector<int>&distance, vector<bool>&visited) {
	visited[src] = true;
	for(auto x: adj[src]) {
		if(!visited[x]) {
			distance[x] = distance[src]+1;
			visited[x] = true;
			dfs_d(adj, x, distance, visited);
		}
	}
}

void printPath(vector<int>&distance, vector<int>&parent, int cur) {
	int i = cur;
	if(distance[cur] == -1) 
		cout<<i<<"\t"<<"No Path\n";
	else {
		vector<int>path;
		while(cur!=-1) {
			path.push_back(cur);
			cur = parent[cur];
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
  vector<bool>visited(n,0);
  dfs(adj, 0, visited);
  cout<<endl;

  // Parent
  visited.assign(n, 0);
  vector<int>parent(n, -1);
  parent[0] = -1;
  dfs_p(adj, 0, visited, parent);
  for(int x=0; x<parent.size(); x++) 
	cout<<parent[x]<<" ";
  cout<<endl;

  // Distance
  visited.assign(n, 0);
  vector<int>distance(n,0);
  distance[0] = 0;
  dfs_d(adj, 0, distance, visited);
  for(int x=0; x<distance.size(); x++) 
	cout<<distance[x]<<" ";
  cout<<endl;

  // Path
  for(int i=0; i<n; i++) 
  	printPath(distance, parent, i);

  return 0;
}