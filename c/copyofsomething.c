#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct List_s
{
    char str[9];
    long int c[10000];
    int u;
} list;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,t,i,savior,j;
    char saviorr[8];
    int k = 1;
    scanf("%d", &n);
    list *arr;
    arr = (list*)malloc((n+n)*sizeof(list));
    for(i=0; i<n; ++i)
    {
    scanf("%d %s", &arr->c[i], arr[i].str);
    arr[i].u = i;
    for (j=0; j<i; j++)
    if (arr->c[i]<arr->c[j])
        {
        savior = arr->c[i];
        arr->c[i]=arr->c[j];
        arr->c[j]=savior;
        strcpy(saviorr, arr[i].str);
        strcpy(arr[i].str, arr[j].str);
        strcpy(arr[j].str, saviorr);
        savior = arr[i].u;
        arr[i].u = arr[j].u;
        arr[j].u = savior;
        }
    }
    for(i=0; i<n; ++i)
        for(j=0; j<i; j++)
            if (arr->c[i]==arr->c[j])
                if (arr[i].u<arr[j].u)
                {
        savior = arr->c[i];
        arr->c[i]=arr->c[j];
        arr->c[j]=savior;
        strcpy(saviorr, arr[i].str);
        strcpy(arr[i].str, arr[j].str);
        strcpy(arr[j].str, saviorr);
                }
    for (i=0; i<n; ++i)
        printf("%d %s\n", arr->c[i], arr[i].str);
}
