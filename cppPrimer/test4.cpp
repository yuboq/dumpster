#include <iostream>
#include <vector>

int a = 3;
class NoDefault
{
  public:
  NoDefault (std::string &s){};
};

class C
{
  public :
    C() = default;
};

class B
{
  using abc = double;
  friend void print (int a) {std::cout <<::a <<std::endl;}
  public:
  abc print2();
  B():B(0) {std::cout << "in default constructor" <<std::endl;}
  B(int x): myint(x) {std::cout <<myint<< std::endl;}
  int myint;
};

B::abc B::print2 () {std::cout <<"print2" <<std::endl; return 1.0;}
int main()
{
  std::vector<C> vec(10);

  /*
  void print(int a);
  B b = B();
  b.print2();
  print (10);
  */
  return 0;
}

