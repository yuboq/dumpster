#include <iostream>
#include <string>

class Box
{
  public:
    static int objectCount;

    Box (int l, int w, int h) : length(l), width (w), height(h)
      {std::cout <<"3arg constructor " <<std::endl;
        objectCount++;
      }
    Box () : Box (1,2,3)
      {
        std::cout << "default constructor" <<std::endl;
      }

    double volume(){return (length* width* height);}

    static int getCount (); 

    Box & addLength (const int x = 1) {length +=x; return *this;}

  private:
    int length, width, height;
};

//initialize static member of class box

int Box::objectCount = 0;

int Box::getCount() {return objectCount;}


int main()
{
  Box b1;
  std::cout <<"b1 created " <<std::endl;
  Box b2 (4,5,6);
  std::cout <<"b2 created " <<std::endl;
  std::cout <<b2.getCount() <<std::endl;
  std::cout << b2.addLength (10).volume() <<std::endl;
}




