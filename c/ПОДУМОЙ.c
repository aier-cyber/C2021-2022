#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char bitword;
void bitsetZero (bitword *arr , int num){
for (int i = 0; i < num; i++)
{
    arr[i] = '0';
}
}
int bitsetGet ( const bitword *arr , int idx ){
if (arr[idx] == '1')
    return 1;
else
    return 0;
}
void bitsetSet ( bitword * arr , int idx , int newval )
{
    if (newval == 0)
        arr[idx] = '0';
    else
        arr[idx] = '1';
}
int bitsetAny ( const bitword * arr , int left , int right ){
    for (int i = left; i < right; i++)
        if (arr[i] == '1')
        return 1;
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    bitword * all;
    all = (char*)malloc(0);
    /*int  t, n, num, val, isDef;
    scanf("%d", &n);
    isDef = 0;
    while (n > 0)
    {
        scanf("%d", &t);
        if (t == 0)
        {
            if (isDef == 1)
                free(all);
            scanf("%d", &num);
            all = (char*)malloc(num);
            bitsetZero(all, num);
            isDef = 1;
        }
        if (t == 1)
        {
            scanf("%d", &num);
            printf("%d\n", bitsetGet(all, num));
        }
        if (t == 2)
        {
            scanf("%d %d", &num, &val);
            bitsetSet(all, num, val);
        }
        if (t == 3)
        {
            scanf("%d %d", &num, &val);
            if (bitsetAny(all, num, val) == 1)
            {
                printf("some\n");
            }
            else
            {
                printf("none\n");
            }
        }
        n--;
    }*/
    return 0;
}
