#include <stdio.h>
int SPOON (int cs, int bs)
{
    int t;
    long int key;
    for (t=1; t<=(cs/2); t++)
    {
        int f=bs%cs;
        if (((f*t+1)%cs)==0)
        {
            key = (f*t+1)/cs;
            break;
        }
        if (((1-f*t)%cs)==0)
        {
            key = (bs*(cs-t)+1)/cs;
            break;
        }
    }
    printf("%ld\n", key);
}
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int a,b,c,d;
scanf("%d %d", &a, &b);
for(d=1; d<=a; d++)
{
scanf("%d", &c);
if ((c%b)==0)
    printf("%d\n", (-1));
    else
    if (c==1)

    printf("%d\n", 1);
    else
    SPOON(c,b);
}
}
