#include <stdio.h>
int arr[21];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long double cls;
    long double ld = 44;
    int i, c, changer;
    ld /= 3;
    for (i = 20; i > 0; i--){
        c = i;
        cls = ld;
        while (c > 1){
            cls *= 10.0;
            changer = (int)cls;
            cls = cls - (long double)changer;
            c--;
        }
        changer = (int)cls;
        cls = cls - (long double)changer;
        cls *= 10;
        arr[i] = (int)cls;
    }
    cls = ld;
    printf("%d.", (int)ld);
    for (i = 1; i < 21; i++)
        printf("%d", arr[i]);
return 0;
}
