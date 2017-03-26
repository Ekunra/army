#include "HealerStates.h"

template <class Type>
HealerStates<Type>::HealerStates ( LimitedField<Type>* health,
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
        std::cout << FO_B << "HealerStates" << FO_RESET <<" created" << std::endl;
    }
}

template <class Type>
HealerStates<Type>::~HealerStates() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "HealerStates (" << FO_B << *this->title << FO_RESET << ") deleted." << std::endl;
    }
}


template class HealerStates<int>;
template class HealerStates<double>;
template class HealerStates<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const HealerStates<Type>& healerStates) {
    out << *((States<Type>*)(&healerStates));
    return out;
}

template std::ostream& operator<<(std::ostream& out, const HealerStates<int>& healerStates);
template std::ostream& operator<<(std::ostream& out, const HealerStates<double>& healerStates);
template std::ostream& operator<<(std::ostream& out, const HealerStates<float>& healerStates);
