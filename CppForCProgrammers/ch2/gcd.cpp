// Greatest Common Divisor (GCD) program
#include <iostream>
using namespace std;

int gcd(int m, int n)
{
    int r;

    while (n!=0) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main()
{
    int x, y, g;
    cout << "\nPROGRAM GCD C++";
    do {
        cout << "\nEnter twp integers: ";
        cin >> x >> y;
        if (x*y == 0)
            throw new exception();
        cout  
            << "\n GCD(" << x << ", " << y << ") = "
            << (g = gcd(x, y)) << endl;
    } while (x != y);
}