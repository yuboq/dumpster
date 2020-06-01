#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int mycount = 1;
void rollhelper (std::string & mystring, int pos){
  mystring[pos-1] += mycount;
  if (mystring[pos-1] > 'z') mystring[pos-1] = mystring[pos-1] -'z';
  mycount = mycount==26? 1 : mycount+1;
}

void roll (std::string & mystring, std::vector <int> & myvec){
  std::sort (myvec.begin(), myvec.end() , std::greater<int> ());
  for (auto i : myvec){
    rollhelper (mystring, i);
  }
}


int main(){
  std::string mystring = "abcdefg";
  std::vector <int> myvec = {1,2,3,4,5};

  roll (mystring, myvec);

  std::cout << mystring <<std::endl;
}
