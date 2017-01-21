#ifndef DEFENCE_H
#define DEFENCE_H

#include <iostream>
#include "../../debug.h"

class Defence {
    protected:
        double* dCoef;
        double* mdCoef;

    public:
        Defence(double dCoef, double mdCoef);
        ~Defence();

        const double& getDmgDefence() const;
        const double& getMDmgDefence() const;
};

#endif // DEFENCE_H
