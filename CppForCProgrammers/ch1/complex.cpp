#include <iostream>
using namespace std;

class complex {
public: //unversal access to interface
    complex(double x=0, double y=0):real(x), imaginary(y){}
    void re_assign(double r){ real = r;}
    void im_assign(double im){ imaginary = im;}
    void print() const{
        cout << "(" << real << ", " << imaginary << "j)"<< endl;
    }
    friend complex operator+(complex, complex);
private: // restricted access to implementation
    double real;
    double imaginary;
};

complex operator+(complex z1,  complex z2){
    complex total;
    total.re_assign(z1.real + z2.real);
    total.im_assign(z1.imaginary + z2.imaginary);
    return total;
}

int main(){
    complex z, w, t;
    
    z.re_assign(5.0);
    z.im_assign(7.5);
    
    t = z + w;

    z.print();
    w.print();
    t.print();

}