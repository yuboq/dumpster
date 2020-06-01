#include <iostream>
#include <vector>

void printVec (std::vector<int> inVec)
{
  for (auto i : inVec)
    std::cout << i ;
  std::cout << std::endl;
}
void printPerms (std::vector<int> &inVec,int l, int r)
{
  
  if (l == r)
  {
    printVec (inVec);
    return;
  }

  for (int i= l;i <=r; ++i)
  {
    std::swap(inVec[i], inVec[l]);
    printPerms (inVec, l+1, r);
    std::swap (inVec[i], inVec[l]);
  }
}

int main()
{
  std::vector <int> myVec {1,2,3};
  printPerms (myVec,0, myVec.size()-1);
  return 0;
}

