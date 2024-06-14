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
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 int tk, i;
 int N,F,Q,o;
 scanf("%d", &tk);
 list(*arr);
 int ic;
 char newE[10];

 for (i=1; i<=tk; i++)
 {
     scanf("%d %d %d", &N, &F, &Q);
     arr=(list*)malloc((N+Q)*sizeof(list));
     int y;
     for (y=0; y < N; y++)
         scanf("%s %d", arr[y].str, &arr[y].next);
     for (int j=0; j < Q; j++)
     {
         scanf("%d", &o);
         if (o == 0)
         {
             scanf("%d %s", &ic, newE);
             if (ic == -1)
             {
                    printf("%d\n", y);
                    int z = y;
                    strcpy(arr[z].str, newE);
                    arr[z].next = F;
                    F = z;
                    y++;
             }
             else
             {
                    printf("%d\n", y);
                    int z = y;
                    strcpy(arr[z].str, newE);
                    arr[z].next = arr[ic].next;
                    arr[ic].next = z;
                    y++;
             }
         }
         else
         {
             scanf("%d", &ic);
             if (ic==-1)
             {
                 printf("%s\n", arr[F].str);
                 F=arr[F].next;
             }
             else
             {
                 int z = arr[ic].next;
                 arr[ic].next = arr[z].next;
                 printf("%s\n", arr[z].str);
             }
         }
     }
     printf("===\n");
     for (int ijc = 0; ijc < y; ijc++)
     {
         if (F == -1)
            break;
         printf("%s\n", arr[F].str);
         F=arr[F].next;
     }
     printf("===\n");
     free(arr);
 }

}
