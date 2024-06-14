#include <stdio.h>
void main()
{
    FILE *fin = fopen ("input.bin", "rb");
    FILE *fout = fopen ("output.bin", "wb");
    int a, b;
    long long int c;
    fread(&a, sizeof(int), 1, fin);
    fread(&b, sizeof(int), 1, fin);
    c = (long long int)a + (long long int)b;
    c = c >> 1;
    fwrite(&c, 4, 1, fout);
    fclose(fin);
    fclose(fout);
}
