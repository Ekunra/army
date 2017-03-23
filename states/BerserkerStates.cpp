#include "BerserkerStates.h"

template <class Type>
BerserkerStates<Type>::BerserkerStates ( LimitedField<Type>* health,
                               Damage<Type>* damage,
                               Defence* defence,
                               const std::string& title,
                               UnitEnum uEnum,
                               UnitEnum uType )
    : States<Type> ( health,
                     damage,
                     defence,
                     "Berserker",
                     uEnum,
                     uType ) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|    + " << FO_RESET;
        std::cout << FO_B << "BerserkerStates" << FO_RESET <<" created" << std::endl;
    }
}

template <class Type>
BerserkerStates<Type>::~BerserkerStates() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "BerserkerStates (" << FO_B << *this->title << FO_RESET << ") deleted." << std::endl;
    }
}


template class BerserkerStates<int>;
template class BerserkerStates<double>;
template class BerserkerStates<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const BerserkerStates<Type>& berserkerStates) {
    out << *((States<Type>*)(&berserkerStates));
    return out;
}

template std::ostream& operator<<(std::ostream& out, const BerserkerStates<int>& berserkerStates);
template std::ostream& operator<<(std::ostream& out, const BerserkerStates<double>& berserkerStates);
template std::ostream& operator<<(std::ostream& out, const BerserkerStates<float>& berserkerStates);
