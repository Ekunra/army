#ifndef LIMITEDFIELD_H
#define LIMITEDFIELD_H

#include <iostream>

template <class Type>
class LimitedField {
    protected:
        Type* value;
        Type* limit;

        Type validate(Type value);

    public:
        LimitedField(Type value);
        ~LimitedField();

        const Type& getValue() const;
        const Type& getLimit() const;

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
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const LimitedField<Type>& field);

#endif // LIMITEDFIELD_H
