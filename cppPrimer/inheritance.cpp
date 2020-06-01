#include <iostream>
#include <string>

class Quote {
  public:
    Quote () = default;
    Quote (const std::string & book, double sales_price) : bookNo(book), price(sales_price)
  { std::cout <<"quote constructor" <<std::endl;}
    std::string isbn() const {return bookNo;}
    virtual double net_price(std::size_t n) const
    { return n*price;}
    virtual ~Quote() = default; //dynamic binding for destructor

  private:
    std::string bookNo;
  protected:
    double price = 0.0;
};

class Disc_quote : public Quote 
{
  public:
    Disc_quote() = default;
    Disc_quote (const std::string & book, double price, std::size_t qty, double disc): Quote (book, price), quantity (qty), discount (disc){}
    double net_price (std::size_t) const = 0;
  protected:
    std::size_t quantity = 0; //purhcase for the discount to apply
    double discount = 0.0; //fractional discount to apply
};

class Bulk_quote : public Disc_quote {
  public:
    Bulk_quote ()= default;
    Bulk_quote (const std::string & book, double p, std::size_t qty, double disc): Disc_quote(book, p,qty, disc) 
    {
      std::cout <<"bulk_quote constructor " <<std::endl;
    }
    double net_price (std::size_t) const override;
  private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price (std::size_t cnt) const
{
  if (cnt >= min_qty)
    return cnt * (1- discount ) * price;
  else
    return cnt *price;
}


double print_total (const Quote &item, size_t n)
{
  double ret = item.net_price(n);//calls Quote::net_price or Bulk_quote::net_price, depending
  std::cout <<"ISBN: " <<item.isbn() <<std::endl; //calls Quote::isbn()
  return ret;
}


int main()
{
  Quote basic;
  Bulk_quote bq;
  print_total (basic, 20);
  Disc_quote discounted;

  return 0;
}
