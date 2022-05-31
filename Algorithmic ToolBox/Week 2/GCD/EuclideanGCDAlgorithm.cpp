#include <iostream>
#include <chrono> //for time calculation
using namespace std;
using namespace std::chrono;

int euclideanGCD(int a, int b)
{
    if (b == 0)
        return a;
    else
    {
        int r = a % b;
        return euclideanGCD(b, r);
    }
}
int main()
{
    auto start = high_resolution_clock::now();
    int gcd = euclideanGCD(357, 234);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
    cout << "GCD: " << gcd << "\n";
    return 0;
}