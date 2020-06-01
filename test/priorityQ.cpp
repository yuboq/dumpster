#include <iostream>
#include <queue>
#include <vector>

int main()
{
  std::priority_queue<int, std::vector<int> , std::greater<int> > a;
  for (int i = 0 ; i < 10; ++i)
  {
    a.push(i);
  }
  while (a.size())
  {
    std::cout <<a.top() <<std::endl;
    a.pop();
  }
  return 0;
}
