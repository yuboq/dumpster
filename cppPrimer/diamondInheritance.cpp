#include <iostream>
#include <string>

class Base 
{
  public:
    Base () {std::cout <<"base constructor" <<std::endl;}
    virtual void print () {std::cout <<"in base" <<std::endl;}
};

class D1: public Base
{
  public:
    D1 () {std::cout <<"D1 constructor "<<std::endl;}
    void print() override {std::cout <<"in D1 " <<std::endl;}
};
class D2 : public Base
{
  public:
    D2() {std::cout <<"D2 constructor" <<std::endl;}
    void print() override {std::cout <<"in D2 " <<std::endl;}
};

class D3 : public D1, public D2
{
  public:
    D3() {std::cout <<"D3 constructor" <<std::endl;}
};
int main()
{
  D3 d3;
  d3.D1::print();

  return 0;
}
