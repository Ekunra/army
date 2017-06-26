#include "Observable.h"


template <class Type>
Observable<Type>::Observable(Unit<Type>* owner) : owner(owner), observers(new std::set<Necromancer<Type>*>) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|        + " << FO_RESET;
        std::cout << FO_B << "Observable" << FO_RESET << " instance created. " << std::endl;
    }
    // std::cout << *this->owner << std::endl;
}

template <class Type>
Observable<Type>::~Observable() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "  - " << FO_RESET;
        std::cout << "Observable instance destructed." << std::endl;
    }
}


template <class Type>
void Observable<Type>::attachObserver() {}

template <class Type>
void Observable<Type>::dettachObserver() {}

template <class Type>
void Observable<Type>::notifyObserver() {}

template class Observable<int>;
template class Observable<double>;
template class Observable<float>;
