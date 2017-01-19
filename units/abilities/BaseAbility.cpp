#include "BaseAbility.h"

template <class Type>
BaseAbility<Type>::BaseAbility(Unit<Type>* owner) : owner(owner) {
    std::cout << "   BaseAbility created." << std::endl;
}
template <class Type>
BaseAbility<Type>::~BaseAbility() {
    std::cout << "    - - BaseAbility destructed." << std::endl;
}

template <class Type>
void BaseAbility<Type>::action(Unit<Type>* enemy) {
    std::cout << "  !! It was a good try! But take care of your teeth! " << std::endl;
    enemy->counterAttack(rodent);
}

template class BaseAbility<int>;
template class BaseAbility<double>;
template class BaseAbility<float>;
