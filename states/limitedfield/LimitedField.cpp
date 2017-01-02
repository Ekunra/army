#include <iostream>
#include "LimitedField.h"


template <class Type>
LimitedField<Type>::LimitedField(Type value)
    : value(new Type(value)), limit(new Type(value)) {
}

template <class Type>
LimitedField<Type>::~LimitedField() {
    std::cout << "LimitedField deleted" << std::endl;
    delete value;
    delete limit;
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
    return result;
}


template <class Type>
const Type LimitedField<Type>::getValue() const {
    return *this->value;
}
template <class Type>
const Type LimitedField<Type>::getLimit() const {
    return *this->limit;
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
    return *this;
}

template <class Type>
LimitedField<Type> LimitedField<Type>::operator=(Type value) {
    *this->value = value;
    *this->limit = value;
    return *this;
}


template <class Type>
std::ostream& operator<<(std::ostream& out, const LimitedField<Type>& field) {
    out << '(' << field.getValue() << '/' << field.getLimit() << ')';
    return out;
}

template class LimitedField<int>;
template class LimitedField<double>;
template class LimitedField<float>;

template std::ostream& operator<<(std::ostream& out, const LimitedField<int>& field);
template std::ostream& operator<<(std::ostream& out, const LimitedField<double>& field);
template std::ostream& operator<<(std::ostream& out, const LimitedField<float>& field);
