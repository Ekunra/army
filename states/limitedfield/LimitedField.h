#ifndef LIMITEDFIELD_H
#define LIMITEDFIELD_H

#include <iostream>
#include <cmath>
#include "../../macro_color.cpp"
#include "../../debug.h"
#include "../../Properties.h"

template <class Type>
class LimitedField {
    protected:
        Type* value;
        Type* limit;
        FieldType* fType;

        Type validate(Type value);

    public:
        LimitedField(Type value, FieldType fType=FieldType::DEFAULT);
        LimitedField(const LimitedField& obj);
        ~LimitedField();

        const Type& getValue() const;
        const Type& getLimit() const;
        const FieldType& getFieldType() const;

        const bool operator==(Type value) const;
        const bool operator!=(Type value) const;
        const bool operator>=(Type value) const;
        const bool operator<=(Type value) const;
        const bool operator>(Type value) const;
        const bool operator<(Type value) const;

        void operator+=(Type value);
        void operator-=(Type value);
        void operator*=(Type value);
        void operator/=(Type value);

        Type operator+(Type value);
        Type operator-(Type value);
        Type operator*(Type value);
        Type operator/(Type value);

        LimitedField operator=(const LimitedField& other);
        LimitedField operator=(Type value);

        void mutate(const LimitedField& other, double coef);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const LimitedField<Type>& field);

#endif // LIMITEDFIELD_H
