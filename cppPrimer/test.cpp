#include <iostream>
#include <string>

class Base
{
  public:
    int sum = 1;
    std::string s = "base string";
    void printString (){std::cout << s <<std::endl;}
    void printInt () {std::cout << sum << std::endl;}
    inline Base & add(const Base & rhs);

    int add2 (const Base &rhs);
    int add2 (const Base & rhs) const;
};

Base & Base::add (const Base & rhs)
{
  sum += rhs.sum;
  std::cout <<"regular add is called " <<std::endl;
  return *this;
}

int Base::add2 (const Base & rhs)
{
  std::cout <<"in regular add2" <<std::endl;
  return 10;
}
int Base::add2 (const Base & rhs) const
{
  std::cout <<"in const add2" <<std::endl;
  return 10;
}

class Derived : public Base
{
  public:
    std::string s = "derived string";
};



void testCase()
{
  int a = 6;
  std::string s = "main string";
  Base *ptr_b1 = new Base();
  Base *ptr_b2 = new Base();

  Base b1 = Base();
  Base b2 = Base();

  b1.add(b2);

  const Base cb = Base();
  cb.add2(b2);
}

int main()
{
  

  /*
  ptr_b1->add(*ptr_b2);
  ptr_b1->printInt();
  ptr_b2->printInt();
*/


  /*
  Derived *ptr_d = new Derived();
  std::cout << ptr_b -> s << std::endl;
  std::cout <<ptr_d -> s <<std::endl;
  std::cout << s <<std::endl;
  */

  return 0;
}
