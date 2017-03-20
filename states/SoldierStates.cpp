#include "SoldierStates.h"

template <class Type>
SoldierStates<Type>::SoldierStates ( LimitedField<Type>* health,
                               Damage<Type>* damage,
                               Defence* defence,
                               const std::string& title,
                               UnitEnum uEnum,
                               UnitEnum uType )
    : States<Type> ( health,
                     damage,
                     defence,
                     "Soldier",
                     uEnum,
                     uType ) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|    + " << FO_RESET;
        std::cout << FO_B << "SoldierStates" << FO_RESET <<" created" << std::endl;
    }
}

template <class Type>
SoldierStates<Type>::~SoldierStates() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "SoldierStates (" << FO_B << *this->title << FO_RESET << ") deleted." << std::endl;
    }
}


template class SoldierStates<int>;
template class SoldierStates<double>;
template class SoldierStates<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const SoldierStates<Type>& soldierStates) {
    out << *((States<Type>*)(&soldierStates));
    return out;
}

template std::ostream& operator<<(std::ostream& out, const SoldierStates<int>& soldierStates);
template std::ostream& operator<<(std::ostream& out, const SoldierStates<double>& soldierStates);
template std::ostream& operator<<(std::ostream& out, const SoldierStates<float>& soldierStates);
