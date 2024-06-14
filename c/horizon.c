#include <stdio.h>
#include <stdlib.h>
//partitions array a[0..n-1] into two subarrays, returning value k
// the subarray a[0..k-1] must have all elements <= pivot
// the subarray a[k..n-1] must have all elements >= pivot
int partition (int *a , int n , int pivot ){
    int i, k, j, swapper, control;
    control = 0;
    k = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == pivot)
        {
            control++;
        }
    }
    control /= 2;
    for (i = 0; i < n; i++, k++)
    {
        j = i+1;
        if (control == 0)
        {
            if (a[i] >= pivot)
            {
                while ((j < n) && (a[j] >= pivot))
                {
                    j++;
                }
                if (j >= n)
                {
                    break;
                }
                swapper = a[i];
                a[i] = a[j];
                a[j] = swapper;
            }
        }
        else
        {
            if (a[i] > pivot)
            {
                while ((j < n) && (a[j] > pivot))
                {
                    j++;
                }
                if (j >= n)
                {
                    break;
                }
                if (a[j] == pivot)
                    control--;
                swapper = a[i];
                a[i] = a[j];
                a[j] = swapper;
            }
            else
            {
            if (a[i] == pivot)
                control--;
            }
        }
    }
        while (control > 0)
        {
            j = k;
            if (a[j] == pivot)
            {
                control--;
                k++;
                continue;
            }
            while ((j < n) && (a[j] != pivot))
                j++;
            swapper = a[k];
            a[k] = a[j];
            a[j] = swapper;
            control--;
        }
    return k;
}

int arr[1000000];
int main()
{
    FILE *fin = fopen ("input.txt", "rb");
    FILE *fout = fopen ("output.txt", "wb");
    int i, pi, n, newk;
    fread(&n, 4, 1, fin);
    fread(&pi, 4, 1, fin);
    for (i = 0; i < n; i++)
    {
        fread(&arr[i], 4, 1, fin);
    }
    newk = partition(arr, n, pi);

    fwrite(&newk, 4, 1, fout);

    for (i = 0; i < n; i++)
    {
        fwrite(&arr[i], 4, 1, fout);
    }
    fclose(fin);
    fclose(fout);
}
