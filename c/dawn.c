#include <stdio.h>
#include <stdlib.h>
int arr[1000000];
int ans[1000000];
//partitions array a[0..n-1] into two subarrays, returning value k
// the subarray a[0..k-1] must have all elements <= pivot
// the subarray a[k..n-1] must have all elements >= pivot
int partition (int *a , int n , int pivot ){
    int i, k = 0, j = (n-1), swapper, control = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] < pivot)
        {
            ans[k] = a[i];
            k++;
        }
        if (a[i] == pivot)
        {
            if (control == 0)
            {
                ans[k] = a[i];
                k++;
                control++;
            }
            else
            {
                ans[j] = a[i];
                j--;
                control--;
            }
        }
        if (a[i] > pivot)
        {
            ans[j] = a[i];
            j--;
        }
    }
    return k;
}
int main()
{
    FILE *fin = fopen ("input.bin", "rb");
    FILE *fout = fopen ("output.bin", "wb");
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
        fwrite(&ans[i], 4, 1, fout);
    }
    fclose(fin);
    fclose(fout);
}
