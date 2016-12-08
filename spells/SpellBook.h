#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <iostream>
#include <map>
#include "Spell.h"

class SpellBook {
    protected:
        std::map<SpellNameEnum, Spell*>* spellBook;
    public:
        SpellBook();
        ~SpellBook();

        const std::map<SpellNameEnum, Spell*>* getSpellBook() const;
};

#endif // SPELLBOOK_H
