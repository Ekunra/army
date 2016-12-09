#include "BaseCounterAttack.h"

BaseCounterAttack::BaseCounterAttack() {}
BaseCounterAttack::~BaseCounterAttack() {
    std::cout << " * BaseCounterAttack destructed." << std::endl;
}

void BaseCounterAttack::counterAttack(Unit* counterAttacker, Unit* enemy) {
    std::cout << "      --- " << counterAttacker->getName() 
    << " counter-attacking " << enemy->getName() 
    << ", causing " << counterAttacker->getDamage()/2 
    << " dmg." <<std::endl;

    enemy->takeCADamage(counterAttacker);
}
