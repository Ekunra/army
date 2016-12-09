#include "Heal.h"

Heal::Heal(SpellEnum sEnum, int power, int manaCost, const std::string& spellName)
    : Spell(sEnum, power, manaCost, spellName) {
        std::cout << " * +++ " << spellName << " created."<< std::endl;
    }
Heal::~Heal() {
    std::cout << " * --- Heal destructed" << std::endl;
}
