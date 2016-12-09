#include "BaseAttack.h"

BaseAttack::BaseAttack() {}
BaseAttack::~BaseAttack() {
    std::cout << " * BaseAttack destructed." << std::endl;
}

void BaseAttack::attack(Unit* attacker, Unit* enemy) {
    std::cout << "      --- " << attacker->getName() 
    << " attacking " << enemy->getName() 
    << ", causing " << attacker->getDamage() 
    << " dmg." <<std::endl;

    enemy->takeDamage(attacker);
    enemy->counterAttack(attacker);
}
