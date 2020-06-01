#include <iostream>

/*
class Base{

  public:
    Base (int x) : myint (x) {std::cout <<"initalized" <<std::endl;}
    Base (const Base & obj) {this->myint = obj.myint; std::cout <<"copying" <<std::endl;}

    friend class Base2;
  private:

    int myint;
};
class Base2{

  public:
    Base2(int x) : myint2(x){}

    Base2& add (const Base &b){myint2+=b.myint; return *this;}
    void print () {std::cout << myint2 <<std::endl;}
  private:
    int myint2;
};
*/

template <typename> class Base2;

template <typename T>
class Base{
  public:
    Base (T x) : myint (x) {}
    void print()const {std::cout <<"hellowrld" <<std::endl;}

    friend class Base2<T>;
  private:

    T myint;
};
template <typename T>
class Base2{
  public:
    Base2(T x) : myint2(x){}

    Base2& add (const Base<T> &b){myint2+=b.myint; return *this;}
    Base2 & print (const Base <T> &b) {b.print();return *this;}
  private:
    T myint2;
};


int main()
{
  Base<int> b(10);
  Base2 b2(20);
  //b2.add (b).print();
  b2.print(b);

  return 0;
}
