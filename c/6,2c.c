#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List_s
{
    char str[8];
    int next;
} list;

typedef main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t); //кол-во тестов

    list *arr;
    int n, f ,q;
    int oper, id;
    char string[8];

    for (int i=0; i < t; ++i)
    {
        scanf("%d%d%d", &n, &f, &q); //кол-во элементов, индекс первого элемента, кол-во операций
        arr = (list*)malloc((n+q)*sizeof(list));

        int cnt = 0;
        for (; cnt < n; ++cnt) //ввод элементов в массив
            scanf("%s %d", arr[cnt].str, &arr[cnt].next);

        for (int j=0; j < q; ++j) //исполнение операций
        {
            scanf("%d", &oper);
            if (oper == 0) //добавление элемента
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
                    //printf("-------\n");//
                    int v = cnt;
                    strcpy(arr[v].str, string);
                    //printf("arr[v].next(%d) = arr[id].next(%d)\n",arr[v].next, arr[id].next);//
                    arr[v].next = arr[id].next;
                    //printf("arr[id].next(%d) = v(%d)\n",arr[id].next, v);//
                    arr[id].next = v;
                    //printf("-------\n");//
                    cnt++;
                }
                /*
                int ff = f;
                for (int jj=0; jj < cnt; ++jj) //
                {//
                    if (f == -1)//
                        break;//
                    printf("%s--> ", arr[ff].str);//
                    ff = arr[ff].next;//
                }//
                printf("\n");*/
            }

            else if (oper == 1) //удаление элемента
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
                    /*
                    int ff = f;
                    for (int z=0; z < cnt; ++z)
                    {
                        if (arr[ff].next == id + 1)
                        {
                            arr[ff].next = arr[id+1].next;
                            printf("%s\n", arr[id+1].str);
                            break;
                        }
                        ff = arr[ff].next;
                    }*/
                }
            }
        }
        printf("===\n");

        for (int jj=0; jj < cnt; ++jj) //вывод элементов списка
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
