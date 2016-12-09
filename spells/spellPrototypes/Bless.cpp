#include "Bless.h"

Bless::Bless(SpellEnum sEnum, int power, int manaCost, const std::string& spellName)
    : Spell(sEnum, power, manaCost, spellName) {
        std::cout << " * +++ " << spellName << " created."<< std::endl;
    }
Bless::~Bless() {
    std::cout << " * --- Bless destructed" << std::endl;
}
