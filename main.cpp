#include <iostream>
#include "limitedfield/LimitedField.h"


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
    LimitedField<double>* f2 = new LimitedField<double>(50);
    LimitedField<double>* f3 = new LimitedField<double>(110);


    delete f1;
    delete f2;
    delete f3;
    delete test;
    return 0;
}
