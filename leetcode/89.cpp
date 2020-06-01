#include <iostream>
#include <vector>

std::vector<int> grayCode (int n)
{
  //my version of the gray code
  std::vector <int> res (1,0);
  for (int i =0; i< n; ++i)
  {
    int size = res.size();
    for (int j = size-1; j >=0; --j)
    {
      res.push_back (res[j] | 1 <<i);
    }
  }
  return res;
}
/*
std::vector <int> grayCode (int n)
{
  std::vector <int> res (1,0);
  std::cout << res.size() <<std::endl;
  for (int i = 0; i < n; ++i)
  {
    int size = res.size();
    for (int j = size-1; j >=0; --j)
    {
      res.push_back(res[j]|1 <<i);
    }
  }
  return res;
}
*/
int main()
{
  std::vector <int> tmp = grayCode (5);
  for (auto i: tmp)
    std::cout << i << " ";
  return 0;
}
