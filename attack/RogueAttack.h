#ifndef ROGUEATTACK_H
#define ROGUEATTACK_H

#include "BaseAttack.h"

template <class Type>
class RogueAttack : public BaseAttack<Type> {
    public:
        RogueAttack();
        virtual ~RogueAttack();

        virtual void attack(Unit<Type>* attacker, Unit<Type>* enemy);
};

#endif // ROGUEATTACK_H
