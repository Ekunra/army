#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <iostream>
#include <map>
#include "Spell.h"
// #include "spellPrototypes/FireBall.h"
// #include "spellPrototypes/Implosion.h"
// #include "spellPrototypes/LightningBolt.h"
// #include "spellPrototypes/Heal.h"
// #include "spellPrototypes/Bless.h"
// #include "spellPrototypes/ManaPortion.h"

class SpellBook {
    protected:
        std::map<SpellEnum, Spell*>* spellBook;
    public:
        SpellBook();
        virtual ~SpellBook();

        bool haveSpell(SpellEnum sEnum);
        void insertSpell(SpellEnum sEnum, Spell* spell);

        const std::map<SpellEnum, Spell*>* getSpellBook() const;
        const Spell* getSpell(SpellEnum sEnum) const;
};

#endif // SPELLBOOK_H
