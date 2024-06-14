#include "BigIntChar.h"

void BigInt::extend(){
    this->memSize += 8;
    char* mimic = new char[this->memSize];
    for (int i = 0; i < this->mLen; i++){
        mimic[i] = this->arr[i];
    }
    delete this->arr;
    this->arr = new char[this->memSize];
    for (int i = 0; i < this->mLen; i++){
        this->arr[i] = mimic[i];
    }
    delete mimic;
}

char* BigInt::getBigInt() const{
    if (this->isNeg){
        char* mimic = new char[this->mLen+2];
        mimic[0] = '-';
        for(int i = 1; i < this->mLen+1; i++){
            mimic[i] = this->arr[mLen-i]+48;
        }
        mimic[this->mLen+1] = '\0';
        return mimic;
    }
    else{
        char* mimic = new char[this->mLen+1];
        for(int i = 0; i < this->mLen; i++){
            mimic[i] = this->arr[mLen-i-1]+48;
        }
        mimic[this->mLen] = '\0';
        return mimic;
    }
}
/****/
/****/
std::ostream& operator<<(std::ostream& o, const BigInt& i){
    o << std::string(i.getBigInt());
    return o;
}

BigInt::BigInt(){
}

BigInt::BigInt(int x){
    if (x == 0){
        this->mLen = 1;
        this->arr[0] = 0;
    }
    else{
        if (x < 0){
            x = -x;
            this->isNeg = 1;
            while(x != 0){
                if (this->mLen == this-> memSize){
                    this->extend();
                }
                this->arr[this->mLen] = x%10;
                this->mLen += 1;
                x /= 10;
            }
        }
        else{
            while(x != 0){
                if (this->mLen == this-> memSize){
                    this->extend();
                }
                this->arr[this->mLen] = x%10;
                this->mLen += 1;
                x /= 10;
            }
        }
    }
}

BigInt::BigInt(std::string bi){
    int i;
    if (bi[0] == '-')
        {for(i = 1; i < bi.length(); i++){
                if (isdigit(bi[i])){}
                else{ break; }
        }
        if (i == bi.length()){
            this->isNeg = 1;
            this->memSize = 8;
            this->mLen = 0;
            for(i = 1; i < bi.length(); i++){
                if (i == this->memSize){
                    this->extend();
                }
                this->arr[i-1] = bi[bi.length()-i]-48;
                this->mLen += 1;
            }
        }
        else{
            throw std::invalid_argument("Error: non-digit value in string parameter!");
        }

    }
    else{
        for(i = 0; i < bi.length(); i++){
                if (isdigit(bi[i])){}
                else{ break; }
        }
        if (i == bi.length()){
            this->isNeg = 0;
            this->memSize = 8;
            this->mLen = 0;
            for(i = 0; i < bi.length(); i++){
                if (i == this->memSize){
                    this->extend();
                }
                this->arr[i] = bi[bi.length()-1-i]-48;
                this->mLen += 1;
            }
        }
        else{
            throw std::invalid_argument("Error: non-digit value in string parameter!");
        }
    }
}

BigInt::BigInt(const BigInt& mim){
    strcpy(this->arr, mim.arr);
    this->isNeg = mim.isNeg;
    this->memSize = mim.memSize;
    this->mLen = mim.mLen;
}

BigInt::~BigInt(){
    delete this->arr;
}

BigInt& BigInt::operator=(const BigInt& mim){
    for (int i = 0; i < mim.mLen; i++){
        this->arr[i] = mim.arr[i];
    }
    this->isNeg = mim.isNeg;
    this->memSize = mim.memSize;
    this->mLen = mim.mLen;
    return *this;
}


size_t BigInt::size() const{
    return this->mLen;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    BigInt b(0);
    BigInt c(2);
    b = c;
    BigInt d("-123");
    b = d;
    std::cout << b << std::endl;
    std::cout << d << std::endl;
    return 0;
}

