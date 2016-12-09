#ifndef BLESS_H
#define BLESS_H

#include "../Spell.h"

class Bless : public Spell {
    protected:
    public:
        Bless(SpellEnum sEnum=BLESS, int power=250, int manaCost=50, const std::string& spellName="Bless");
        virtual ~Bless();
};

#endif // BLESS_H
