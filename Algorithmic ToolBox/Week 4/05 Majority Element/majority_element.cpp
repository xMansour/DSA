#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

int get_majority_element(vector<int> &a, int low, int high)
{
  if (low == high)
  {
    return a[low];
  }

  if (low + 1 == high)
  {
    if (a[low] != a[high])
      return -1;
    else
      return a[low];
  }
  int mid = floor((high + low) / 2);
  int maj1 = get_majority_element(a, low, mid);
  int maj2 = get_majority_element(a, mid + 1, high);

  int maj1Count = 0;
  int maj2Count = 0;
  for (int i = low; i <= high; i++)
  {
    if (maj1 == a[i])
      maj1Count++;
    else if (maj2 == a[i])
      maj2Count++;
  }

  int n = high - low + 1;

  if (maj1Count > maj2Count && maj1Count > n / 2)
    return maj1;
  if (maj1Count < maj2Count && maj2Count > n / 2)
    return maj2;

  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
}
