#ifndef LIGHTNINGBOLT_H
#define LIGHTNINGBOLT_H

#include "../Spell.h"

class LightningBolt : public Spell {
    protected:
    public:
        LightningBolt(SpellEnum sEnum=LIGHTNINGBOLT, int power=20, int manaCost=20, const std::string& spellName="LightningBolt");
        virtual ~LightningBolt();
};

#endif // LIGHTNINGBOLT_H
