#include <iostream>
#include <map>

void myFunc ()
{
  static int a =10;
  a++;
  std::cout << a<< std::endl;
}

class MyClass1
{
  private:
    void print ()
    {
      std::cout << "ehh bb u lik?" <<std::endl;
    }
  public:
  static int b;
  MyClass1() = default;
  MyClass1 (int x) {std::cout <<"in constructor for b" <<std::endl;}
  ~MyClass1()
  {
    std::cout <<"In destructor MyClass1 " <<std::endl;
  };


  void inc () {std::cout <<++b <<std::endl;}
};


int MyClass1::b = 10;

int main()
{

  using hashTable = std::map <int, std::string>;
  hashTable ht;
  ht[10] = "lalal";
  ht[1] = "helloworld";
  ht [2] = "this is 2";
  for (auto it = ht.begin(); it != ht.end(); ++it)
  {
    std::cout <<it->first << " " <<it ->second << std::endl;
  }
  MyClass1 mc1;
  MyClass1 mc2 = MyClass1();
  mc1 = mc2;
  std::cout << ++MyClass1::b <<std::endl;
  return 0;
}
