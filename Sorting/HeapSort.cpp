// Time Complexity
// Worst Case - O(n*log n)
// Average Case - O(n*log n)
// Best Case - O(n*log n)

// Space Complexity - O(1)

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

void heapify(vector<int>&arrayInt, int size, int i) {
  int largest = i;
  int left = 2*i+1;
  int right = 2*i+2;

  if(left < size && arrayInt[left] > arrayInt[largest])
    largest = left;

  if(right < size && arrayInt[right] > arrayInt[largest])
    largest = right;

  if(largest != i) {
    swap(arrayInt[largest], arrayInt[i]);
    heapify(arrayInt, size, largest);
  }
}

void heapSort(vector<int>&arrayInt, int size){
  // Building Max Heap
  for(int i=size/2-1; i>=0; i--)
    heapify(arrayInt, size, i);

  //Heap Sort
  for(int i=size-1 ; i>=0; i--) {
    swap(arrayInt[0], arrayInt[i]);
    heapify(arrayInt, i, 0);
  }
}

void printArray(vector<int>arrayInt) {
  for(int i=0; i<arrayInt.size(); i++)
    cout<<arrayInt[i]<<" ";
}

int main(int argc, char** argv) {   
  file_i_o();
  //write your code here Als
  int size;
  cin>>size;
  vector<int>arrayInt(size);
  for(int i=0; i<size; i++)
    cin>>arrayInt[i];

  heapSort(arrayInt, size);
  printArray(arrayInt);
  return 0;
}