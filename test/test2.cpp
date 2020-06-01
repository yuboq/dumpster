#include <iostream>

class Base{
  public:
    Base () : myint (0){}
    int add (int x){ return x+1;}
    friend class myfriend;
  private:
    int myint;
};

class Derived : Base {

  public:
    int add (int y) { return y+ 2;}
};

int main(){
  Base b;
  Derived d;
  std::cout << d.add (10) << std::endl;
  std::cout << b.add (10) << std::endl;
  return 0;
}
