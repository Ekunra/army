#include "RogueAttack.h"

RogueAttack::RogueAttack() {}
RogueAttack::~RogueAttack() {
    std::cout << " * RogueAttack destructed." << std::endl;
}

void RogueAttack::attack(Unit* attacker, Unit* enemy) {
    std::cout << "      --- " << attacker->getName() 
    << " attacking " << enemy->getName() 
    << ", causing " << attacker->getDamage() 
    << " dmg." <<std::endl;

    enemy->takeDamage(attacker);
}
