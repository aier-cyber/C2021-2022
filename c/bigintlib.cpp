#include "bigintlib.h"
#include <string.h>
#include <stdio.h>

BigInt::BigInt(){
    this->mLen = 0;
    this->memSize = 8;
    this->isNeg = 0;
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
                this->arr[this->mLen] = char(x%10);
                this->mLen += 1;
                x /= 10;
            }
        }
        else{
            while(x != 0){
                if (this->mLen == this-> memSize){
                    this->extend();
                }
                this->arr[this->mLen] = char(x%10);
                this->mLen += 1;
                x /= 10;
            }
        }
    }
}
void BigInt::extend(){
    char* mimic = new char[this->memSize+8];
    strcpy(mimic, this->arr);
    delete this->arr;
    this->arr = mimic;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    BigInt b;
    b = 108;
    printf("%s", b->arr);
    return 0;
}

