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

template <class Type>
class SpellBook {
    protected:
        std::map<SpellEnum, Spell<Type>*>* spellBook;
    public:
        SpellBook();
        virtual ~SpellBook();

        bool haveSpell(SpellEnum sEnum);
        void insertSpell(SpellEnum sEnum, Spell<Type>* spell);

        const std::map<SpellEnum, Spell<Type>*>* getSpellBook() const;
        const Spell<Type>& getSpell(SpellEnum sEnum) const;
};

#endif // SPELLBOOK_H
