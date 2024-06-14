#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int value;
    struct Node* next;
} Node;

//тип указателя на функцию, которую можно передавать как callback
typedef void (* callback )( void * ctx , int * value );
//здесь ctx –- это контекст, который передаётся в func первым аргументом
//последние два параметра задают массив, по элементам которого нужно пройтись
void arrayForeach ( void * ctx , callback func , int * arr , int n )
{
    for (int i = 0; i < n; i++)
    {
        func(ctx, &arr[i]);
    }
    printf("%d ", *((int* )ctx));
}

void nodeForeach ( void * ctx, callback func , Node * arr)
{
    for (Node* Mim = arr; Mim != NULL; Mim = Mim->next)
    {
        func(ctx, &Mim->value);
    }
    printf("%d", *((int* )ctx));
}

void evenFunc(void *ctx, int *value)
{
    if ((*value % 2) == 0)
    {
        *((int* )ctx) += *value;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k, i, an = 0;
    scanf("%d", &n);
    int *arr = (int*) malloc (4*n);
    struct Node Fst;
    Fst.next = NULL;
    Node* L = &Fst;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        arr[i] = k;
        L->value = k;
        if (i != n-1)
        {
            L->next = (Node* ) malloc(sizeof(Node));
            L = L->next;
            L->next = NULL;
        }
    }

    callback func;
    func = evenFunc;
    void *ctx;
    ctx = &an;
    arrayForeach(ctx, func, arr, n);
    *((int*)ctx) = 0;
    nodeForeach(ctx, func, &Fst);
    return 0;
}
