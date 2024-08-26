// Convert this program to C++
// change to C++ io
// change to one line comments
// change defines of constants to const
// change array to vetor<>
// inline any short function


#include<iostream>
#include<vector>

using namespace :: std;

const int N=40;

inline void sum(int& s, vector<int> d)
{
    for (int x : d){
        s = s + x;
    }
}

int main()
{
    int accum = 0;
    vector<int> data;

    for (int i=0; i<N; ++i)
        data.push_back(i);

    sum(accum, data);
    cout << accum << endl;

}