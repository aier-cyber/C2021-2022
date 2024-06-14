#include <stdio.h>
typedef union _tmp
{
    char byte[3];
    int num;
} tmp;
void swap (tmp *arr, int i, int j)
{
    char p;
    p = arr->byte[j];
    arr->byte[j] = arr->byte[i];
    arr->byte[i] = p;
}
void main()
{
    FILE *Fin = fopen("input.bin", "rb");
    FILE *Fout = fopen("output.bin", "wb");
    tmp axx;
    fread(axx.byte, sizeof(char), 4, Fin);
    int b;
    int n;
    if (axx.num > 10000)
    {
        swap(&axx, 0, 3);
        swap(&axx, 1, 2);
        n = axx.num;
        b = 1;
    }
    else
    {
        n = axx.num;
        b = 0;
    }
    tmp sum;
    sum.num = 0;
    for (int i=0; i < n; ++i)
    {
        fread(axx.byte, sizeof(char), 4, Fin);
        if (b == 1)
        {
            swap(&axx, 0, 3);
            swap(&axx, 1, 2);
        }
        sum.num = sum.num + axx.num;
    }
    if (b == 1)
    {
        swap(&sum, 0, 3);
        swap(&sum, 1, 2);
    }
    fwrite(&sum.num, sizeof(int), 1, Fout);
    fclose(Fin);
    fclose(Fout);
}
