#include <ostream>
using namespace :: std;

class point{
public:
    point(double x=0.0, double y=0.0):x(x),y(y){} //constructor
    double getx(){return x;}
    void setx(double v){x = v;}
    double gety(){return y;}
    void sety(double v){y = v;}
private:
    double x,y;
};