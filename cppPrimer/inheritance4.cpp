#include <iostream>
#include <string>

extern int thisint;
class MyClass1 
{
  public:
    MyClass1() = default;
    MyClass1(int x) : myint (x)
  {
    std::cout <<"my class int constructor" <<std::endl;
  }
    static int mystat;
    virtual int add (int x) = 0;
  private:
    int myint;
};

int MyClass1::mystat = 11;
void incStat ( int & mystat)
{
  std::cout << ++mystat << std::endl;
}

class MyClass2: public MyClass1
{
  public:
    using MyClass1::MyClass1;
    MyClass2() = default;

    int add (int x) override 
    {
      myint2 +=x;
      std::cout <<myint <<std::endl;
      return myint2;
    }
  private:
    int myint2;
    int myint;

};


int main()
{
  int thisint = 12;
  std::cout <<thisint <<std::endl;
  MyClass2 mc(10);
  mc.add (20);
}
