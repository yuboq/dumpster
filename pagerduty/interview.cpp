#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
/*Create a minimal viable product: Prior to the call, we would like to ask you to spend about 30 - 45 minutes preparing a starter app. The format is up to you - it can be a command-line application, a web app, a desktop app, you name it. For example, a front-end component is not mandatory for those of you that are stronger in back-end development. Feel free to use whatever language and framework you're most comfortable with. Data can be stored in memory; you do not have to persist the data or use external storage. The app must support adding just the name of a dish, deleting a dish, and viewing all dish names we've added. Don't spend too much time on this minimal viable product - ideally 30-45mins - but the app does have to be complete prior to the interview. We will be unable to conduct the interview if the app is incomplete.*/

//start time: 14:11
//end time: 15:10
/*
 * Solution is divided up into several parts:
 *  1. parsing input
 *  2. add menu item
 *  3. remove menu item
 *  4. print menu
 *
 *  Constraints: 45min
 *  Assumuptions: No duplicates, no empty entries, case sensitive
 *  Nice to haves: a way to add additional information to the menu (e.g. price)
 *  Main issue: Parsing input actaully took the longest (30min). Initially used string, then char, then int. Invalid int is 0, so case statement starts at 1
 */
class Menu
{
  public:
    std::unordered_map <std::string, std::vector<std::string> > myMenu;

    void start()
    {
      while (true)
      {

        std::cout <<"select options: 1.add dish |  2. delete dish |  3. view dish | 4.Search |  5. exit" <<std::endl;
        int selection = 0;
        std::cin >> selection;
        switch (selection){
        case 1: addDish();
                break;
        case 2: deleteDish();
                break;
        case 3: viewDish();
                break;
        case 4: searchIngredients();
                break;
        case 5: return;

        default: std::cout <<"invalid input" <<std::endl;
                 std::cin.clear();//clear cin error if invalid input
                 std::cin.ignore(10000, '\n');//ignore next line
        }
      }
    }

    std::vector<std::string > parseStringtoVec (std::string ingredients)
    {
      //TODO
      //parses string of ingredients into a vector, comma spliced

      std::vector<std::string> output;
      std::string substr = "";
      for (char c: ingredients)
      {
        if (c == ',')
        {
          output.push_back (substr);
          substr = "";
        }
        else
        {
          substr += c;
        }
      }
      output.push_back(substr);

      return output;
    }

    std::unordered_map <std::string, int> createPantry (std::string toSearch)
    {
      //TODO
      std::unordered_map <std::string, int> output;
      std::string substr = "";
      for (char c: toSearch)
      {
        if (c ==',')
        {
          output[substr] = 0;
          substr = "";
        }
        else
        {
          substr +=c;
        }
      }
      output[substr] = 0;
      return output;

    }
    void searchIngredients()
    {
      std::string toSearch;
      std::cin >> toSearch;
      std::unordered_map <std::string,int> pantry;
      pantry = createPantry (toSearch);//TODO

      for (auto dish : myMenu)
      {
        bool finishedFlag = true;
        for (auto ingredient:dish.second)//TODO Note: needs to be a vector
        {
          if (pantry.find(ingredient) == pantry.end())
          {
            finishedFlag = false;
            break;
          }
        }
        if (finishedFlag)
        {
          std::cout <<dish.first << " "<<std::endl;
        }
      }
    }



    void addDish()
    {
      std::string dish = "";
      std::string ingredients;
      std::cin >> dish >>ingredients;
      std::vector<std::string > ingredientsVec = parseStringtoVec (ingredients);

      myMenu[dish] = ingredientsVec;
    }
    void deleteDish()
    {
      std::string dish = "";
      std::cin >>dish;
      if (myMenu.find(dish) != myMenu.end())
      {
        myMenu.erase (dish);
        std::cout <<"dish '" << dish <<"' deleted" <<std::endl;
      }
      else
      {
        std::cout <<"cannot find dish '" <<dish <<"'"<<std::endl;
      }
    }
    void viewDish()
    {
      for (auto dish: myMenu)
      {
        std::cout <<dish.first << " ";
        for (auto ingredient : dish.second)
          std::cout << ingredient << " " ;
        std::cout << std::endl;

      }
    }
};

int main()
{
  Menu m;
  m.start();
  return 0;
}
