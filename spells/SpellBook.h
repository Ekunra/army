#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <iostream>
#include <map>
#include "Spell.h"
#include "spellPrototypes/FireBall.h"
#include "spellPrototypes/Implosion.h"
#include "spellPrototypes/LightningBolt.h"
#include "spellPrototypes/Heal.h"
#include "spellPrototypes/Bless.h"

class SpellBook {
    protected:
        std::map<SpellEnum, Spell*>* spellBook;
    public:
        SpellBook();
        virtual ~SpellBook();

        const std::map<SpellEnum, Spell*>* getSpellBook() const;
};

#endif // SPELLBOOK_H
