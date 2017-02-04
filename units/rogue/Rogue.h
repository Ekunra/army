#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "../Unit.h"
#include "../../attack/RogueAttack.h"
#include "../../Properties.h"

template <class Type>
class Rogue : public Unit<Type> {
    public:
        Rogue(const std::string& name);
        virtual ~Rogue();

        virtual void attack(Unit<Type>* enemy);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Rogue<Type>& rogue);

#endif // ROGUE_H
