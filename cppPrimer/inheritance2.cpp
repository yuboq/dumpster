#include <iostream>
#include <string>

class MyClass
{
  public:
    MyClass(int x) : a (x) {}
    MyClass () = default;
    MyClass (const MyClass & mc);
    virtual void print() {std::cout <<a <<std::endl;}
    int myint = 15;
    static void myFunc () {std::cout <<"print my func "<<std::endl;}
    virtual void print2() = 0;
  private:
    int a;
    friend class MyClass2;
};

class MyClass2 : public MyClass
{
  public:
    MyClass2 () = default;
    MyClass2 (int y) : b(y){myint = 16;}
    void print () override {std::cout << b <<std::endl;}
    void print2() override {std::cout <<"myclass2 " <<a  <<std::endl;}
    void f(const MyClass2 &);
  private:
    int b;
    int a = 11;
};
class MyClass3: public MyClass2
{
  public:
  void print () {std::cout <<"myclass3" <<std::endl;}
}; 
void someFunc (MyClass & mc)
{
  mc.print();
}

void MyClass2::f(const MyClass2 & derived)
{
  MyClass::myFunc();
  MyClass2::myFunc();
  derived.myFunc();
  myFunc();
}



int main()
{
  MyClass2 mc2(20);
  MyClass3 mc3;
  mc3.print2();
  mc2.print2();
}

