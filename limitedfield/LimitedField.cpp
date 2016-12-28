#include <iostream>
#include "LimitedField.h"


template <class Type>
LimitedField<Type>::LimitedField(Type value)
    : value(new Type(value)), limit(new Type(value)) {
}

template <class Type>
LimitedField<Type>::~LimitedField() {
    delete value;
    delete limit;
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
