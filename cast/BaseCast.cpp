#include "BaseCast.h"

template <class Type>
BaseCast<Type>::BaseCast() {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|          + " << FO_RESET;
        std::cout << FO_B << "BaseCast" << FO_RESET <<" instance created" << std::endl;
    }
}
template <class Type>
BaseCast<Type>::~BaseCast() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "BaseCast instance deleted." << std::endl;
    }
}

template <class Type>
void BaseCast<Type>::action() {}


template class BaseCast<int>;
template class BaseCast<double>;
template class BaseCast<float>;
