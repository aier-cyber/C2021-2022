#include <stdio.h>

typedef struct LongNum_s {
int len ; //сколько цифр в числе
int arr [3000]; //массив десятичных цифр числа
} LongNum ;

void AdvMult(int *arm, int *lem, int mulval)
{
 int curr, overflow, hep, i;
 for(i = 0; ; i++)
 {
     overflow += (mulval * *(arm+i));
     *(arm+i)=overflow % 10;
     overflow /= 10;

 }
}
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
struct LongNum_s OneNum;
for (int u = 0; u<3000; u++)
    OneNum.arr[u] = 0;
OneNum.len = 1;
OneNum.arr[0] = 1;
int n;
scanf("%d", &n);


return 0;
}
