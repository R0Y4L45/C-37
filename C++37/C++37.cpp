#include <iostream>

using namespace std;



#include "Fraction.h"



int main()
{
    Fraction f(2, 2);
    Fraction f1(25, 30);
    Fraction f3(4, 16);
    cout << f3;
    f3.Simplify();
    cout << (float) f3;
    

}
