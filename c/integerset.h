#ifndef anyname
#define anyname

typedef struct IntegerSet_s{
    int* arr;
    int msize;
} IntegerSet;


int IsAllDif(int* arr, int msize);


IntegerSet* CreateSet(int* arr, int amount);


int IsInSet(IntegerSet* all, int key);
#endif
