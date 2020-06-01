#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class MyClass1 {
  public:
    MyClass1(){std::cout <<"default base constructor " <<std::endl;}
    MyClass1(int x) : myint (x) {std::cout <<" base construtor " <<std::endl;}
    virtual void printint(){std::cout <<"base" << myint <<std::endl;}

  private:
    int myint;
};

class MyClass2 : public MyClass1{
  public:
    MyClass2 () : MyClass1(10){std::cout <<"default construotr mc2 " <<std::endl;};
    MyClass2 (int x) : MyClass1(x) {std::cout <<"constructor mc2" <<std::endl;}
    void printint() override {std::cout << "in derived" <<std::endl;}
    int another=10;
};


int main()
{

  std::unordered_map <std::string, std::shared_ptr <MyClass1 >> basket;
  basket ["a"] = std::make_shared <MyClass1> (11);
  basket ["b"]  = std::make_shared <MyClass2> (12);

  /*
  std::vector < std::shared_ptr < MyClass1 >> basket;
  basket.push_back (std::make_shared <MyClass1> (11));
  basket.push_back (std::make_shared <MyClass2> (12));
  basket.back() -> printint();
  basket.front() -> printint();
  */

  /*
  std::vector< MyClass1 > basket;
  MyClass1 mc1 (11);
  MyClass2 mc2 (12);
  basket.push_back (mc1);
  basket.push_back (mc2);
  basket.back().printint();
  basket.front().printint();
  */

  return 0;
}

