#include <iostream>
#include <chrono> //for time calculation
using namespace std;
using namespace std::chrono;

// polynomial function O(n)
long long arrayFibonacci(int n)
{
    long long arr[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
        arr[i] = arr[i - 1] + arr[i - 2];

    return arr[n];
}
int main()
{
    auto start = high_resolution_clock::now();
    int num = 90;
    long long fibonacci = arrayFibonacci(num);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;

    cout << "Fibonacci of: " << num << " is: " << fibonacci << "\n";
    return 0;
}