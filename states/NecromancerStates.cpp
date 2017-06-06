#include "NecromancerStates.h"

template <class Type>
NecromancerStates<Type>::NecromancerStates ( LimitedField<Type>* health,
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
        std::cout << FO_B << "NecromancerStates" << FO_RESET <<" created" << std::endl;
    }
}

template <class Type>
NecromancerStates<Type>::~NecromancerStates() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "NecromancerStates (" << FO_B << *this->title << FO_RESET << ") deleted." << std::endl;
    }
}


template class NecromancerStates<int>;
template class NecromancerStates<double>;
template class NecromancerStates<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const NecromancerStates<Type>& necromancerStates) {
    out << *((States<Type>*)(&necromancerStates));
    return out;
}

template std::ostream& operator<<(std::ostream& out, const NecromancerStates<int>& necromancerStates);
template std::ostream& operator<<(std::ostream& out, const NecromancerStates<double>& necromancerStates);
template std::ostream& operator<<(std::ostream& out, const NecromancerStates<float>& necromancerStates);
