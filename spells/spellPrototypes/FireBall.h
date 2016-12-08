#ifndef FIREBALL_H
#define FIREBALL_H

#include "../Spell.h"

class FireBall : public Spell {
    protected:
    public:
        FireBall(SpellEnum sEnum=FIREBALL, int power=20, int manaCost=20, const std::string& spellName="FireBall");
        virtual ~FireBall();
};

#endif // FIREBALL_H
