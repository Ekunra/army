#ifndef DEFENCE_H
#define DEFENCE_H

#include <iostream>

class Defence {
    protected:
        double* dmgDefence;
        double* mDmgDefence;

    public:
        Defence();
        ~Defence();

        const double& getDmgDefence() const;
        const double& getMDmgDefence() const;
};

#endif // DEFENCE_H