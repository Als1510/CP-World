// Two ways
// Iterative
// Recursive => Divide & Conquer

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

int iterativeSearch(vector<int>arrayInt, int element) {
	int low = 0, high = arrayInt.size()-1;
	while(low<=high) {

		int mid = low + (high-low)/2;
		
		if(arrayInt[mid] == element) 
			return mid;
		
		if(arrayInt[mid] < element)
			low = mid+1;
		
		else
			high = mid-1;
	}
	return 0;
}

int recursiveBinarySearch(vector<int>arrayInt, int element, int low, int high) {
	if(low<=high) {

		int mid = low+(high-low)/2;

		if(arrayInt[mid] == element)
			return mid;
		
		if(arrayInt[mid]>element) 
			return recursiveBinarySearch(arrayInt, element, low, mid-1);
		
		else
			return recursiveBinarySearch(arrayInt, element, mid+1, high);
	}
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

  iterativeSearch(arrayInt, element)?cout<<"Found using Iterative":cout<<"Not found";
  recursiveBinarySearch(arrayInt, element, 0, size-1)?cout<<"\nFound using Recursive":cout<<"\nNot found";
  return 0;

}