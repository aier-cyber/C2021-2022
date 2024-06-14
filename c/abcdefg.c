#include <stdio.h>
typedef union _tmp
{
    char byte[3];
    int k;
} tmp;
void main()
{
    FILE *Fin = fopen("input.bin", "rb");
    FILE *Fout = fopen("output.bin", "wb");
    tmp *arr;
    fread(arr->byte, sizeof(char), 4, Fin);
    int a,b;
    char mask;
    if (arr->k > 10000)
    {
        mask = arr->byte[0];
        arr->byte[0]=arr->byte[3];
        arr->byte[3]=mask;
        mask = arr->byte[1];
        arr->byte[1]=arr->byte[2];
        arr->byte[2]=mask;
        b=1;
    }
    else b=0;
    a=arr->k;
    tmp *sum;
    sum->k=0;
    for (int i = 0 ; i < a ; + + i)
    {
        fread(arr->byte, sizeof(char), 4, Fin);
        if (b==1)
        {
        mask = arr->byte[0];
        arr->byte[0]=arr->byte[3];
        arr->byte[3]=mask;
        mask = arr->byte[1];
        arr->byte[1]=arr->byte[2];
        arr->byte[2]=mask;
        }
        sum->k=sum->k+arr->k;
    }
    if (b==1)
    {
        mask = sum->byte[0];
        sum->byte[0] =sum->byte[3];
        sum->byte[3]=mask;
        mask=sum->byte[1];
        sum->byte[1]=sum->byte[2];
        sum->byte[2]=mask;
    }
    fwrite(&sum->k, sizeof(int), 1, Fout);
    fclose(Fin);
    fclose(Fout);
}
