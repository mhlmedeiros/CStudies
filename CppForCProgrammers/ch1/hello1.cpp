//Hello world in C++

#include <iostream>
#include <string>
using namespace std;

inline void pr_message(string s = "Hello world!")
{cout << s << endl;}

int main()
{
    pr_message();
    pr_message("Joaquim doesn't wanna sleep!");
    pr_message("Why, god, why?");

}