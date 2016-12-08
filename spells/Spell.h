#ifndef SPELL_H
#define SPELL_H

#include <iostream>

typedef enum {
    FireBall,
    LightningBolt,
    Implosion,
    Heal,
    Bless
} SpellNameEnum;


class Spell {
    protected:
        SpellNameEnum snEnum;
        int power;
        int manaCost;
        std::string* spellName;
    public:
        Spell();
        virtual ~Spell();

        const SpellNameEnum getSNEnum() const;
        const int getPower() const;
        const int getManaCost() const;
        const std::string* getSpellName() const;

};

#endif // SPELL_H
