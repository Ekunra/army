#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "../Unit.h"
#include "../../Properties.h"
#include "../../states/SoldierStates.h"

template <class Type>
class Soldier : public Unit<Type> {
    public:
        Soldier(const std::string& name);
        virtual ~Soldier();

        virtual void attack(Unit<Type>* enemy);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Soldier<Type>& soldier);

#endif // SOLDIER_H
