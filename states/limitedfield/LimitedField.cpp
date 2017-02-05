#include <iostream>
#include "LimitedField.h"


template <class Type>
LimitedField<Type>::LimitedField(Type value, FieldType fType)
            : value(new Type(value)),
              limit(new Type(value)),
              fType(new FieldType(fType)) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "   + " << FO_RESET;
        std::cout << FO_D_GREY << "LimitedField Instance created." << FO_RESET;

        switch (fType) {
            case FieldType::HEALTH : {
                std::cout << " Health.";
                break;
            }
            case FieldType::MANA : {
                std::cout << " Mana.";
                break;
            }
            default : {
                std::cout << " Default.";
            }
        }

        std::cout << std::endl;

    }
}

template <class Type>
LimitedField<Type>::LimitedField(const LimitedField& obj) {
    std::cout << "Copy constructor works." << std::endl;
    std::cout << obj.getValue() << std::endl;
    std::cout << obj.getLimit() << std::endl;
    value = new Type(obj.getValue());
    limit = new Type(obj.getLimit());
    fType = new FieldType(obj.getFieldType());
    std::cout << "Copy constructor finished its work." << std::endl;
}

template <class Type>
LimitedField<Type>::~LimitedField() {
    delete value;
    delete limit;
    if ( DEBUG ) {
        std::cout << FO_B_RED << "        - " FO_RESET;
        std::cout << "LimitedField Instance deleted" << std::endl;
    }
}


template <class Type>
Type LimitedField<Type>::validate(Type result) {
std::cout << "- \"Validate function works\"" << std::endl;
    if ( result > *this->limit ) {
        return *this->limit;
    }
    if ( result < 0 ) {
        return 0;
    }
    return round( result * 100 ) / 100;
}


template <class Type>
const Type& LimitedField<Type>::getValue() const {
    return *this->value;
}
template <class Type>
const Type& LimitedField<Type>::getLimit() const {
    return *this->limit;
}
template <class Type>
const FieldType& LimitedField<Type>::getFieldType() const {
    return *this->fType;
}


template <class Type>
const bool LimitedField<Type>::operator==(Type value) const {
std::cout << "\"Operator == works\"" << std::endl;
    return *this->value == value;
}

template <class Type>
const bool LimitedField<Type>::operator!=(Type value) const {
std::cout << "\"Operator != works\"" << std::endl;
    return *this->value != value;
}

template <class Type>
const bool LimitedField<Type>::operator>=(Type value) const {
std::cout << "\"Operator >= works\"" << std::endl;
    return *this->value >= value;
}

template <class Type>
const bool LimitedField<Type>::operator<=(Type value) const {
std::cout << "\"Operator <= works\"" << std::endl;
    return *this->value <= value;
}

template <class Type>
const bool LimitedField<Type>::operator>(Type value) const {
std::cout << "\"Operator > works\"" << std::endl;
    return *this->value > value;
}

template <class Type>
const bool LimitedField<Type>::operator<(Type value) const {
std::cout << "\"Operator < works\"" << std::endl;
    return *this->value < value;
}


template <class Type>
void LimitedField<Type>::operator+=(Type value) {
std::cout << "\"Operator += works\"" << std::endl;
    Type result = *this->value + value;

    *this->value = this->validate(result);
}

template <class Type>
void LimitedField<Type>::operator-=(Type value) {
std::cout << "\"Operator -= works\"" << std::endl;
    Type result = *this->value - value;

    *this->value = this->validate(result);
}

template <class Type>
void LimitedField<Type>::operator*=(Type value) {
std::cout << "\"Operator *= works\"" << std::endl;
    Type result = *this->value * value;

    *this->value = this->validate(result);
}

template <class Type>
void LimitedField<Type>::operator/=(Type value) {
std::cout << "\"Operator /= works\"" << std::endl;
    Type result = *this->value / value;

    *this->value = this->validate(result);
}


template <class Type>
Type LimitedField<Type>::operator+(Type value) {
    return *this->value + value;
}

template <class Type>
Type LimitedField<Type>::operator-(Type value) {
    return *this->value - value;
}

template <class Type>
Type LimitedField<Type>::operator*(Type value) {
    return *this->value * value;
}

template <class Type>
Type LimitedField<Type>::operator/(Type value) {
    return *this->value / value;
}

template <class Type>
LimitedField<Type> LimitedField<Type>::operator=(const LimitedField& other) {
std::cout << "\"Operator = works\"" << std::endl;
    *this->value = other.getValue();
    *this->limit = other.getLimit();
    *this->fType = other.getFieldType();
    return *this;
}

