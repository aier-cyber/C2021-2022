#include <stdlib.h>
#include <stddef.h>
#include "integerset.h"
int cmp(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}
IntegerSet* CreateSet(int* arr, int amount){
    IntegerSet* ph;
    int* res;
    if (amount != 0){
    int i;
    //
    res =(int*) malloc (amount*4);
    for (i = 0; i < amount; i++){
        res[i] = arr[i];
    }
    qsort(res, amount, 4, cmp);
    for (i = 0; i < (amount-1); i++){
        if (res[i] == res[i+1]){ //printf
            return 0;
        }
    }
    }//
    ph = (IntegerSet*) malloc (sizeof(IntegerSet));
    ph->arr = res;
    ph->msize = amount;
    return ph;
}
int IsInSet(IntegerSet* all, int key){
    if (all == 0){
        return 0;
    }
    else{
        if (bsearch(&key, all->arr, all->msize, 4, cmp) != 0){
            return 1;
        }
    }
    return 0;
}
