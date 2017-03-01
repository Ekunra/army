#include "DMTSpell.h"

template <class Type>
DMTSpell<Type>::DMTSpell(SpellEnum sEnum, SpellEnum sType, Type power, Type manaCost, const std::string& spellName)
    : Spell<Type>(sEnum, sType, power, manaCost, spellName) {
    std::cout << "   * +++ DMTSpell created" << std::endl;
}
template <class Type>
DMTSpell<Type>::DMTSpell(const Spell<Type>& prototype)
    : Spell<Type> ( prototype.getSEnum(),
                    prototype.getSType(),
                    prototype.getPower(),
                    prototype.getManaCost(),
                    prototype.getSpellName() ) {
    std::cout << "   * +++ DMTSpell created with Spell Prototype." << std::endl;
}
template <class Type>
DMTSpell<Type>::~DMTSpell() {
    std::cout << "   * --- DMTSpell destructed" << std::endl;
}

template class DMTSpell<int>;
template class DMTSpell<double>;
template class DMTSpell<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const DMTSpell<Type>& spell) {
    std::cout << *((Spell<Type>*)(&spell));
    return out;
}

template std::ostream& operator<<(std::ostream& out, const DMTSpell<int>& spell);
template std::ostream& operator<<(std::ostream& out, const DMTSpell<double>& spell);
template std::ostream& operator<<(std::ostream& out, const DMTSpell<float>& spell);
