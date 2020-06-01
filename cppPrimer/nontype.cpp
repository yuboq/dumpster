#include <iostream>

template <typename T, unsigned N>
int add (T a)
{
  return N +a;
}

int main(){
  std::cout << add<int,10> (5) <<std::endl;
}
