#include "LimitedField.h"

template<class Type>
LimitedField<Type>::LimitedField(Type value) {
    this->value = new Type(value);
    this->limit = new Type(value);
	std::cout << "*this->value = " << *(this->value) << std::endl;
	std::cout << "this->value = " << this->value << std::endl;
    
}

template<class Type>
LimitedField<Type>::~LimitedField() {}

// template <class Type>
// Type LimitedField<Type>::validate(Type result) {
//     if ( result > this->limit ) {
//         return this->limit;
//     }
//     if ( result < 0 ) {
//         return 0;
//     }
//     return result;
// }

template<class Type>
const Type LimitedField<Type>::getValue() const {
    return *this->value;
}

template<class Type>
const Type LimitedField<Type>::getLimit() const {
    return *this->limit;
}

template <class Type>
const bool LimitedField<Type>::operator==(const LimitedField& other) const {
    return *this->value != other.getValue();
}

template <class Type>
void LimitedField<Type>::show(const LimitedField* other) {
	std::cout << "other.value = " << other.value << std::endl;
	std::cout << "*other.value = " << *other.value << std::endl;
	// std::cout << "other->value = " << other->value << std::endl;
	// std::cout << "*other->value = " << *other->value << std::endl;
	std::cout << "other.getValue() = " << other.getValue() << std::endl;
	// std::cout << "*other.getValue() = " << *other.getValue() << std::endl;
	// std::cout << "other->getValue() = " << other->getValue() << std::endl;
	// std::cout << "*other->getValue() = " << *other->getValue() << std::endl;
}


// template <class Type>
// const bool LimitedField<Type>::operator!=(const LimitedField& other) const {
//     return !(*this == other);
// }

// template <class Type>
// const bool LimitedField<Type>::operator>=(const LimitedField& other) const {
//     return this->value >= other.value;
// }

// template <class Type>
// const bool LimitedField<Type>::operator<=(const LimitedField& other) const {
//     return this->value <= other.value;
// }

// template <class Type>
// const bool LimitedField<Type>::operator>(const LimitedField& other) const {
//     return this->value > other.value;
// }

// template <class Type>
// const bool LimitedField<Type>::operator<(const LimitedField& other) const {
//     return this->value < other.value;
// }

// template <class Type>
// void LimitedField<Type>::operator+=(const LimitedField& other) {
//     Type result = this->value + other.value;

//     this->value = this->validate(result);
// }

// template <class Type>
// void LimitedField<Type>::operator-=(const LimitedField& other) {
//     Type result = this->value - other.value;

//     this->value = this->validate(result);
// }

// template <class Type>
// void LimitedField<Type>::operator*=(const LimitedField& other) {
//     Type result = this->value * other.value;

//     this->value = this->validate(result);
// }

// template <class Type>
// void LimitedField<Type>::operator/=(const LimitedField& other) {
//     Type result = this->value + other.value;

//     this->value = this->validate(result);
// }

// template <class Type>
// Type LimitedField<Type>::operator+(const LimitedField& other) {
//     return this->value + other.value;
// }

// template <class Type>
// Type LimitedField<Type>::operator-(const LimitedField& other) {
//     return this->value - other.value;
// }

// template <class Type>
// Type LimitedField<Type>::operator*(const LimitedField& other) {
//     return this->value * other.value;
// }

// template <class Type>
// Type LimitedField<Type>::operator/(const LimitedField& other) {
//     return this->value / other.value;
// }

// template <class Type>
// const bool LimitedField<Type>::operator==(Type value) const {
//     return this->value == value;
// }

// template <class Type>
// const bool LimitedField<Type>::operator!=(Type value) const {
//     return this->value != value;
// }

// template <class Type>
// const bool LimitedField<Type>::operator>=(Type value) const {
//     return this->value >= value;
// }

// template <class Type>
// const bool LimitedField<Type>::operator<=(Type value) const {
//     return this->value <= value;
// }

// template <class Type>
// const bool LimitedField<Type>::operator>(Type value) const {
//     return this->value > value;
// }

// template <class Type>
// const bool LimitedField<Type>::operator<(Type value) const {
//     return this->value < value;
// }

// template <class Type>
// void LimitedField<Type>::operator+=(Type value) {
//     Type result = this->value + value;

//     this->value = this->validate(result);
// }

// template <class Type>
// void LimitedField<Type>::operator-=(Type value) {
//     Type result = this->value - value;

//     this->value = this->validate(result);
// }

// template <class Type>
// void LimitedField<Type>::operator*=(Type value) {
//     Type result = this->value * value;

//     this->value = this->validate(result);
// }

// template <class Type>
// void LimitedField<Type>::operator/=(Type value) {
//     Type result = this->value / value;

//     this->value = this->validate(result);
// }

// template <class Type>
// Type LimitedField<Type>::operator+(Type value) {
//     return this->value + value;
// }

// template <class Type>
// Type LimitedField<Type>::operator-(Type value) {
//     return this->value - value;
// }

// template <class Type>
// Type LimitedField<Type>::operator*(Type value) {
//     return this->value * value;
// }

// template <class Type>
// Type LimitedField<Type>::operator/(Type value) {
//     return this->value / value;
// }

// template <class Type>
// LimitedField<Type> LimitedField<Type>::operator=(const LimitedField& other) {
//     this->value = other.value;
//     this->limit = other.limit;
//     return *this;
// }

// template <class Type>
// LimitedField<Type> LimitedField<Type>::operator=(Type value) {
//     this->value = value;
//     this->limit = value;
//     return *this;
// }



template<class Type>
std::ostream& operator<<(std::ostream& out, const LimitedField<Type>& field) {
    out << field.getValue() << '/' << field.getLimit();
    return out;
}

template class LimitedField<int>;
template class LimitedField<double>;
template class LimitedField<float>;

template std::ostream& operator<<(std::ostream& out, const LimitedField<int>& field);
template std::ostream& operator<<(std::ostream& out, const LimitedField<double>& field);
template std::ostream& operator<<(std::ostream& out, const LimitedField<float>& field);