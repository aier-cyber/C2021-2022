#include <stdio.h>
union trHelper {
char bytes[4];
int mima;
};
void ChangeEndian(int* a){
char mim;
union trHelper arr;
arr.mima = *a;
mim = arr.bytes[0];
arr.bytes[0] = arr.bytes[3];
arr.bytes[3] = mim;
mim = arr.bytes[1];
arr.bytes[1] = arr.bytes[2];
arr.bytes[2] = mim;
*a = arr.mima;
}
void main()
{
    FILE *fin = fopen ("input.bin", "rb");
    FILE *fout = fopen ("output.bin", "wb");
    int n, a, b, i;
    a = 0;
    fread(&n, 4, 1, fin);
    if (n <= 10000)
    {
        for (i = 0; i < n; i++)
        {
            fread(&b, 4, 1, fin);
            a = a + b;
        }
        fwrite(&a, 4, 1, fout);
    }
    else
    {
        ChangeEndian(&n);
        for (i = 0; i < n; i++)
        {
            fread(&b, 4, 1, fin);
            ChangeEndian(&b);
            a = a + b;
        }
        ChangeEndian(&a);
        fwrite(&a, 4, 1, fout);
    }
    fclose(fin);
    fclose(fout);
}
