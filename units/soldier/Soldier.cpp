#include "Soldier.h"

template <class Type>
Soldier<Type>::Soldier(const std::string& name) 
                :  Unit<Type>  (name, 
                                new States<Type>(new LimitedField<Type>( (Type)Hp::SOLDIER, FieldType::HEALTH ),
                                                 new Damage<Type>((Type)Dmg::SOLDIER),
                                                 new Defence((double)TakeDamageCoef::SOLDIER,
                                                             (double)TakeMagicDamageCoef::SOLDIER),
                                                 "Soldier",
                                                 UnitEnum::SOLDIER,
                                                 UnitEnum::ALIVE),
                                NULL/*new BaseAbility<Type>(this)*/,
                                NULL,
                                new BaseAttack<Type>,
                                new BaseCounterAttack<Type>) {
    if ( DEBUG ) {
        std::cout << FO_B_L_GREEN << "-------- ** " << FO_RESET;
        std::cout << FO_B << "Soldier instance created." << FO_RESET << std::endl;
    }
}

template <class Type>
Soldier<Type>::~Soldier() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "   ** " << FO_RESET;
        std::cout << FO_RED << "Soldier destructed." << FO_RESET << std::endl;
    }
}

template <class Type>
void Soldier<Type>::attack(Unit<Type>* enemy) {
    Unit<Type>::attack(enemy);
}


template class Soldier<int>;
template class Soldier<double>;
template class Soldier<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Soldier<Type>& soldier) {
    out << ' ' << FO_B << soldier.getName() << FO_RESET;
    out << FO_D_GREY << " [ " << FO_RESET;
    out << *((Unit<Type>*)(&soldier));
    out << FO_D_GREY << " ]" << FO_RESET;
    return out;
}

template std::ostream& operator<<(std::ostream& out, const Soldier<int>& soldier);
template std::ostream& operator<<(std::ostream& out, const Soldier<double>& soldier);
template std::ostream& operator<<(std::ostream& out, const Soldier<float>& soldier);
