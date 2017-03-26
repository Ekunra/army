#include "Healer.h"

template <class Type>
Healer<Type>::Healer(const std::string& name)
    : SpellCaster<Type>(new SpellCasterStates<Type>(
                            new LimitedField<Type>( (Type)Mp::HEALER,
                                                    FieldType::MANA ),
                            (double)DDTMagicCoef::HEALER,
                            (double)HTMagicCoef::HEALER,
                            (double)DMTMagicCoef::HEALER,
                            (double)MTMagicCoef::HEALER ),
                        new BaseCast<Type>(),
                        name,
                        new HealerStates<Type>(),
                        nullptr, // altStates;
                        nullptr, // primary Ability;
                        nullptr, // secondary Ability;
                        new BaseAttack<Type>,
                        new BaseCounterAttack<Type> ) {

    SpellCaster<Type>::spellBook->insertSpell(FIREBALL, new FireBall<Type>);
    SpellCaster<Type>::spellBook->insertSpell(IMPLOSION, new Implosion<Type>);
    SpellCaster<Type>::spellBook->insertSpell(LIGHTNINGBOLT, new LightningBolt<Type>);
    SpellCaster<Type>::spellBook->insertSpell(HEAL, new Heal<Type>);
    SpellCaster<Type>::spellBook->insertSpell(BLESS, new Bless<Type>);
    SpellCaster<Type>::spellBook->insertSpell(MANAPORTION, new ManaPortion<Type>);
    SpellCaster<Type>::spellBook->insertSpell(MANADRAIN, new ManaDrain<Type>);

    if ( DEBUG ) {
        std::cout << FO_B_L_GREEN << "---------- ** " << FO_RESET;
        std::cout << FO_B << "Healer instance created." << FO_RESET << "\n" << std::endl;
    }
}
template <class Type>
Healer<Type>::~Healer() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "-- ** " << FO_RESET;
        std::cout << FO_RED << "Healer destructed." << FO_RESET << std::endl;
    }
}

template <class Type>
void Healer<Type>::cast(SpellEnum sEnum, SpellCaster<Type>* targetCaster) {
    if ( Unit<Type>::getUEnum() != UnitEnum::WIZARD ) {
        return;
    }
    std::cout << FO_B << this->getName() << FO_RESET;
    std::cout << "'s cast(SpellEnum, SpellCaster*) received ";
    std::cout << targetCaster->getName() << " for sending it to SpellCaster's::cast" << std::endl;
    SpellCaster<Type>::cast(sEnum, targetCaster);
}
template <class Type>
void Healer<Type>::cast(SpellEnum sEnum, Unit<Type>* targetUnit) {
    if ( Unit<Type>::getUEnum() != UnitEnum::WIZARD ) {
        return;
    }
    std::cout << FO_B << this->getName() << FO_RESET;
    std::cout << "'s cast(SpellEnum, Unit*) received ";
    std::cout << targetUnit->getName() << " for sending it to SpellCaster's::cast" << std::endl;
    SpellCaster<Type>::cast(sEnum, targetUnit);
}

template class Healer<int>;
template class Healer<double>;
template class Healer<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Healer<Type>& healer) {
    out << ' ' << FO_B << healer.getName() << FO_RESET;
    out << FO_D_GREY << " [ " << FO_RESET;
    out << *((SpellCaster<Type>*)(&healer));
    out << FO_D_GREY << " ]" << FO_RESET;
    return out;
}

template std::ostream& operator<<(std::ostream& out, const Healer<int>& healer);
template std::ostream& operator<<(std::ostream& out, const Healer<double>& healer);
template std::ostream& operator<<(std::ostream& out, const Healer<float>& healer);

