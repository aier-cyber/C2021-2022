#include <stdio.h>

typedef union _tmp
{
    char byte[4];
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
    tmp vol;
    fread(vol.byte, sizeof(char), 4, Fin);
    int ctrl;
    int n;
    if (vol.num > 10000)
    {
        swap(&vol, 0, 3);
        swap(&vol, 1, 2);
        n = vol.num;
        ctrl = 1;
    }
    else
    {
        n = vol.num;
        ctrl = 0;
    }

    tmp sum;
    sum.num = 0;
    for (int i=0; i < n; ++i)
    {
        fread(vol.byte, sizeof(char), 4, Fin);
        if (ctrl == 1)
        {
            swap(&vol, 0, 3);
            swap(&vol, 1, 2);
        }
        sum.num += vol.num;
    }
    if (ctrl == 1)
    {
        swap(&sum, 0, 3);
        swap(&sum, 1, 2);
    }
    fwrite(&sum.num, sizeof(int), 1, Fout);
    fclose(Fin);
    fclose(Fout);
}
