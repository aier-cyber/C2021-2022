#include <stdio.h>
#include <math.h>

typedef union _tmp
{
    char byte[8];
    int num[2];
} tmp;

void main()
{
    FILE *Fin = fopen("input.bin", "rb");
    FILE *Fout = fopen("output.bin", "wb");

    tmp arr;

    long long int ans;
    for (int i=0; i < 8; ++i)
    {
        fread(&arr.byte[i], sizeof(char), 1, Fin);
    }
    ans = (long long)arr.num[0] + (long long)arr.num[1];
    ans = floor((long double)ans / 2);
    int a = (int)ans;
    fwrite(&a, sizeof(int), 1, Fout);
    fclose(Fin);
    fclose(Fout);
}
