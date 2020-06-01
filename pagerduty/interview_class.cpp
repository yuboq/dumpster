#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

/* Create a menu interface that supports:
 *  Adding a dish
 *  Deleting a dish
 *  Viewing all dishes
 *  */

class Dish
{
  public:
    Dish (std::string s): dishName(s) {std::cout<<"1arg constructor" <<std::endl;}
    Dish () : Dish("empty"){std::cout <<"delegate constructor" <<std::endl;}

    virtual ~Dish() =default;

    virtual double getPrice () {return 0.0;}
    friend class Interface;
  private:
    std::string dishName;
};
class Dessert;

class Interface : public Dish 
{
  public:
    bool addDish(const std::shared_ptr <Dish> &);
    bool deleteDish (const std::string s);
    void viewDish ();
  private:
    std::unordered_map <std::string ,std::shared_ptr <Dish>> menu;
};

class Dessert: public Dish
{
  public:
    Dessert (std::string s, double p) : Dish (s), price (p) {}
    friend class Interface;
    double getPrice () override {return price;}


  private:
    double price;
};

bool Interface::addDish (const std::shared_ptr <Dish>& d)
{
  menu [d->dishName] = d;
  return true;
}

bool Interface::deleteDish(const std::string s)
{

  if (menu.find(s) != menu.end())
  {
    menu.erase (s);
    return true;
  }
  return false;
}
void Interface::viewDish()
{
  for (auto d: menu)
  {
    std::cout <<d.second->dishName << ": $" << d.second -> getPrice()<<std::endl;
  }
}

int main()
{
  Interface menu;

  menu.addDish (std::make_shared <Dessert> ("pie", 3.50));
  menu.addDish (std::make_shared <Dessert> ("cake", 4.50));

  menu.viewDish();
  return 0;
}

