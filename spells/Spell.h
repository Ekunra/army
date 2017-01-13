#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../Properties.h"
#include "SpellEnum.h"

template <class Type>
class Spell {
    protected:
        SpellEnum* sEnum;
        Type* power;
        Type* manaCost;
        std::string* spellName;
    public:
        Spell(SpellEnum sEnum, Type power, Type manaCost, const std::string& spellName);
        virtual ~Spell();

        const SpellEnum& getSEnum() const;
        const Type& getPower() const;
        const Type& getManaCost() const;
        const std::string& getSpellName() const;
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Spell<Type>* spell);

#endif // SPELL_H
