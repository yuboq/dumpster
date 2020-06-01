#include <iostream>
#include <string>

using db = double;
class MyClass{
  public:
    MyClass (int x, std::string y): myInt(x), myString (y) { std::cout <<"called 2 arg constructor" <<std::endl; numInstances ++; }
    MyClass() : MyClass (10, "hellowlrd") {std::cout <<"called defualt constructor" <<std::endl;} 
    MyClass(int x) : MyClass (x, "somestring") { std::cout <<"1 arg constructor " <<std::endl;}

    friend void print (MyClass); 

    void print() {std::cout <<myInt <<std::endl;}

    friend class MyClass2;
    static int numInstances;

    MyClass & add (int x) {myInt += x; return *this;}
    MyClass & add (MyClass mc) {myInt += mc.myInt; return *this;}

  private:
    int myInt;
    std::string myString;
    int privateFunction () {std::cout <<"privates" <<std::endl;}
    db mydouble = 0.3;

};

class MyClass2
{
  
  public:
    MyClass2() = default;
    MyClass2(int x) : myInt(x) {}
    void showMC1Int(MyClass a) {std::cout << a.myInt <<std::endl;}
    int myInt;
};


void print(MyClass a){std::cout << a.myInt <<a.myString <<std::endl;}

int MyClass::numInstances = 0;

int main()
{
  MyClass mc1 (20, "mc1");
  MyClass mc2 (12);
  mc1.add(12).print();
  std::cout <<MyClass::numInstances <<std::endl;
}


