#include <iostream>
#include <string>

class Account 
{
  public:
    void calculate() {amount += amount * interestRate;}
    static double rate() {return interestRate;}
    static void rate(double);

  private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate(){return 10.1;}
    static constexpr int period = 30;
};

void Account::rate(double newRate)
{
  interestRate = newRate;
}

double Account::interestRate = initRate();

int main()
{
  double r;
  Account ac1;
  Account *ac2 = new Account();
  r= ac1.rate();
  r = ac2-> rate();
}
