#include <iostream>
using namespace :: std;

const int N = 10;

template <class summable>
summable sum(summable array[], int size)
{
    summable sum;
    for(int i=0; i<size; i++){
        sum += array[i];
    }
    return sum;
}

int main()
{
    double array[N];

    for (int i=0; i<N; i++)
    {
        array[i] = i/10.;
    }

    cout << "\nSummation = " << sum(array, N) << endl;
}
