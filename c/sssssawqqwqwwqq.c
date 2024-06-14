#include <stdio.h>
#include <string.h>
typedef struct Label_s {
char name [16];
int age;
} Label;

typedef struct NameStats_s {
int cntTotal;
int cntLong;
} NameStats;

typedef struct AgeStats_s {
int cntTotal;
int cntAdults;
int cntKids;
} AgeStats;
Label names[1000];
void calcStats (const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges)
{
    oNames->cntTotal=0;
    oNames->cntLong=0;
    oAges->cntTotal=0;
    oAges->cntAdults=0;
    oAges->cntKids=0;

    int counter,length;
    char stroka[25];
    for (counter=0; counter<cnt; counter++)
    {
        gets(stroka);
        sscanf(stroka,"%s %d", &arr[counter].name, &arr[counter].age);
        length = strlen(arr[counter].name);

        /*printf("вся строка: %s\n", stroka);
        printf("в ней переданы имя: %s и возраст: %d\n", arr[counter].name, arr[counter].age);
        printf("длинна имени: %d\n", length);
        printf("**беляшик)0)**\n");*/

        oNames->cntTotal++;
        oAges->cntTotal++;

        if (length > 10)
            oNames->cntLong++;

        if (arr[counter].age>=18)
            oAges->cntAdults++;

        if (arr[counter].age<14)
            oAges->cntKids++;
    }
   printf("names: total = %d\nnames: long = %d\nages: total = %d\nages: adult = %d\nages: kid = %d\n", oNames->cntTotal, oNames->cntLong, oAges->cntTotal, oAges->cntAdults, oAges->cntKids);
}
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int n;
char c;
scanf("%d", &n);
scanf("%c ", &c);
//printf("%c", c);
struct NameStats_s mimica;
struct AgeStats_s mimicb;
calcStats (&names[0], n, &mimica, &mimicb);
return 0;
}
