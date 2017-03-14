#include "VampireInfectAbility.h"

template <class Type>
VampireInfectAbility<Type>::VampireInfectAbility(Unit<Type>* owner, const std::string& name)
    : BaseAbility<Type>(owner, name) {

    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|      + " << FO_RESET;
        std::cout << FO_B << "VampireInfectAbility" << FO_RESET << " created." << std::endl;
    }
}
template <class Type>
VampireInfectAbility<Type>::~VampireInfectAbility() {
    if ( DEBUG ){
        std::cout << FO_B_RED << "        - " << FO_RESET;
        std::cout << "VampireInfectAbility destructed." << std::endl;
    }
}

template <class Type>
void VampireInfectAbility<Type>::action(Unit<Type>* enemy) {
    if ( !enemy->isAlive() ) {
        return;
    }

    if ( enemy->getUEnum() != UnitEnum::WEREWOLF && enemy->getUEnum() != UnitEnum::WOLF && enemy->getUEnum() != UnitEnum::VAMPIRE ) {
        States<Type>* previousEnemyStates = enemy->getStatesAddress();
        States<Type>* previousEnemyAltStates = enemy->getAltStatesAddress();

        VampireStates<Type>* newEnemyVampireStates = new VampireStates<Type>( new LimitedField<Type>(*enemy->getHealth()),
                                                                         new Damage<Type>(enemy->getMaxDmg()) );

        States<Type>* newEnemyAltStates = nullptr;

        enemy->setStates(newEnemyVampireStates);
        enemy->setAltStates(newEnemyAltStates);

        delete previousEnemyStates;
        delete previousEnemyAltStates;

        VampireAttack<Type>* newVampireAttack = new VampireAttack<Type>();
        enemy->setAttack(newVampireAttack);

        VampireCounterAttack<Type>* newVampireCounterAttack = new VampireCounterAttack<Type>();
        enemy->setCounterAttack(newVampireCounterAttack);

        VampireInfectAbility<Type>* newVampireInfectAbility = new VampireInfectAbility<Type>(enemy);
        enemy->setPrimaryAbility(newVampireInfectAbility);

        BaseAbility<Type>* BaseAbility = nullptr;
        enemy->setSecondaryAbility(BaseAbility);
    }
}


template class VampireInfectAbility<int>;
template class VampireInfectAbility<double>;
template class VampireInfectAbility<float>;
