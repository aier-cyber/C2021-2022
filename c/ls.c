#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void* b){
return (*(int*)a - *(int*)b);
}
int farr[100000];
int sarr[100000];
int ans[100000];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k, i, j, mimic, counter;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &farr[i]);
    }
    qsort(farr, n, 4, comp);

    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &sarr[i]);
    }
    qsort(sarr, k, 4, comp);

    i = 0;
    j = 0;
    counter = 0;
    while ((i < n) && (j < k))
    {
        if (farr[i] < sarr[j])
        {
            ans[counter] = farr[i];
            counter++;
            mimic = farr[i];
            while (mimic == farr[i])
            {
                i++;
                if (i >= n)
                {
                    break;
                }
            }
            if(i >= n)
            {
                break;
            }
        }
        else
        {
            if (farr[i] > sarr[j])
            {
                ans[counter] = sarr[j];
                counter++;
                mimic = sarr[j];
                while (mimic == sarr[j])
                {
                    j++;
                    if (j >= k)
                    {
                        break;
                    }
                }
                if (j >= k)
                {
                    break;
                }
            }
            else
            {
                i++;
                j++;
            }
        }
    }
    while (i < n)
    {
        ans[counter] = farr[i];
        counter++;
        mimic = farr[i];
        while (mimic == farr[i])
        {
            i++;
            if (i >= n)
                break;
        }
    }
    while (j < k)
    {
        ans[counter] = sarr[j];
        counter++;
        mimic = sarr[j];
        while (mimic == sarr[j])
        {
            j++;
            if (j >= k)
                break;
        }
    }
    printf("%d\n", counter);
    for (i = 0; i < counter; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}
