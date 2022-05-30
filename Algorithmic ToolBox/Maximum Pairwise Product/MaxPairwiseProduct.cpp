#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProductOn2(const std::vector<int> &numbers)
{
    long long maxProduct = 0;
    int n = numbers.size();
    // O(n^2) solution  when the array inpurts are 10^5 this will make 10^10 operations which is more than a bilion which can be executed in 1 second
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((long long)numbers[i] * numbers[j] > maxProduct)
            {
                maxProduct = (long long)numbers[i] * numbers[j];
            }
        }
    }
    return maxProduct;
}
long long MaxPairwiseProductOn(const std::vector<int> &numbers)
{
    // O(n) solution
    long long maxProduct = 0;
    int n = numbers.size();
    int maxIndex = -1;
    int max2Index = -1;
    for (int i = 0; i < n; i++)
    {
        if (maxIndex == -1 || numbers[i] > numbers[maxIndex])
            maxIndex = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != maxIndex && ((max2Index == -1) || (numbers[i] > numbers[max2Index])))
            max2Index = i;
    }
    //std::cout << "Max Index: " << maxIndex << "\n";

    //std::cout << "Max 2 Index: " << max2Index << "\n";
    maxProduct = (long long)numbers[maxIndex] * numbers[max2Index];

    return maxProduct;
}

void stressTest()
{
    while (true)
    {
        int n = rand() % 1000 + 2;
        std::cout << n << "\n";
        std::vector<int> a;
        for (int i = 0; i < n; i++)
        {
            a.push_back(rand() % 100000);
        }

        for (int i = 0; i < n; i++)
        {
            std::cout << a[i] << " ";
        }
        std::cout << "\n";
        long long result1 = MaxPairwiseProductOn2(a);
        long long result2 = MaxPairwiseProductOn(a);
        if (result1 != result2)
        {
            std::cout << "Wrong answer: " << result1 << " " << result2 << "\n";
            break;
        }
        else
            std::cout << "OK\n";
    }
}

int main()
{
    //stressTest();
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductOn(numbers) << "\n";
    return 0;
}
