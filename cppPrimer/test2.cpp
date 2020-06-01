#include <iostream>

class B
{
  public:
    int a = 10;
    void add (B b) {std::cout <<"normal add" <<std::endl;}
    void add (B b) const {std::cout <<"const add " <<std::endl;}
};

int main()
{
  B b1 = B();
  const B b2 = B();

  b1.add (b2);
  b2.add(b1);
}





