// Use of a default value

#include <iostream>
using namespace :: std;

inline void add3(int& s, int a, int b, int c=0)
{
    // Note that we pass s "by reference" without pointers
    s = a+b+c;
}

inline double average(int s){ return s/ 3.0; }

int main()
{
    int score1, score2, score3, sum;

    cout << "\nEnter 3 scores: ";
    cin >> score1 >> score2 >> score3;
    add3(sum, score1, score2, score3);
    cout << "\nSum = " << sum;
    cout << "\nAverage = " << average(sum) << endl;
    add3(sum, 2 * score1, score2); //use of default valur 0;
    cout << "\nWeighted Sum = " << sum << ".";
    cout << "\nWeighted Average = " << average(sum) << ".\n";
}

