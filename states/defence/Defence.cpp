#include "Defence.h"

Defence::Defence(double dCoef, double mdCoef)
    : dCoef(new double(dCoef/100)), mdCoef(new double(mdCoef/100)) {

        if ( DEBUG ) {
            std::cout << FO_B_GREEN << "|  + " << FO_RESET;
            std::cout << FO_D_GREY << "Defence Instance created." << FO_RESET << std::endl;
            
        }
    }
Defence::~Defence() {
    delete dCoef;
    delete mdCoef;

    if ( DEBUG ) {
        std::cout << FO_B_RED << "        - " << FO_RESET;
        std::cout << "Defence instance deleted" << std::endl;
    }
}

const double& Defence::getDmgDefence() const {
    return *this->dCoef;
}
const double& Defence::getMDmgDefence() const {
    return *this->mdCoef;
}
