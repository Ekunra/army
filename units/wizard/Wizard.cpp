#include "Wizard.h"

template <class Type>
Wizard<Type>::Wizard(const std::string& name)
    : SpellCaster<Type>(new SpellCasterStates<Type>(
                            new LimitedField<Type>( (Type)Mp::WIZARD,
                                                    FieldType::MANA ),
                            (double)DDTMagicCoef::WIZARD,
                            (double)HTMagicCoef::WIZARD,
                            (double)MTMagicCoef::WIZARD ),
                        new BaseCast<Type>(),
                        name,
                        new States<Type> (
                            new LimitedField<Type>( (Type)Hp::WIZARD,
                                                    FieldType::HEALTH ),
                            new Damage<Type>((Type)Dmg::WIZARD),
                            new Defence((double)TakeDamageCoef::WIZARD,
                                        (double)TakeMagicDamageCoef::WIZARD),
                            "Wizard",
                            UnitEnum::WIZARD,
                            UnitEnum::ALIVE ),
                        nullptr, // altState;
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

    if ( DEBUG ) {
        std::cout << FO_B_L_GREEN << "---------- ** " << FO_RESET;
        std::cout << FO_B << "Wizard instance created." << FO_RESET << std::endl;
    }
}
template <class Type>
Wizard<Type>::~Wizard() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "-- ** " << FO_RESET;
        std::cout << FO_RED << "Wizard destructed." << FO_RESET << std::endl;
    }
}

template <class Type>
void Wizard<Type>::cast(SpellEnum sEnum, SpellCaster<Type>* targetCaster) {
    if ( Unit<Type>::getUEnum() != UnitEnum::WIZARD ) {
        std::cout << " - This Unit has no cast ability now! He is a ";
        std::cout << FO_B_RED << Unit<Type>::getTitle() << FO_RESET << " now!" << std::endl;
        return;
    }
    SpellCaster<Type>::cast(sEnum, targetCaster);
}
template <class Type>
void Wizard<Type>::cast(SpellEnum sEnum, Unit<Type>* targetUnit) {
    if ( Unit<Type>::getUEnum() != UnitEnum::WIZARD ) {
        std::cout << " - This Unit has no cast ability now! He is a ";
        std::cout << FO_B_RED << Unit<Type>::getTitle() << FO_RESET << " now!" << std::endl;
        return;
    }
    SpellCaster<Type>::cast(sEnum, targetUnit);
}

template class Wizard<int>;
template class Wizard<double>;
template class Wizard<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Wizard<Type>& wizard) {
    out << ' ' << FO_B << wizard.getName() << FO_RESET;
    out << FO_D_GREY << " [ " << FO_RESET;
    out << *((SpellCaster<Type>*)(&wizard));
    out << FO_D_GREY << " ]" << FO_RESET;
    return out;
}

template std::ostream& operator<<(std::ostream& out, const Wizard<int>& wizard);
template std::ostream& operator<<(std::ostream& out, const Wizard<double>& wizard);
template std::ostream& operator<<(std::ostream& out, const Wizard<float>& wizard);

