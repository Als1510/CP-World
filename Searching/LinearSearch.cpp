// Time complexity O(n)
// Space complexity O(1)

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

int linearSearch(vector<int>arrayInt, int element) {
	for(int i=0; i<arrayInt.size(); i++)
		if(arrayInt[i] == element)
			return 1;
	return 0;
}

int main(int argc, char** argv) {   
  file_i_o();
  //write your code here Als
 	int size;
 	cin>>size;
 	vector<int>arrayInt(size);
 	for(int i=0; i<size; i++)
 		cin>>arrayInt[i];
 	int element;
 	cin>>element;
 	linearSearch(arrayInt, element)?cout<<"Found":cout<<"Not found"; 
  return 0;
}