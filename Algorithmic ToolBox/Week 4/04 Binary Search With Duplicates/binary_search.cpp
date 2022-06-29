#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;

int binary_search(const vector<int> &a, int x)
{
  int low = 0, high = (int)a.size() - 1;
  while (high >= low)
  {
    int mid = floor((high + low) / 2);
    if (a[mid] == x)
    {
      for (int i = low; i < mid; i++)
      {
        if (a[i] == a[mid])
        {
          return i;
        }
      }
      return mid;
    }
    else if (x < a[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

int linear_search(const vector<int> &a, int x)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x)
      return i;
  }
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i)
  {
    // replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
