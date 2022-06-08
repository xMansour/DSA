#include <iostream>
#include <vector>
using namespace std;

double getOptimalValue(int capacity, vector<int> weights, vector<int> values)
{
  if (capacity == 0 || weights.empty())
    return 0;

  int maxIndex = 0;
  for (int i = 1; i < values.size(); i++)
    if (((double)values[maxIndex] / weights[maxIndex]) < ((double)values[i] / weights[i]))
      maxIndex = i;

  double amount = min(weights[maxIndex], capacity);
  double value = values[maxIndex] * (amount / weights[maxIndex]);
  capacity -= amount;
  weights.erase(weights.begin() + maxIndex);
  values.erase(values.begin() + maxIndex);
  return value + getOptimalValue(capacity, weights, values);
}

int main()
{
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> values[i] >> weights[i];
  }

  double value = getOptimalValue(capacity, weights, values);

  cout.precision(10);
  cout << value << endl;
  return 0;
}
