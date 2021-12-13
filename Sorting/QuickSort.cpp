#include<bits/stdc++.h>
using namespace std;

void file_i_o() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("../Input.txt", "r", stdin);
    freopen("../Output.txt", "w", stdout);
  #endif  
}

int partition(vector<int>&arrayInt, int low, int high) {
  int pivot = arrayInt[high];
  int i = low-1;
  for(int j=low; j<high; j++) {
    if(arrayInt[j] <= pivot) {
      i++;
      swap(arrayInt[i], arrayInt[j]);
    }
  }
  swap(arrayInt[i+1], arrayInt[high]);
  return (i+1);
}

void quickSort(vector<int>&arrayInt, int low, int high) {
  if(low>=high)
    return;
  int pivot = partition(arrayInt, low, high);
  quickSort(arrayInt, low, pivot-1);
  quickSort(arrayInt, pivot+1, high);
}

void printArray(vector<int>arrayInt) {
  for(int i=0; i<arrayInt.size(); i++)
    cout<<arrayInt[i]<<" ";
}

int main() {
  file_i_o();
  int size;
  cin>>size;
  vector<int>arrayInt(size);
  for(int i=0; i<size; i++) 
    cin>>arrayInt[i];
  quickSort(arrayInt, 0, size-1);
  printArray(arrayInt);
}