template <class Type>
LimitedField<Type> LimitedField<Type>::operator=(Type value) {
    *this->value = value;
    *this->limit = value;
    return *this;
}
template <class Type>
void LimitedField<Type>::mutate(const LimitedField& other, double coef) {
    *this->value = (float)(*other.value) * coef;
    *this->limit = (float)(*other.limit) * coef;
}

template <class Type>
std::ostream& operator<<(std::ostream& out, const LimitedField<Type>& field) {
    Type full = field.getLimit();
    Type almostFull = (Type)(( (float)field.getLimit() / 10 ) * 8);
    Type hurmed = field.getLimit() / 2;
    Type veryHurmed = (Type)(( (float)field.getLimit() / 10 ) * 2);


    switch ( field.getFieldType() ) {
        case FieldType::HEALTH : {

            out << FO_D_GREY << "HP:" << FO_RESET;

            if ( field.getValue() >= full ) {

                out << FO_B_L_GREEN << field.getValue() << FO_RESET;
                out << FO_D_GREY << '/' << FO_RESET;
                out << FO_B_L_GREEN << field.getLimit() << FO_RESET;

            } else if ( field.getValue() < full && field.getValue() >= almostFull ) {

                out << FO_GREEN << field.getValue() << FO_RESET;
                out << FO_D_GREY << '/' << FO_RESET;
                out << FO_L_GREEN << field.getLimit() << FO_RESET;

            } else if ( field.getValue() < almostFull && field.getValue() >= hurmed ) {

                out << FO_GREEN << field.getValue() << FO_RESET;
                out << FO_D_GREY << '/' << FO_RESET;
                out << FO_GREEN << field.getLimit() << FO_RESET;

            } else if ( field.getValue() < hurmed && field.getValue() >= veryHurmed ) {

                out << FO_ORANGE << field.getValue() << FO_RESET;
                out << FO_D_GREY << '/' << FO_RESET;
                out << FO_GREEN << field.getLimit() << FO_RESET;

            } else if ( field.getValue() < veryHurmed && field.getValue() >= 0.001 ) {

                out << FO_RED << field.getValue() << FO_RESET;
                out << FO_D_GREY << '/' << FO_RESET;
                out << FO_B_ORANGE << field.getLimit() << FO_RESET;

            } else if ( field.getValue() < 0.001 ) {

                out << FO_B_L_RED << field.getValue() << FO_RESET;
                out << FO_D_GREY << '/' << FO_RESET;
                out << FO_RED << field.getLimit() << FO_RESET;

            }
            break;
        }

        case FieldType::MANA : {

            out << FO_D_GREY << "MP:" << FO_RESET;

            if ( field.getValue() >= full ) {

                out << FO_B_BLUE256 << field.getValue() << FO_RESET;
                out << FO_D_GREY << '/' << FO_RESET;
                out << FO_B_BLUE256 << field.getLimit() << FO_RESET;

            } else if ( field.getValue() < full && field.getValue() >= almostFull ) {

                out << FO_BLUE256 << field.getValue() << FO_RESET;
                out << FO_D_GREY << '/' << FO_RESET;
                out << FO_B_BLUE256 << field.getLimit() << FO_RESET;

            } else if ( field.getValue() < almostFull && field.getValue() >= hurmed ) {

                out << FO_BLUE256 << field.getValue() << FO_RESET;
                out << FO_D_GREY << '/' << FO_RESET;
                out << FO_BLUE256 << field.getLimit() << FO_RESET;

            } else if ( field.getValue() < hurmed && field.getValue() >= veryHurmed ) {

                out << FO_VIOLET256 << field.getValue() << FO_RESET;
                out << FO_D_GREY << '/' << FO_RESET;
                out << FO_BLUE256 << field.getLimit() << FO_RESET;

            } else if ( field.getValue() < veryHurmed && field.getValue() >= 0.001 ) {

                out << FO_PINK256 << field.getValue() << FO_RESET;
                out << FO_D_GREY << '/' << FO_RESET;
                out << FO_BLUE << field.getLimit() << FO_RESET;

            } else if ( field.getValue() < 0.001 ) {

                out << FO_B_L_RED << field.getValue() << FO_RESET;
                out << FO_D_GREY << '/' << FO_RESET;
                out << FO_BLUE << field.getLimit() << FO_RESET;

            }
            break;
        }
        default : {}
    }
    return out;
}

template class LimitedField<int>;
template class LimitedField<double>;
template class LimitedField<float>;

template std::ostream& operator<<(std::ostream& out, const LimitedField<int>& field);
template std::ostream& operator<<(std::ostream& out, const LimitedField<double>& field);
template std::ostream& operator<<(std::ostream& out, const LimitedField<float>& field);
