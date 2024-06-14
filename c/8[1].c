#include <stdio.h>
#include <math.h>
typedef union tmp
{
char byte[7];
int a[2];
} tmp;
void main()
{
    FILE *Fin = fopen ("input.bin", "rb");
    FILE *Fout = fopen ("output.bin", "wb");
    tmp xoxox;
    long long int p;
    for (int i=0; i <=7; ++i)
    {
        fread(&xoxox.byte[i], sizeof(char), 1, Fin);
    }
    p = (long long)xoxox.a[0]+(long long)xoxox.a[1];
    p = floor((long long)p/2);
    int a = (int)p;
    fwrite(&a, sizeof(int), 1, Fout);
    fclose(Fin);
    fclose(Fout);
}
