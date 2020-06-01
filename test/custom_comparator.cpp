#include <iostream>
#include <vector>
#include <algorithm>

struct greater1{
  bool operator()(const long & a, const long & b) const{
    return a>b;
  }
};

int main()
{
  std::vector <int> myVec;
  myVec.push_back(14);
  myVec.push_back(23);
  myVec.push_back(10);
  myVec.push_back(19);
  std::make_heap (myVec.begin(), myVec.end(), greater1());
  std::cout <<myVec.front() << myVec.back() <<std::endl;
  while (myVec.size())
  {
    std::cout << myVec.front()<<std::endl;
    std::pop_heap(myVec.begin(), myVec.end(), greater1());
    myVec.pop_back();
  }
  return 0;
}

