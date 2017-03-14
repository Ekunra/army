#include "Vampire.h"

template <class Type>
Vampire<Type>::Vampire(const std::string& name) 
    :  Unit<Type>  (name, 
                    new VampireStates<Type>(),
                    nullptr,
                    new VampireInfectAbility<Type>(this),
                    NULL,
                    new VampireAttack<Type>,
                    new VampireCounterAttack<Type>) {
    if ( DEBUG ) {
        std::cout << FO_B_L_GREEN << "---------- ** " << FO_RESET;
        std::cout << FO_B << "Vampire instance created." << FO_RESET << "\n" << std::endl;
    }
}

template <class Type>
Vampire<Type>::~Vampire() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "-- ** " << FO_RESET;
        std::cout << FO_RED << "Vampire destructed." << FO_RESET << std::endl;
    }
}

template <class Type>
void Vampire<Type>::attack(Unit<Type>* enemy) {
    Unit<Type>::attack(enemy);
}


template class Vampire<int>;
template class Vampire<double>;
template class Vampire<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Vampire<Type>& vampire) {
    out << ' ' << FO_B << vampire.getName() << FO_RESET;
    out << FO_D_GREY << " [ " << FO_RESET;
    out << *((Unit<Type>*)(&vampire));
    out << FO_D_GREY << " ]" << FO_RESET;
    return out;
}

template std::ostream& operator<<(std::ostream& out, const Vampire<int>& vampire);
template std::ostream& operator<<(std::ostream& out, const Vampire<double>& vampire);
template std::ostream& operator<<(std::ostream& out, const Vampire<float>& vampire);
