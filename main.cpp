#include <iostream>
#include "states/limitedfield/LimitedField.h"
#include "states/damage/Damage.h"


class Test {
    protected:
        LimitedField<double>* lfield;
    public:
        Test(int value) : lfield(new LimitedField<double>(value)) {}
        ~Test() {
            delete lfield;
        }

        void show() {
            std::cout << *lfield << std::endl;
        }
};

int main() {
    Test* test = new Test(100.5);
    LimitedField<double>* f1 = new LimitedField<double>(100);
    Damage<double>* d1 = new Damage<double>(30);
    std::cout << "f1 - " << *f1 << std::endl;
    std::cout << "d1 - " << *d1 << std::endl;
    std::cout << "------------------------------" << std::endl;

    for ( int i = 20; i > 0; i-- ) {
        std::cout << d1->getDamage() << ' ';
    }
    std::cout << d1->getDamage() << std::endl;

    int a = 10;
    double b = 11.7;
    float c = 5.33333;

    // std::cout << "------------------------------" << std::endl;
    // *f1 -= a;
    // std::cout << *f1 << std::endl;

    // std::cout << "------------------------------" << std::endl;
    // *f1 -= b;
    // std::cout << *f1 << std::endl;
    
    // std::cout << "------------------------------" << std::endl;
    // *f1 += c;
    // std::cout << *f1 << std::endl;

    // std::cout << "------------------------------" << std::endl;
    // std::cout << "   a = " << a << ";\n" << "   b = " << b << ";\n" << "   c = " << c << ';' << std::endl;
    // a = b;
    // std::cout << "     a = " << a << ';' << std::endl;
    // a = c;
    // std::cout << "     a = " << a << ';' << std::endl;
    // a = 10;
    // std::cout << "     -----" << std::endl;
    // b = a;
    // std::cout << "     b = " << b << ';' << std::endl;
    // b = c;
    // std::cout << "     b = " << b << ';' << std::endl;
    // b = 11.7;
    // std::cout << "     -----" << std::endl;
    // c = b;
    // std::cout << "     c = " << c << ';' << std::endl;
    // c = a;
    // std::cout << "     c = " << c << ';' << std::endl;
    // c = 5.33333;

    std::cout << "------------------------------" << std::endl;


    delete f1;
    delete test;
    delete d1;
    return 0;
}
