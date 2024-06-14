#include <stdio.h>
#include <string.h>
int convert(char c)
{
    if (c == '0') return 0; if (c == '1') return 1; if (c == '2') return 2;
    if (c == '3') return 3; if (c == '4') return 4; if (c == '5') return 5;
    if (c == '6') return 6; if (c == '7') return 7; if (c == '8') return 8;
    if (c == '9') return 9;
}
typedef struct LongNum_s {
int len ; //сколько цифр в числе
int arr [1000000]; //массив десятичных цифр числа
} LongNum ;
LongNum all[3];
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int i, c, mimi, mimc, overflow, curr;
char n[1001];
all[1].len = 0;
all[2].len = 0;

scanf("%s", &n);
i=strlen(n);
all[1].len = i;
for (c = 0; c<i; c++)
    all[1].arr[c] = convert(n[i-1-c]);

scanf("%s", &n);
i=strlen(n);
all[2].len = i;
for (c = 0; c<i; c++)
    all[2].arr[c] = convert(n[i-1-c]);
/*
for (c = 0; c<all[1].len; c++)
    printf("%d", all[1].arr[c]);
printf("\n");
for (c = 0; c<all[2].len; c++)
    printf("%d", all[2].arr[c]);
printf("\n");
for (c = 0; c< 1000000; c++)
    all[0].arr[c] = 0;
*/
for (i = 0; i<all[1].len; i++)
{
    overflow = 0;
    for (c = 0; c<all[2].len; c++)
    {
        curr = all[0].arr[c+i];
        all[0].arr[c+i] = (curr + all[1].arr[i]*all[2].arr[c] + overflow) % 10;
        overflow = (curr + all[1].arr[i]*all[2].arr[c]+overflow) / 10;
    }
    if (overflow != 0)
        all[0].arr[c+i] = overflow;
}

if (all[0].arr[all[1].len+all[2].len-1] == 0)
    all[0].len = all[1].len+all[2].len-1;
else
    all[0].len = all[1].len+all[2].len;

for (i = all[0].len-1; i>=0; i--)
    printf("%d", all[0].arr[i]);
return 0;
}
