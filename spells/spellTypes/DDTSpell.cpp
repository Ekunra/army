#include "DDTSpell.h"

template <class Type>
DDTSpell<Type>::DDTSpell(SpellEnum sEnum, SpellEnum sType, Type power, Type manaCost, const std::string& spellName)
    : Spell<Type>(sEnum, sType, power, manaCost, spellName) {
    std::cout << "   * +++ DDTSpell created" << std::endl;
}
template <class Type>
DDTSpell<Type>::DDTSpell(const Spell<Type>& prototype)
    : Spell<Type> ( prototype.getSEnum(),
                    prototype.getSType(),
                    prototype.getPower(),
                    prototype.getManaCost(),
                    prototype.getSpellName() ) {
    std::cout << "   * +++ DamageDTSpell created with Spell Prototype." << std::endl;
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
