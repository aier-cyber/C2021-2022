#include <stdio.h>
#include <stdlib.h>
typedef struct p_Node
{
    struct p_Node *low, *high;
    int value;
} Node;
void random_shuffle(int *arr, int n)
{
    for (int i=0; i < n; ++i)
    {
        int k = rand() % (i+1);
        int p = arr[i];
        arr[i] = arr[k];
        arr[k] = p;
    }
}
void add(int x, Node* *p, Node *nd)
{
    if (!(*p))
    {
        (*p) = nd;
        return;
    }
    Node *s = *p;
    while (1)
    {
        int rnd = rand() % 2;

        if ((s->value > x || (s->value == x && rnd == 1)) && s->low == NULL)
        {
            s->low = nd;
            return;
        }
        else if ((s->value < x || (s->value == x && rnd == 0)) && s->high == NULL)
        {
            s->high = nd;
            return;
        }
        else if (s->value > x || (s->value == x && rnd == 1))
        {
            s = s->low;
        }
        else if (s->value < x || (s->value == x && rnd == 0))
        {
            s = s->high;
        }
    }
}
void extruct(Node *poof, FILE *F)
{
    if (poof == NULL)
        return;
    extruct(poof->low, F);
    fwrite(&poof->value, sizeof(int), 1, F);
    extruct(poof->high, F);
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
    random_shuffle(arr, n);
    Node *poof = NULL;
    for (int i=0; i < n; ++i)
    {
        Node *node;
        node = malloc(sizeof(Node));
        node->high = NULL;
        node->low = NULL;
        node->value = arr[i];
        add(arr[i], &poof, node);
    }
    extruct(poof, Fout);
}
