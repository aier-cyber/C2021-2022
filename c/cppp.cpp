/*
class BigInt {
public:
    BigInt(); // +
    BigInt(int); // +
    BigInt(std::string); // +
    BigInt(const BigInt&); // +
    ~BigInt(); // +
    BigInt& operator=(const BigInt&);  // +
    BigInt operator~() const; // +

    BigInt& operator++(); // +
    const BigInt operator++(int) const; // +
    BigInt& operator--(); // +
    const BigInt operator--(int) const; // +

    BigInt& operator+=(const BigInt&); // +
    BigInt& operator*=(const BigInt&); // +
    BigInt& operator-=(const BigInt&); // +
    BigInt& operator/=(const BigInt&); // +
    BigInt& operator%=(const BigInt&); // +
    BigInt& operator^=(const BigInt&); // +
    BigInt& operator&=(const BigInt&); // +
    BigInt& operator|=(const BigInt&); // +

    BigInt operator+() const;  // +
    BigInt operator-() const;  // +

    bool operator==(const BigInt&) const; // +
    bool operator!=(const BigInt&) const; // +
    bool operator<(const BigInt&) const; // +
    bool operator>(const BigInt&) const; // +
    bool operator<=(const BigInt&) const; // +
    bool operator>=(const BigInt&) const; // +

    operator int() const; // -
    operator std::string() const; // +
    size_t size() const;  // +
};

BigInt operator+(const BigInt&, const BigInt&); // +
BigInt operator-(const BigInt&, const BigInt&); // +
BigInt operator*(const BigInt&, const BigInt&); // +
BigInt operator/(const BigInt&, const BigInt&); // +
BigInt operator%(const BigInt&, const BigInt&); // +

BigInt operator^(const BigInt&, const BigInt&); // +
BigInt operator&(const BigInt&, const BigInt&); // +
BigInt operator|(const BigInt&, const BigInt&); // +


std::ostream& operator<<(std::ostream& o, const BigInt& i); // +
*/
