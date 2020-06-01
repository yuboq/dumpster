#include <iostream>
#include <string>

class LottaMath
{
  int a;
  int b;
  void printHelper ()const {std::cout <<a << " " <<b <<std::endl;}
  friend void printOut (LottaMath & la);

  public:
  LottaMath() = default;
  LottaMath(int x, int y): a(x), b(y) {std::cout <<"a and b initialized" <<std::endl;}
  LottaMath (int x) : a(x) {std::cout <<"a initialized" <<std::endl;} 

  ~LottaMath() {std::cout <<"destructor" <<std::endl;}

  LottaMath & add (const int c);


  inline LottaMath & sub (const int c);
  const LottaMath & print () const {printHelper(); return *this;}
  LottaMath & print () {printHelper(); return *this;}

};

void printOut (LottaMath &la)
{
  std::cout <<"in printout" <<la.a <<std::endl;
}

inline
LottaMath & LottaMath::add (const int c)
{
  a +=c;
  std::cout << a<<std::endl;
  return *this;
}

LottaMath & LottaMath::sub(const int c)
{
  a-=c;
  std::cout << a <<std::endl;
  return *this;
}

int main()
{
  LottaMath la = LottaMath(4,7);
  la.add(10).sub(10);
  la.print();
  printOut (la);

  return 0;
}
