#include "LightningBolt.h"

LightningBolt::LightningBolt(SpellEnum sEnum, int power, int manaCost, const std::string& spellName)
    : Spell(sEnum, power, manaCost, spellName) {
        std::cout << " * +++ " << spellName << " created."<< std::endl;
    }
LightningBolt::~LightningBolt() {
    std::cout << " * --- LightningBolt destructed" << std::endl;
}
