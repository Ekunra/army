#include "WerewolfInfectAbility.h"

template <class Type>
WerewolfInfectAbility<Type>::WerewolfInfectAbility(Unit<Type>* owner, const std::string& name)
    : BaseAbility<Type>(owner, name) {

    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|      + " << FO_RESET;
        std::cout << FO_B << "WerewolfInfectAbility" << FO_RESET << " created." << std::endl;
    }
}
template <class Type>
WerewolfInfectAbility<Type>::~WerewolfInfectAbility() {
    if ( DEBUG ){
        std::cout << FO_B_RED << "        - " << FO_RESET;
        std::cout << "WerewolfInfectAbility destructed." << std::endl;
    }
}

template <class Type>
void WerewolfInfectAbility<Type>::action(Unit<Type>* enemy) {
    if ( !enemy->isAlive() ) {
        return;
    }

    if ( enemy->getUEnum() != UnitEnum::WEREWOLF && enemy->getUEnum() != UnitEnum::WOLF && enemy->getUEnum() != UnitEnum::VAMPIRE ) {
        States<Type>* previousEnemyStates = enemy->getStatesAddress();
        States<Type>* previousEnemyAltStates = enemy->getAltStatesAddress();

        WerewolfStates<Type>* newEnemyWerewolfStates = new WerewolfStates<Type>( new LimitedField<Type>(*enemy->getHealth()),
                                                                         new Damage<Type>(enemy->getMaxDmg()) );

        LimitedField<Type>* newEnemyWolfHealth = new LimitedField<Type>(*enemy->getHealth());
        newEnemyWolfHealth->mutate(*enemy->getHealth(), 2);

        WolfStates<Type>* newEnemyWolfStates = new WolfStates<Type> ( newEnemyWolfHealth,
                                                                      new Damage<Type>(enemy->getMaxDmg()*2) );

        enemy->setStates(newEnemyWerewolfStates);
        enemy->setAltStates(newEnemyWolfStates);

        delete previousEnemyStates;
        delete previousEnemyAltStates;

        WerewolfAttack<Type>* newWerewolfAttack = new WerewolfAttack<Type>();
        enemy->setAttack(newWerewolfAttack);

        WerewolfCounterAttack<Type>* newWerewolfCounterAttack = new WerewolfCounterAttack<Type>();
        enemy->setCounterAttack(newWerewolfCounterAttack);

        WerewolfInfectAbility<Type>* newWerewolfInfectAbility = new WerewolfInfectAbility<Type>(enemy);
        enemy->setPrimaryAbility(newWerewolfInfectAbility);

        WerewolfTransformAbility<Type>* newWerewolfTransformAbility = new WerewolfTransformAbility<Type>(enemy);
        enemy->setSecondaryAbility(newWerewolfTransformAbility);
    }
}


template class WerewolfInfectAbility<int>;
template class WerewolfInfectAbility<double>;
template class WerewolfInfectAbility<float>;
