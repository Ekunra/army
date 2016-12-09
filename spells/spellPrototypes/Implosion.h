#ifndef IMPLOSION_H
#define IMPLOSION_H

#include "../Spell.h"

class Implosion : public Spell {
    protected:
    public:
        Implosion(SpellEnum sEnum=IMPLOSION, int power=20, int manaCost=20, const std::string& spellName="Implosion");
        virtual ~Implosion();
};

#endif // IMPLOSION_H
