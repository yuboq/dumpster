#include <iostream>
#include <vector>

template <typename T =int , typename U > void myfunc(const T & a, const U& b ){
  std::cout << a << " "<< b <<std::endl;
};
template <typename T = int> void myfunc2 (const T & a ){
  std::cout << a << " " << std::endl;
}

typedef char T;
template <typename T = int> class Base {
  public:
    Base (T a=10) : myint (a) {}
    void print() {std::cout << myint << std::endl;}
  private:
    T myint;
};

template <typename T> void printContainer (const T& a){
  for (typename T::size_type i = 0; i !=a.size(); ++i){
    std::cout << a[i] <<" ";
  }

  std::cout << std::endl;
}

template <typename T> void printContainer2 (const T& a){
  for (typename T::const_iterator it = a.begin(); it != a.end(); ++ it){
    std::cout << *it <<std::endl;
  }
  
}

int main(){
  Base<> b;//default T is int
  Base <char>b2 ('a');//T is char
  b.print();
  b2.print();
  std::vector<int> myVec = {1,2,3,455,6};
  printContainer (myVec);
  printContainer2 (myVec);
  return 0;
}
