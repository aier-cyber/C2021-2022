#include <stdio.h>
#include <string.h>
typedef struct list_s {
    char name[20];
    long long int memory;
    long long int created;
    long long int modified;
} list;

list all[1000];

void swap (list* a, list* b)
{
    list mimc;
    mimc.created = a->created;
    mimc.memory = a->memory;
    strcpy(mimc.name, a->name);
    mimc.modified = a->modified;
    a->created = b->created;
    a->memory = b->memory;
    a->modified = b->modified;
    strcpy(a->name, b->name);
    b->created = mimc.created;
    b->memory = mimc.memory;
    b->modified = mimc.modified;
    strcpy(b->name, mimc.name);
}

int compare (list a, list b)
{
    int j;
    for (j = 0; j < 20; j++)
    {
        if (a.name[j] > b.name[j])
            return 1;
    }
    return 0;
}
int main()
{
    FILE *fin = fopen ("input.bin", "rb");
    FILE *fout = fopen ("output.bin", "wb");
    long long int memor, modif, creat, aTime, bTime;
    char isDirect, isHid;
    char name[20];
    int n, i, k, j, l;
    char zero;
    zero = 1;
    k = 0;
    fread(&n, 4, 1, fin);
    fread(&aTime, 8, 1, fin);
    fread(&bTime, 8, 1, fin);
    for (i = 0; i < n; i++)
    {
        fread(name, 20, 1, fin);
        fread(&memor, 8, 1, fin);
        fread(&isDirect, 1, 1, fin);
        fread(&creat, 8, 1, fin);
        fread(&modif, 8, 1, fin);
        fread(&isHid, 1, 1, fin);

        if ((isDirect == 0) && (isHid == 0) && (creat >= aTime) && (modif <= bTime))
        {
            all[k].created = creat;
            all[k].memory = memor;
            all[k].modified = modif;
            strcpy(all[k].name, name);
            k++;
        }
    }
    for (i = 0; i < k; i++)
    {
        for (j = i+1; j < k; j++)
        {
            for (l = 0; l < 20; l++)
            {
                if (all[i].name[l] < all[j].name[l])
                {
                    break;
                }
                else
                {
                    if (all[i].name[l] == all[j].name[l])
                    {
                        continue;
                    }
                    else
                    {
                        swap(&all[i], &all[j]);
                    }
                }
            }
        }
    }
    for (i = 0; i < k; i++)
    {
        fwrite(all[i].name, 20, 1, fout);
        fwrite(&all[i].memory, 8, 1, fout);
        fwrite(&zero, 1, 1, fout);
        fwrite(&all[i].created, 8, 1, fout);
        fwrite(&all[i].modified, 8, 1, fout);
        fwrite(&zero, 1, 1, fout);
    }
    fclose(fin);
    fclose(fout);
}
