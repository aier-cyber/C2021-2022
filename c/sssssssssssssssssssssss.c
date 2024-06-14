#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List
{
    char **arr;
    int size;
} list;
void main()
{
    int n;
    scanf("%d", &n);
    list *a;
    a = calloc(sizeof(list), 1000001);
    int key;
    char string[8];
    for (int i=0; i < n; ++i)
    {
        scanf("%d %s", &key, string);
        if (a[key].size == 0)
        {
            a[key].arr = calloc(sizeof(char*), 1);
            a[key].arr[0] = malloc(strlen(string) + 1);
            strcpy(a[key].arr[0], string);
            a[key].size = 1;
        }
        else
        {
            a[key].arr = realloc(a[key].arr, sizeof(char*) * (a[key].size + 1));
            a[key].arr[a[key].size] = malloc(strlen(string) + 1);
            strcpy(a[key].arr[a[key].size], string);
            ++a[key].size;
        }
    }

    for (int i=0; i < 1000001; ++i)
    {
        for (int j=0; j < a[i].size; ++j)
        {
            printf("%d %s\n", i, a[i].arr[j]);
        }
    }
}
