#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


int main()
{
  int a[10]={0};
  for (auto i: a)
  {
    std::cout << i << std::endl;
  }
  std::vector<int> myVec {10,20,3,4,6,18};
  std::cout <<std::distance (myVec.begin(), std::max_element (myVec.begin(), myVec.end())) <<std::endl;
  return 0;
}
