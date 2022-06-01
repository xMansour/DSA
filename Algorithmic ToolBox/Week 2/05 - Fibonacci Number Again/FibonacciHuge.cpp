#include <iostream>
using namespace std;

long long getFibonacciHugeNaive(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
long long getPisanoPeriod(long long m)
{
    long long prev = 0;
    long long next = 1;
    long long current = prev + next;
    for (int i = 0; i < m * m; i++)
    {
        current = (prev + next) % m;
        prev = next;
        next = current;
        if (prev == 0 && next == 1)
            return i + 1;
    }
    return 0;
}
int fibonacci_fast(int n)
{
    if (n <= 1)
        return n;
    else
    {
        int arr[n + 1];
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i < n + 1; i++)
            arr[i] = arr[i - 1] + arr[i - 2];
        return arr[n];
    }
}
long long getFibonacciHugeFast(long long n, long long m)
{
    if (n <= 1)
        return n;
    else
    {
        int pisanoPeriod = getPisanoPeriod(m);
        cout << pisanoPeriod << "\n";
        n = n % pisanoPeriod;
        return fibonacci_fast(n) % m;
    }
}

int main()
{
    long long n, m;
    cin >> n >> m;
    // cout << getFibonacciHugeNaive(n, m) << '\n';
    cout << getFibonacciHugeFast(n, m) << '\n';
}
