#include <stdlib.h>
#include <stdio.h>
typedef unsigned int bitword;

void bitsetZero (bitword * arr, int num){
    int i;
    for (i = 0; i<= num; i++)
    {
    arr[i] = 0;
    }
}

int bitsetGet ( const bitword * arr , int idx )
{
    int answer;
    unsigned int x = idx%32;
    idx /= 32;
    x = arr[idx] & (1<<x);
    if (x != 0)
    {
        answer = 1;
    }
    else
    {
        answer = 0;
    }
    return answer;
}

void bitsetSet ( bitword * arr , int idx , int newval ){
    unsigned int x = idx%32;
    idx /= 32;
    if (newval == 1)
    {
        arr[idx] |= (1<<x);
    }
    else
    {
        arr[idx] &= ~(1<<x);
    }
}

bitword makeMask(int left, int right)
{
    bitword m = 0;
    for (int j = 0; j<right-left; j++)
        m = (m << 1) + 1;
    for (int j = 0; j<left; j++)
        m = m << 1;
    return m;
}

int anyBitInRange(bitword word, int left, int right)
{
    bitword acc = word & makeMask(left, right);
    if (acc != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int bitsetAny ( const bitword * arr , int left , int right ) // left = 33, right = 100
{
    int i;
    if (left/32 == right/32)
    {
        return anyBitInRange(arr[left/32], left%32, right%32);
    }

    for (i = left/32; i <= right/32; i++)
    {
        if (i == left/32)
        {
            if (anyBitInRange(arr[i], left%32, 32))
                return 1;
        }
        else
        {
            if (i == right/32)
            {
                if (anyBitInRange(arr[i], 0, right%32))
                    return 1;
            }
            else
            {
                if (arr[i] != 0)
                    return 1;
            }
        }
    }
    return 0;
}

bitword* all[625000];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int ans, val, n, t, isdef;
    isdef = 0;
    scanf("%d", &n);
    for (int o = 0; o < n; o++)
    {
        scanf("%d", &t);
        if (t == 0)
        {
            scanf("%d", &val);
            bitsetZero(all, (val/32));
        }

        if (t == 1)
        {
            scanf("%d", &val);
            ans = bitsetGet(all, val);
            printf("%d\n", ans);
        }

        if (t == 2)
        {
            scanf("%d %d", &val, &ans);
            bitsetSet(all, val, ans);
        }

        if (t == 3)
        {
            scanf("%d %d", &val, &ans);
            ans = bitsetAny(all, val, ans);
            if (ans == 1)
            {
                printf("some\n");
            }
            else
            {
                printf("none\n");
            }
        }
    }

    return 0;
}
