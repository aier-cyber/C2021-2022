#include <stdio.h>
typedef struct LongNum_s {
int len ; //сколько цифр в числе
int arr [500]; //массив десятичных цифр числа
} LongNum;
void FibCalc(const LongNum *arr, int *n)
{

}
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
LongNum AdvNum[2000];
int n;
--n;
scanf("%d", &n);
FibCalc(&AdvNum[0], &n);
return 0;
}
