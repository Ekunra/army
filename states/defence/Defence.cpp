#include "Defence.h"

Defence::Defence(double dCoef, double mdCoef)
    : dCoef(new double(dCoef)), mdCoef(new double(mdCoef)) {}
Defence::~Defence() {
    delete dCoef;
    delete mdCoef;
}

const double& Defence::getDmgDefence() const {}
const double& Defence::getMDmgDefence() const {}