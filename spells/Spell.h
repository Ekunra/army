#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../debug.h"
#include "../Properties.h"
#include "../macro_color.cpp"
#include "SpellEnum.h"

template <class Type>
class Spell {
    protected:
        SpellEnum* sEnum;
        SpellEnum* sType;
        Type* power;
        Type* manaCost;
        std::string* spellName;

    public:
        Spell(SpellEnum sEnum, SpellEnum sType, Type power, Type manaCost, const std::string& spellName);
        Spell(const Spell& sample);
        virtual ~Spell();

        const SpellEnum& getSEnum() const;
        const SpellEnum& getSType() const;
        const Type& getPower() const;
        const Type& getManaCost() const;
        const std::string& getSpellName() const;

        Spell<Type> action();

        Spell<Type> operator=(const Spell& other);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Spell<Type>& spell);

#endif // SPELL_H
