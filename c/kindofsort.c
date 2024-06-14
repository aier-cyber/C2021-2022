#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct List_s
{
    char str[9];
    int c;
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
    scanf("%d %s", &arr[i].c, arr[i].str);
    arr[i].u = i;
    for (j=0; j<i; j++)
    if (arr[i].c<arr[j].c)
        {
        savior = arr[i].c;
        arr[i].c=arr[j].c;
        arr[j].c=savior;
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
            if (arr[i].c==arr[j].c)
                if (arr[i].u<arr[j].u)
                {
        savior = arr[i].c;
        arr[i].c=arr[j].c;
        arr[j].c=savior;
        strcpy(saviorr, arr[i].str);
        strcpy(arr[i].str, arr[j].str);
        strcpy(arr[j].str, saviorr);
                }
    for (i=0; i<n; ++i)
        printf("%d %s\n", arr[i].c, arr[i].str);
}
