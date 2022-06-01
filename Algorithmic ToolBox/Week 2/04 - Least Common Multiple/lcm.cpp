#include <iostream>
using namespace std;
int stepsEuc = 0;
long long stepsNaive = 0;
long long naiveLCMAlgorithm(int a, int b)
{
  stepsNaive = a * b;
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long)a * b;
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

long long euclideanLCMAlgorithm(int a, int b)
{
  // since a*b = gcd(a,b)*lcm(a,b)
  return (long long)a * b / euclideanGCD(a, b);
}
int main()
{
  int a, b;
  cin >> a >> b;
  // cout << naiveLCMAlgorithm(a, b) << "\n";
  // cout << "Number of steps to find the GCD for naive algorithm: " << stepsNaive << "\n";
  cout << euclideanLCMAlgorithm(a, b) << "\n";
  // cout << "Number of steps to find the GCD for eculidean algorithm: " << stepsEuc << "\n";
  return 0;
}
