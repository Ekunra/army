#include "BaseAbility.h"

template <class Type>
BaseAbility<Type>::BaseAbility() {
    std::cout << "   BaseAbility created." << std::endl;
}
template <class Type>
BaseAbility<Type>::~BaseAbility() {
    std::cout << "    - - BaseAbility destructed." << std::endl;
}

template <class Type>
void BaseAbility<Type>::bite(Unit<Type>* rodent, Unit<Type>* enemy) {
    // std::cout << "  !! It was a good try! But take care of your teeth! " << std::endl;
    // enemy->counterAttack(rodent);
}

template <class Type>
void BaseAbility<Type>::transform(Unit<Type>* unit) {
    // std::cout << "  :) It's realy interesting, whom do you want to transform into?" << std::endl;
}

template class BaseAbility<int>;
template class BaseAbility<double>;
template class BaseAbility<float>;
