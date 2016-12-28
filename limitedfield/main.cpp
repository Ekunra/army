#include <iostream>
#include "LimitedField.h"


class Test {
    protected:
        LimitedField<double>* lfield;
    public:
        Test(double value) : lfield(new LimitedField<double>(value)) {}
        ~Test() {
            delete lfield;
        }

        void show() {
            std::cout << *lfield << std::endl;
        }
};

int main() {
    Test* test = new Test(100.5);
    LimitedField<int>* f1 = new LimitedField<int>(100);
    
    std::cout << *f1 << std::endl;
    test->show();

    delete f1;
    delete test;
    return 0;
}
