#include <iostream>

template <typename T>
class Base
{
  public:
    Base (T x) : myint(x) {}

    Base & operator++();
    Base operator ++(T){
      Base result (*this);
      ++(*this);
      return result;
    }
    void print () {std::cout <<myint <<std::endl;}
  private:
    T myint;
};

class Number
{
  public:
    Number () : Number (0) {};
    Number (int x) : myint (x) {}

    Number & operator++(){
      this->myint+=1;
      return *this;
    }

    Number operator++(int){
      Number result (*this);
      ++(*this);
      return result;
    }
    void print (){
      std::cout << myint <<std::endl;
    }
  private:
    int myint;
};


template <typename T>
Base<T> & Base<T>::operator++ ()
{
  this -> myint +=1;
  return *this;
}

int larger (int a, int b){
  return (a>b) ? a : b;
}
int main()
{
  Base b (10);
  b++;
  b.print();
  return 0;
}
