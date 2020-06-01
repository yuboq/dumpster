#include <iostream>

class Base
{
  public:
    Base () = default;
    Base (int x) : myInt (x) {}

    void add1 (const Base &b) {myInt += b.myInt;}
    int myInt;
};


int main()
{
  Base b(12);
  Base *ptr_b = &b;
  b.add1(4);
  std::cout <<b.myInt <<std::endl;
}

