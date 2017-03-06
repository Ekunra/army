#ifndef VAMPIRESTATES_H
#define VAMPIRESTATES_H

#include <iostream>
#include "States.h"
// #include <memory>
// #include "damage/Damage.h"
// #include "defence/Defence.h"
// #include "limitedfield/LimitedField.h"
// #include "../Exceptions.h"
// #include "../Properties.h"
// #include "../spells/spellTypes/DDTSpell.h"
// #include "../spells/spellTypes/HTSpell.h"

template <class Type>
class VampireStates : public States<Type> {
    public:
        VampireStates();
        virtual ~VampireStates();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const VampireStates<Type>& vampireStates);

#endif // VAMPIRESTATES_H
