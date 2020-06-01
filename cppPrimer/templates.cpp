#include <iostream>
#include <vector>
class Base{
  public:
    template <typename U> U add (const U &,const U &);
    inline int  add2 (int x, int y) {return x+y;}
};

template <typename U> U Base::add (const U &x, const U &y) {return x+y;};
template <typename T>
T add (T a){
  return a+1;
}

template <unsigned size>
void add (int & value){
  value +=size;
}

template <typename T, unsigned size, typename U>
T find (const U& container){
  return container [size];
}

template <typename T, unsigned N, unsigned M>
constexpr unsigned size (T& a) {
  std::cout << "hi";
  return M;
}


//template <typename T, class U > calc (const T&, const U&);
int main()
{
  std::vector <int> a= {1,2,3,4,5};
  std::cout << find< int, 3> (a) <<std::endl;
  std::cout << "size " <<size (a) << std::endl;
  int num = 10;
  add <10> (num);

  std::cout << num <<std::endl;
}
