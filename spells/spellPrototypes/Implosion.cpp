#include "Implosion.h"

Implosion::Implosion(SpellEnum sEnum, int power, int manaCost, const std::string& spellName)
    : Spell(sEnum, power, manaCost, spellName) {
        std::cout << " * +++ " << spellName << " created."<< std::endl;
    }
Implosion::~Implosion() {
    std::cout << " * --- Implosion destructed" << std::endl;
}
