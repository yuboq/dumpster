#include <iostream>

template <typename T> class Stack{
  public:
    Stack() {std::cout << "constructor" <<std::endl;}
};

void f1(Stack<char>);

class Exercise {
  Stack <double> &rsd;
  Stack<int> si;
};

int main() {
  int a = 5;
  int &i = a;

  a= 6;
  std::cout << i <<std::endl;

  return 0;
}
