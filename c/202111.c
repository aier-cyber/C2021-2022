#include <stdio.h>

int main ()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

int ansone,anstwo,i,x,d,N,M,P,K,L;
scanf("%d", &N);
scanf("%d %d %d %d", &M, &P, &K, &L);

d = (P-1)*L+(K-1);
for (i=1; i<=M; i++)
{
    if (M%i == 0)
    { if ((d+1)*i == M-(M%i))
    { x = i; break; }}
    else if (d*i == M-(M%i))
    { x = i; break; }
}



if (N%x == 0)
{ i = N/x; }
else { i = N/x + 1; }

if (i%L == 0)
{ ansone = i/L; anstwo = L; }
else { ansone = 1+i/L; anstwo = i%L; }

printf("%d %d", ansone, anstwo);

return 0;
}
