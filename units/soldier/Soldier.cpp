#include "Soldier.h"

template <class Type>
Soldier<Type>::Soldier(const std::string& name) 
                :  Unit<Type>  (name, 
                                new States<Type>((Type)Hp::SOLDIER,
                                                 (Type)Dmg::SOLDIER,
                                                 "Soldier",
                                                 UnitEnum::SOLDIER,
                                                 UnitEnum::SOLDIER),
                                new BaseAbility<Type>,
                                new BaseAttack<Type>,
                                new BaseCounterAttack<Type>) {}

template <class Type>
Soldier<Type>::~Soldier() {
    std::cout << " -- Soldier destructed." << std::endl;
}

template <class Type>
void Soldier<Type>::attack(Unit<Type>* enemy) {
    // Unit::attack(enemy);
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
