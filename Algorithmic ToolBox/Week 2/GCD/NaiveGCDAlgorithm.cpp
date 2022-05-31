#include <iostream>
#include <chrono> //for time calculation
using namespace std;
using namespace std::chrono;

int naiveGCD(int a, int b)
{
    int gcd = 0;
    for (int i = 1; i < a + b; i++)
    {
        cout << i << " ";
        if (a % i == 0 && b % i == 0)
            gcd = i;
    }
    cout << "\n";
    return gcd;
}
int main()
{
    auto start = high_resolution_clock::now();
    int gcd = naiveGCD(357, 234);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;

    cout << "GCD: " << gcd << "\n";
    return 0;
}