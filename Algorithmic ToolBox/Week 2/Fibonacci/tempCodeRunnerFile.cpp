#include <iostream>
#include <chrono> //for time calculation
using namespace std;
using namespace std::chrono;

// exponential function 2^n
int naiveFibonacci(int n)
{
    if (n < 2)
        return n;
    else
        return naiveFibonacci(n - 1) + naiveFibonacci(n - 2);
}
int main()
{
    auto start = high_resolution_clock::now();
    int num = 40;
    int fibonacci = naiveFibonacci(num);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;

    cout << "Fibonacci of: " << num << " is: " << fibonacci << "\n";
    return 0;
}