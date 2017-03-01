#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../debug.h"
#include "../Properties.h"
#include "../macro_color.cpp"
// #include "../units/SpellCaster.h" - Ваще ППЦ при включении не компилится!!!!!!!!!!!!!!!!!!!!!!!!
// #include "../units/Unit.h" - Ваще ППЦ при включении не компилится!!!!!!!!!!!!!!!!!!!!!!!!
#include "SpellEnum.h"

template <class Type> class SpellCaster;
template <class Type> class Unit;

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

        void action(SpellCaster<Type>* caster, SpellCaster<Type>* target);
        void action(SpellCaster<Type>* caster, Unit<Type>* target);

        Spell<Type> operator=(const Spell& other);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Spell<Type>& spell);

#endif // SPELL_H
