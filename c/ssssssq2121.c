#include <stdio.h>
typedef struct DateTime_s {
int year, month, day;
int hours, minutes, seconds;
} DateTime;
DateTime carr[50000];
DateTime min (const DateTime* arr, int cnt)
{
    int key,i;
    key = 0;
    scanf("%d %d %d %d %d %d", &arr[0].year, &arr[0].month, &arr[0].day, &arr[0].hours, &arr[0].minutes, &arr[0].seconds);
    for (i=1; i<cnt; i++)
    {
    scanf("%d %d %d %d %d %d", &arr[i].year, &arr[i].month, &arr[i].day, &arr[i].hours, &arr[i].minutes, &arr[i].seconds);
        if (arr[i].year<arr[key].year)
        {
            key=i;
        }
        else
        {
        if (arr[i].year == arr[key].year)
        {
            if (arr[i].month<arr[key].month)
            {
                key=i;
            }
            else
            {
            if (arr[i].month == arr[key].month)
            {
            if (arr[i].day<arr[key].day)
            {
                key=i;
            }
            else
            {
            if (arr[i].day == arr[key].day)
            {
            if (arr[i].hours<arr[key].hours)
            {
                key=i;
            }
            else
            {
            if (arr[i].hours == arr[key].hours)
            {
            if (arr[i].minutes < arr[key].minutes)
            {
                key=i;
            }
            else
            {
            if (arr[i].minutes == arr[key].minutes)
            {
            if (arr[i].seconds<arr[key].seconds)
            {
                key=i;
            }
            }
            }
            }
            }
            }
            }
            }
            }
        }
        }
    }
    printf("%d %d %d %d %d %d", arr[key].year, arr[key].month, arr[key].day, arr[key].hours, arr[key].minutes, arr[key].seconds);
}
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int n;
scanf("%d", &n);
min (carr, n);
return 0;
}
