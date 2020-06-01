#include <iostream>
#include <vector>

//find missing number in sorted array in O(log n) time

int findmissinghelper (const std::vector<int>&, int, int);
std::vector <int> genvec (int size)
{
  std::vector <int> outVec;
  for (int i = 1; i< size; ++i) {
    if (i == 5) continue;
    outVec.push_back (i);
  }
  return outVec;
}

int findmissing (const std::vector <int> & myvec){
  int midpoint = (myvec.size()-1)/2;
  if ((myvec[midpoint]- midpoint) >1)
    return findmissinghelper (myvec, 0, midpoint);
  else
    return findmissinghelper (myvec, midpoint+1, myvec.size()-1);
}

int findmissinghelper (const std::vector<int> & myvec, int beg, int end){
  if (beg == end) return myvec[beg]-1;
  int midpoint = (end-beg)/2 + beg;
  if ((myvec[midpoint] - midpoint) >1)
    return findmissinghelper (myvec, beg, midpoint);
  return findmissinghelper  (myvec, midpoint+1, end);
}
  

int main(){
  std::vector<int> myvec = genvec(10);
  //for (auto i: myvec) std::cout <<i<< " ";
  std::cout <<findmissing (myvec) <<std::endl;
}
  

