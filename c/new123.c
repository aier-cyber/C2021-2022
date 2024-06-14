#include <stdio.h>
#include <stdlib.h>

void SiftUp (int Id, int* heap)
{
    if (Id == 0)
        return;
    int FatherId = (Id - 1) / 2;
    if (heap[Id] < heap[FatherId])
    {
        int mimic;
        mimic = heap[Id];
        heap[Id] = heap[FatherId];
        heap[FatherId] = mimic;
        SiftUp(FatherId, heap);
    }
}

void SiftDown (int Id, int* heap, int edge)
{
    if (2*Id + 1 > edge)
        return;
    if (2*Id + 1 == edge)
    {
        if (heap[2*Id+1] < heap[Id])
        {
            int mimic = heap[2*Id+1];
            heap[2*Id+1] = heap[Id];
            heap[Id] = mimic;
        }
    }
    else
    {
        if (heap[2*Id+1] < heap[2*Id+2])
        {
            if (heap[2*Id+1] < heap[Id])
            {
                int mimic = heap[2*Id+1];
                heap[2*Id+1] = heap[Id];
                heap[Id] = mimic; // типо свап :|
                SiftDown(2*Id+1, heap, edge);
            }
        }
        else
        {
            if (heap[2*Id+2] < heap[Id])
            {
                int mimic = heap[2*Id+2];
                heap[2*Id+2] = heap[Id];
                heap[Id] = mimic; // :P
                SiftDown(2*Id+2, heap, edge);
            }
        }
    }
}


int main()
{
    FILE *fin = fopen ("input.bin", "rb");
    FILE *fout = fopen ("output.bin", "wb");
    int n, k, i, Id;
    fread(&n, 4, 1, fin);
    int *arr = (int*)malloc(4 * n);
    fread(arr, 4, n, fin);
    int *heap = (int*)malloc(4 * n);
    for (k = 0; k < n; k++)
    {
        heap[k] = arr[k];
        SiftUp(k, heap);
    }
    i = n-1;
    for (k = 0; k < n; k++)
    {
        arr[k] = heap[0];
        fwrite(&arr[k], 4, 1, fout);
        heap[0] = heap[i];
        heap[i] = 2147483647;
        i--;
        SiftDown(0, heap, i);
    }
    return 0;
}
