#include <stdio.h>
#include <string.h>
class BigInt {
public:
    BigInt();
    BigInt(int);
private:
        int mLen;
        int memSize;
        int isNeg;
        char* arr = new char[8];
        void extend();
};

/*
void BigInt::extend()
{
    char* mimic = new char[this->memSize+8];
    strcpy(mimic, this->arr);
    delete this-arr;
    this->arr = mimic;
}

*/
