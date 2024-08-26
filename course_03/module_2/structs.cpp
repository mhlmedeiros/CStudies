#include <iostream>

using namespace :: std;

struct point{
    double x;
    double y;
    void print(){cout << "(" << x << "," << y << ")";} // this "member function" is implicitly inlined
};

ostream& operator<<(ostream& out, const point& p){
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

int main(){
    point p = {5, 4};
    cout << "using overloaded operator: " << endl;
    cout << "\tp = " << p << endl;
    cout << "using function member: " << endl;
    cout << "\tp = ";
    p.print();
    cout << endl; 

    return 0;
}