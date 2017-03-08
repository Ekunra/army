#include "WolfStates.h"

template <class Type>
WolfStates<Type>::WolfStates ( LimitedField<Type>* health,
                               Damage<Type>* damage,
                               Defence* defence,
                               const std::string& title,
                               UnitEnum uEnum,
                               UnitEnum uType )
    : States<Type> ( health,
                     damage,
                     defence,
                     "Wolf",
                     uEnum,
                     uType) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|    + " << FO_RESET;
        std::cout << FO_B << "WolfStates" << FO_RESET <<" created" << std::endl;
    }
}

template <class Type>
WolfStates<Type>::~WolfStates() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "WolfStates (" << FO_B << *this->title << FO_RESET << ") deleted." << std::endl;
    }
}


template class WolfStates<int>;
template class WolfStates<double>;
template class WolfStates<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const WolfStates<Type>& wolfStates) {
    out << *((States<Type>*)(&wolfStates));
    return out;
}

template std::ostream& operator<<(std::ostream& out, const WolfStates<int>& wolfStates);
template std::ostream& operator<<(std::ostream& out, const WolfStates<double>& wolfStates);
template std::ostream& operator<<(std::ostream& out, const WolfStates<float>& wolfStates);
