#ifndef HEAL_H
#define HEAL_H

#include "../Spell.h"

class Heal : public Spell {
    protected:
    public:
        Heal(SpellEnum sEnum=HEAL, int power=20, int manaCost=20, const std::string& spellName="Heal");
        virtual ~Heal();
};

#endif // HEAL_H
