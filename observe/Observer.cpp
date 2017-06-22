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
void Observer<Type>::attachObservable(Unit<Type>* enemy) {
    this->observables->insert(enemy);
}

template <class Type>
void Observer<Type>::dettachObservable(Unit<Type>* enemy) {
    this->observables->erase(enemy);
}

template <class Type>
void Observer<Type>::notifyObservable() {}

template <class Type>
void Observer<Type>::showObservables() {
    typename std::set<Unit<Type>*>::iterator it = (*this->observables).begin();
    for ( ; it != this->observables->end(); it++ ) {
        std::cout << " --- " << (*it)->getName() << " [ " << **it << " ] " << std::endl;
    }
}


template class Observer<int>;
template class Observer<double>;
template class Observer<float>;

