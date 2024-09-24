#include <iostream>
using namespace std;

const double convertion_factor = 1.609;

inline double to_km(int dist_miles)
{
    return dist_miles * convertion_factor;
}

int main()
{
    int miles;
    double kilometers;

    cout << "Convert miles to kilometers" << endl;

    do {
        cout << "Enter a distance in miles: ";
        cin >> miles;
        kilometers = to_km(miles);
        cout << "it's approximately: " << static_cast<int>(kilometers) << " km" << endl;
    } while (miles > 0);

}