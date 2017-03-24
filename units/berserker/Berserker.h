#ifndef BERSERKER_H
#define BERSERKER_H

#include <iostream>
#include "../Unit.h"
#include "../../Properties.h"
#include "../../states/BerserkerStates.h"

template <class Type>
class Berserker : public Unit<Type> {
    public:
        Berserker(const std::string& name);
        virtual ~Berserker();

        virtual void attack(Unit<Type>* enemy);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Berserker<Type>& berserker);

#endif // BERSERKER_H
