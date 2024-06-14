#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    struct Tree *LSon;
    struct Tree *RSon;
    int Value;
} Tree;

void Shuffle(int *arr, int n)
{
    for (int i=0; i < n; ++i)
    {
        int k = rand() % i;
        int p = arr[i];
        arr[i] = arr[k];
        arr[k] = p;
    }
}

void AvalanceOutput(Tree *MTree, FILE *fout)
{
    if (MTree == NULL)
        return;
    AvalanceOutput(MTree->LSon, fout);
    fwrite(&MTree->Value, 4, 1, fout);
    AvalanceOutput(MTree->RSon, fout);
}

void main()
{
    FILE *fin = fopen("input.bin", "rb");
    FILE *fout = fopen("output.bin", "wb");
    int n, i, way = 0;
    fread(&n, 4, 1, fin);
    int *arr = (int*)malloc(4 * n);
    fread(arr, 4, n, fin);
    Shuffle(arr, n);
    Tree *MainTree = NULL;

    for (i = 0; i < n; i++)
    {
        Tree *Branch;
        Branch = malloc(sizeof(Tree));
        Branch->LSon = NULL;
        Branch->RSon = NULL;
        Branch->Value = arr[i];
        Tree *Mimic;
        Mimic = MainTree;
        while(1)
        {
            if (MainTree == NULL)
            {
                MainTree = Branch;
                break;
            }

            if (Branch->Value < Mimic->Value)
            {
                if (Mimic->LSon == NULL)
                {
                    Mimic->LSon = Branch;
                    break;
                }
                Mimic = Mimic->LSon;
            }
            else
            {
                if (Branch->Value > Mimic->Value)
                {
                    if (Mimic->RSon == NULL)
                    {
                        Mimic->RSon = Branch;
                        break;
                    }
                    Mimic = Mimic->RSon;
                }
                else
                {
                    if (way == 0)
                    {
                        way = rand() % 2;
                        if (Mimic->LSon == NULL)
                        {
                            Mimic->LSon = Branch;
                            break;
                        }
                        Mimic = Mimic->LSon;
                    }
                    else
                    {
                        way = rand() % 2;
                        if (Mimic->RSon == NULL)
                        {
                            Mimic->RSon = Branch;
                            break;
                        }
                        Mimic = Mimic->RSon;
                    }
                }
            }
        }
    }
    AvalanceOutput(MainTree, fout);
    fclose(fin);
    fclose(fout);
}
