#include <iostream>
#include <string>

class MyClass1
{
  public:
    MyClass1(int x, int y, int z) : priv_mem (x), prot_mem (y), pub_mem(z){}
    MyClass1() = default;
    int pub_mem;

    void getProt() {std::cout << prot_mem <<std::endl;}
    void getPub() {std::cout <<pub_mem <<std::endl;}
    void getPriv () {std::cout << priv_mem <<std::endl;}
  protected:
    int prot_mem;
  private:
    int priv_mem;
};

class MyClass2 : public MyClass1
{
  public:
    MyClass2(int x, int y, int z) : MyClass1(x,y,z) {}
    MyClass2() = default;
    void getPub() {std::cout << pub_mem <<std::endl;}


};

class MyClass3 : private MyClass1
{
  public:
    MyClass3(int x, int y, int z) : MyClass1(x,y,z) {}
    MyClass3() = default;
    using MyClass1::prot_mem;
};

int main()
{
  MyClass2 mc2 (1,2,3);
  MyClass1 *mc1 = &mc2;
  //std::cout <<mc1->prot_mem <<std::endl;

  const int local = 10;
  int * ptr = (*ptr) &local;
  std::cout <<local << *ptr <<std::endl;

}
