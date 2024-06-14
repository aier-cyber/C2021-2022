#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List_s
{
    char str[8];
    int next;
} list;

void main()
{
    int t;
    scanf("%d", &t);

    list *arr;
    int n, f ,q;
    int oper, id;
    char string[8];

    for (int i=0; i < t; ++i)
    {
        scanf("%d%d%d", &n, &f, &q);
        arr = (list*)malloc((n+q)*sizeof(list));

        int cnt = 0;
        for (; cnt < n; ++cnt)
            scanf("%s %d", arr[cnt].str, &arr[cnt].next);

        for (int j=0; j < q; ++j)
        {
            scanf("%d", &oper);
            if (oper == 0)
            {
                scanf("%d %s", &id, string);
                if (id == -1)
                {
                    printf("%d\n", cnt);
                    int v = cnt;
                    strcpy(arr[v].str, string);
                    arr[v].next = f;
                    f = v;
                    cnt++;
                }
                else
                {
                    printf("%d\n", cnt);
                    int v = cnt;
                    strcpy(arr[v].str, string);
                    arr[v].next = arr[id].next;
                    arr[id].next = v;
                    cnt++;
                }
            }

            else if (oper == 1)
            {
                scanf("%d", &id);
                if (id == -1)
                {
                    printf("%s\n", arr[f].str);
                    f = arr[f].next;
                }
                else
                {
                    int v = arr[id].next;
                    arr[id].next = arr[v].next;
                    printf("%s\n", arr[v].str);
                }
            }
        }
        printf("===\n");

        for (int jj=0; jj < cnt; ++jj)
        {
            if (f == -1)
                break;
            printf("%s\n", arr[f].str);
            f = arr[f].next;
        }
        printf("===\n");

        free(arr);
    }
}
