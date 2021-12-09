// [capture clause] (parameters) -> return type {
// 	definition of method
// }


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
 	
 	string msg = "Hello";
 	int counter = 10;

 	auto myFunc = [msg, counter] () mutable{
 		//Change won't affect the outer variable
 	};

 	auto myFunc = [&msg, &counter] () {
 		//Change will affect the outer variable
 	};

 	auto myFunc = [=] () {
 		//Capture all local variable by value
 	};

 	auto myFunc = [&] () {
 		//Capture all local variable by reference
 	};

 	myFunc();
  return 0;
}