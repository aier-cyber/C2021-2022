#include <stdio.h>
#include <string.h>
#include <iostream>
#include <ctype.h>
#include <vector>

class BigInt {
public:
    char* getBigInt() const;

    BigInt();
    BigInt(int);
    BigInt(std::string); //
    BigInt(const BigInt&);
    ~BigInt();
    BigInt& operator=(const BigInt&);

    size_t size() const;
private:
    int mLen = 0;
    int memSize = 8;
    int isNeg = 0;
    char* arr = new char[8];
    void extend();
};

std::ostream& operator<<(std::ostream& o, const BigInt& i);
/*
void BigInt::extend()
{
    char* mimic = new char[this->memSize+8];
    strcpy(mimic, this->arr);
    delete this-arr;
    this->arr = mimic;
}

*/
