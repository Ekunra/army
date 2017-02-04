#include "Wizard.h"

template <class Type>
Wizard<Type>::Wizard(const std::string& name)
                : SpellCaster<Type>(name,
                                    new SpellCasterStates<Type>(
                                        new LimitedField<Type>( (Type)Mp::WIZARD,
                                                                FieldType::MANA) ),
                                    new States<Type> (
                                        new LimitedField<Type>( (Type)Hp::WIZARD,
                                                                FieldType::HEALTH ),
                                        new Damage<Type>((Type)Dmg::WIZARD),
                                        new Defence((double)TakeDamageCoef::WIZARD,
                                                    (double)TakeMagicDamageCoef::WIZARD),
                                        "Wizard",
                                        UnitEnum::WIZARD,
                                        UnitEnum::ALIVE ),
                                    NULL,
                                    NULL,
                                    new BaseAttack<Type>,
                                    new BaseCounterAttack<Type> ) {

    // SpellCaster<Type>::spellBook->insertSpell(FIREBALL, new FireBall<Type>);
    // SpellCaster<Type>::spellBook->insertSpell(IMPLOSION, new Implosion<Type>);
    // SpellCaster<Type>::spellBook->insertSpell(LIGHTNINGBOLT, new LightningBolt<Type>);
    // SpellCaster<Type>::spellBook->insertSpell(HEAL, new Heal<Type>);
    // SpellCaster<Type>::spellBook->insertSpell(BLESS, new Bless<Type>);
    // SpellCaster<Type>::spellBook->insertSpell(MANAPORTION, new ManaPortion<Type>);

    if ( DEBUG ) {
        std::cout << FO_B_L_GREEN << "         ** " << FO_RESET;
        std::cout << FO_B << "Wizard instance created." << FO_RESET << std::endl;
    }
}
template <class Type>
Wizard<Type>::~Wizard() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "   ** " << FO_RESET;
        std::cout << FO_RED << "Wizard destructed." << FO_RESET << std::endl;
    }
}

template <class Type>
void Wizard<Type>::cast(SpellEnum sEnum, SpellCaster<Type>* someCaster) {}
template <class Type>
void Wizard<Type>::cast(SpellEnum sEnum, Unit<Type>* enemy) {}

template class Wizard<int>;
template class Wizard<double>;
template class Wizard<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Wizard<Type>& wizard) {}

template std::ostream& operator<<(std::ostream& out, const Wizard<int>& wizard);
template std::ostream& operator<<(std::ostream& out, const Wizard<double>& wizard);
template std::ostream& operator<<(std::ostream& out, const Wizard<float>& wizard);

