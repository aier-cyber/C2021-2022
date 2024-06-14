#include <stdio.h>
#include <stdlib.h>
typedef unsigned int bitword;
int orCreator (int degree){
    int acc = 1;
    for (int i = 0; i < degree; i++)
        acc *= 2;
    return acc;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    printf("%d", sizeof(bitword));
    return 0;
}
