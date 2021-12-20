// Indexing starts from backwards

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

int main(int argc, char** argv) {   
  file_i_o();
  //write your code here Als
	bitset<8>bset(20);
	cout<<bset<<endl;
	cout<<bset.count()<<endl;
	cout<<bset.size()<<endl;
	// returns 1 if bit is set o/w 0
	for(int i=0; i<bset.size(); i++)
		cout<<bset.test(i)<<" ";

	if(bset.any())
		cout<<"\nReturns true if any bit is set"<<endl;
	if(!bset.none())
		cout<<"Returns true if none of bit is set"<<endl;

	// sets all bits
	cout<<bset.set()<<endl;
	cout<<bset.set(4, 0)<<endl;

	// reset all bits 0
	cout<<bset.reset()<<endl;

	// flip all bits 1 <--> 0 & vice-versa
	cout<<bset.flip()<<endl;
	cout<<bset.flip(2)<<endl;

	// convert decimal to binary
	int n = 113;
	cout<<bitset<8>(n)<<endl;
  return 0;
}