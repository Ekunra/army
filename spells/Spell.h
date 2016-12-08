#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "SpellEnum.cpp"

class Spell {
    protected:
        SpellEnum sEnum;
        int* power;
        int* manaCost;
        std::string* spellName;
    public:
        Spell(SpellEnum sEnum, int power, int manaCost, const std::string& spellName);
        virtual ~Spell();

        const SpellEnum getSEnum() const;
        const int getPower() const;
        const int getManaCost() const;
        const std::string& getSpellName() const;
};

std::ostream& operator<<(std::ostream& out, const Spell* spell);

#endif // SPELL_H
