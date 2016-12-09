#ifndef SPELLCASTERSTATES_H
#define SPELLCASTERSTATES_H

#include <iostream>
#include "../Exception.h"

class SpellCasterStates : public States {
    protected:
        int mana;
        int manaLimit;

    public:
        SpellCasterStates();
        ~SpellCasterStates();

        const int getMana() const;
        const int getManaLimit() const;

        void spendMana();
};

#endif // SPELLCASTERSTATES_H
