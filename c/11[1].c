#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _tmp
{
    struct _tmp *next;
    int value;
} tmp;

typedef union _fitc
{
    unsigned value;
    unsigned char byte[4];
} fitc;
unsigned jenkins(char *key, size_t len)
{
    unsigned hash, i;
    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    double fn = clock();

    return hash;
}

void main()
{
    FILE *Fin = fopen("input.bin", "rb");
    FILE *Fout = fopen("output.bin", "wb");
    int n;
    fread(&n, sizeof(int), 1, Fin);
    int *arr;
    arr = (int*)malloc(sizeof(int) * n);
    fread(arr, sizeof(int), n, Fin);
    tmp **hash_table;
    hash_table = malloc(sizeof(struct _tmp) * n);

    for (int i=0; i < n; ++i)
    {
        hash_table[i] = NULL;
    }
    int unik = 0;
    for (int i=0; i < n; ++i)
    {
        int poof = 1;
        fitc x;
        x.value = arr[i];
        int idx = jenkins(x.byte, 4) % n;
        if (hash_table[idx])
        {
            tmp *p = hash_table[idx];
            if (p->value == arr[i])
                continue;
            for(; p->next != NULL; p = p->next)
            {
                if (p->next->value == arr[i])
                {
                    poof = 0;
                    break;
                }
            }
            if (poof == 0)
                continue;
            tmp *s;
            s = malloc(sizeof(struct _tmp));
            s->value = arr[i];
            s->next = NULL;
            p->next = s;
            ++unik;
        }
        else
        {
            hash_table[idx] = malloc(sizeof(tmp));
            hash_table[idx]->value = arr[i];
            hash_table[idx]->next = NULL;
            ++unik;
        }
    }
    fwrite(&unik, sizeof(int), 1, Fout);
    for (int i=0; i < n; ++i)
    {
        fitc x;
        x.value = arr[i];
        int idx = jenkins(x.byte, 4) % n;
        tmp *p;
        for (p = hash_table[idx]; p != NULL; p = p->next)
        {
            if (p->value == arr[i])
            {
                fwrite(&p->value, sizeof(int), 1, Fout);
                p->value = 2000000000;
                break;
            }
        }
    }
}
