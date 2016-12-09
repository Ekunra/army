#include "FireBall.h"

FireBall::FireBall(SpellEnum sEnum, int power, int manaCost, const std::string& spellName)
    : Spell(sEnum, power, manaCost, spellName) {
        std::cout << " * +++ " << spellName << " created."<< std::endl;
    }
FireBall::~FireBall() {
    std::cout << " * --- FireBall destructed" << std::endl;
}
