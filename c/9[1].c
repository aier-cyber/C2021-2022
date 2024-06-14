#include <stdio.h>
#include <stdlib.h>
int merge (const int *a, int ak, const int *b, int bk, int *res)
{
    int aId = 0, bId = 0, i;
    for (i=0; (aId != ak) && (bId != bk); i++)
    {
        if (a[aId] < b[bId])
        {
            res[i] = a[aId];
            aId++;
        }
        else
        {
            res[i] = b[bId];
            bId++;
        }
    }
    if (aId == ak)
    {
        for (i = i; bId != bk; bId++)
        {
            res[i] = b[bId];
            i++;
        }
    }
    else
    {
        for (i = i; aId != ak; aId++)
        {
            res[i] = a[aId];
            i++;
        }
    }

    return i;
}

void main()
{
    FILE *fin = fopen("input.txt", "rb");
    FILE *fout = fopen("output.txt", "wb");

    int n, m, i;
    fread(&n, 4, 1, fin);
    fread(&m, 4, 1, fin);
    int* farr;
    int* sarr;
    farr = (int*)malloc(4*n);
    sarr = (int*)malloc(4*m);

    for (i = 0; i < n; i++)
    {
        fread(&farr[i], 4, 1, fin);
    }

    for (i = 0; i < m; i++)
    {
        fread(&sarr[i], 4, 1, fin);
    }

    int *res;
    res = (int*)malloc(4*(n+m));

    int newi = merge(farr, n, sarr, m, res);
    for (i = 0; i < newi; i++)
    {
        fwrite(&res[i], 4, 1, fout);
    }
    fclose(fin);
    fclose(fout);
}
