#include <iostream>
using namespace std;
int stepsEuc = 0;
int stepsNaive = 0;

int naiveGCDAlgorithm(int a, int b)
{
  stepsNaive = (a < b) ? a : b;
  int currentGCD = 1;
  for (int d = 2; d <= a && d <= b; d++)
    if (a % d == 0 && b % d == 0)
      if (d > currentGCD)
        currentGCD = d;
  return currentGCD;
}

int euclideanGCD(int a, int b)
{
  stepsEuc++;
  if (b == 0)
    return a;
  else
  {
    int r = a % b;
    return (euclideanGCD(b, r));
  }
}

int main()
{
  int a, b;
  cin >> a >> b;
  //cout << naiveGCDAlgorithm(a, b) << "\n";
  //cout << "Number of steps to find the GCD for naive algorithm: " << stepsNaive << "\n";
  cout << euclideanGCD(a, b) << "\n";
  //cout << "Number of steps to find the GCD for eculidean algorithm: " << stepsEuc << "\n";
  return 0;
}
