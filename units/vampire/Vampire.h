#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include "../Unit.h"
#include "../../Properties.h"
#include "../../attack/VampireAttack.h"
#include "../../attack/VampireCounterAttack.h"

template <class Type>
class Vampire : public Unit<Type> {
    public:
        Vampire(const std::string& name);
        virtual ~Vampire();

        virtual void attack(Unit<Type>* enemy);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Vampire<Type>& vampire);

#endif // VAMPIRE_H
