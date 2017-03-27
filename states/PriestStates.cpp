#include "PriestStates.h"

template <class Type>
PriestStates<Type>::PriestStates ( LimitedField<Type>* health,
                               Damage<Type>* damage,
                               Defence* defence,
                               const std::string& title,
                               UnitEnum uEnum,
                               UnitEnum uType )
    : States<Type> ( health,
                     damage,
                     defence,
                     title,
                     uEnum,
                     uType ) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|    + " << FO_RESET;
        std::cout << FO_B << "PriestStates" << FO_RESET <<" created" << std::endl;
    }
}

template <class Type>
PriestStates<Type>::~PriestStates() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "PriestStates (" << FO_B << *this->title << FO_RESET << ") deleted." << std::endl;
    }
}


template class PriestStates<int>;
template class PriestStates<double>;
template class PriestStates<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const PriestStates<Type>& priestStates) {
    out << *((States<Type>*)(&priestStates));
    return out;
}

template std::ostream& operator<<(std::ostream& out, const PriestStates<int>& priestStates);
template std::ostream& operator<<(std::ostream& out, const PriestStates<double>& priestStates);
template std::ostream& operator<<(std::ostream& out, const PriestStates<float>& priestStates);
