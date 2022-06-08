#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;
int functionCalls = 0;
int computeMinRefills(int location, vector<int> &stops, int tankRefillLength, int distinationBetweenCities)
{
    functionCalls++;
    if (location + tankRefillLength >= distinationBetweenCities)
        return 0;
    if (stops.empty() || (stops[0] - location) > tankRefillLength)
        return -1 * functionCalls;
    int lastStop = location;
    while (!stops.empty() && (stops[0] - location) <= tankRefillLength)
    {
        lastStop = stops[0];
        stops.erase(stops.begin());
    }
    return 1 + computeMinRefills(lastStop, stops, tankRefillLength, distinationBetweenCities);
}

int main()
{
    int distinationBetweenCities = 0;
    cin >> distinationBetweenCities;
    int tankRefillLength = 0;
    cin >> tankRefillLength;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << computeMinRefills(0, stops, tankRefillLength, distinationBetweenCities) << "\n";

    return 0;
}
