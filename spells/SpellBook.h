#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <iostream>
#include <map>
#include "Spell.h"

class SpellBook {
    protected:
        std::map<SpellEnum, Spell*>* spellBook;
    public:
        SpellBook();
        virtual ~SpellBook();

        const std::map<SpellEnum, Spell*>* getSpellBook() const;
};

#endif // SPELLBOOK_H
