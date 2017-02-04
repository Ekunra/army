#ifndef LIGHTNINGBOLT_H
#define LIGHTNINGBOLT_H

#include "../Spell.h"

template <class Type>
class LightningBolt : public Spell<Type> {
    protected:
    public:
        LightningBolt ( SpellEnum sEnum=LIGHTNINGBOLT,
                        Type power=(Type)SPower::LIGHTNINGBOLT,
                        Type manaCost=(Type)SCost::LIGHTNINGBOLT,
                        const std::string& spellName="LightningBolt");
        virtual ~LightningBolt();
};

#endif // LIGHTNINGBOLT_H
