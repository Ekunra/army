#include "DDTSpell.h"

template <class Type>
DDTSpell<Type>::DDTSpell(SpellEnum sEnum, Type power, Type manaCost, const std::string& spellName)
    : Spell<Type>(sEnum, power, manaCost, spellName) {
    std::cout << "   * +++ DDTSpell created" << std::endl;
}
template <class Type>
DDTSpell<Type>::~DDTSpell() {
    std::cout << "   * --- DDTSpell destructed" << std::endl;
}

template class DDTSpell<int>;
template class DDTSpell<double>;
template class DDTSpell<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const DDTSpell<Type>& spell) {
    std::cout << *((DDTSpell<Type>*)(&spell));
    return out;
}

template std::ostream& operator<<(std::ostream& out, const DDTSpell<int>& spell);
template std::ostream& operator<<(std::ostream& out, const DDTSpell<double>& spell);
template std::ostream& operator<<(std::ostream& out, const DDTSpell<float>& spell);
