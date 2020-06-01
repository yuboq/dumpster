#include <iostream>
#include <string>

class Base{
  public:
    Base (): myInt(10) {}
    explicit Base (int x) : myInt (x) {std::cout <<"construcotr "<< std::endl;}
    
    void print(const Base &c){std::cout <<c.myInt <<std::endl;}
    int myInt;
};


class MyClass 
{
  std::string myString;
  public:

    MyClass (): MyClass("helloworld"){std::cout <<"delegated initializer " <<std::endl;}
    MyClass (std::string s, int i) : MyClass() {std::cout <<"string int intiialized "<< std::endl;}
    MyClass (std::string s) : myString (s) {std::cout <<"string initialized "<< std::endl;}

    void myFunc1(MyClass a){std::cout <<myString + a.myString <<std::endl;}
};

int main()
{
  Base b;
  b.print (b);
  //b.print (20);
  /*
  char a ='a';
  int b = static_cast <int> (a);
  std::cout <<b <<std::endl;
  */
  /*
  std::string h = "this is a string";
  int myint = 5;
  MyClass m (h, 5) ;
  m.myFunc1 (std::string ("hello"));
  */
  return 0;
}

