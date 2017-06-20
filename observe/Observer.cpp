#include "Observer.h"

template <class Type>
Observer<Type>::Observer(Necromancer<Type>* necr) : owner(necr), observables(new std::set<Unit<Type>*>) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|        + " << FO_RESET;
        std::cout << FO_B << "Observer" << FO_RESET << " instance created. " << std::endl;
    }
}
template <class Type>
Observer<Type>::~Observer() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "  - " << FO_RESET;
        std::cout << "Observer instance destructed." << std::endl;
    }
}

template <class Type>
void Observer<Type>::attachObservable() {}
template <class Type>
void Observer<Type>::dettachObservable() {}
template <class Type>
void Observer<Type>::notifyObservable() {}

template class Observer<int>;
template class Observer<double>;
template class Observer<float>;

