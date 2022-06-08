#include <iostream>
#include <cmath>

int getChange(int money)
{
  return floor(money / 10) + floor((money % 10) / 5) + floor(money % 5);
}

int main()
{
  int money;
  std::cin >> money;
  std::cout << getChange(money) << '\n';
}
