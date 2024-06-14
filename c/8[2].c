#include <stdio.h>
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
 int a1, a2, b1, b2, c1, c2;
 scanf("%d", &a1);
 scanf("%d", &a2);
 scanf("%d", &b1);
 scanf("%d", &b2);
 scanf("%d", &c1);
 scanf("%d", &c2);

 if ((a1 < b1 ) || ( a1 < b2 ) || ( a1 < c1 ) || ( a1 < c2 ) || ( a2 < c1 ) || ( a2 < c2 ) || ( a2 < b1 ) || ( a2 < b2 ))
 { printf("NO"); goto end; }

 if (a1 * a2 < b1 * b2 + c1 * c2)
 { printf("NO"); goto end; }

        if ((b1 <= a1) && ( b2 <= a2))
        {
        if ((c2 <= a2 ) && ( c1 <= a1 - b1))
    { printf("YES"); goto end; }

        if ((c1 <= a2) && (c2 <= a1 - b1))
    { printf("YES"); goto end; }

        if ((c2 <= a2 - b2) && ( c1 <= a1))
    { printf("YES"); goto end; }

        if ((c1 <= a2 - b2) && ( c2 <= a1))
    { printf("YES"); goto end; }
        }

        if ((b1 <= a2 )&&( b2 <= a1))
        {
        if ((c2 <= a1 - b2 ) && ( c1 <= a2))
    { printf("YES"); goto end; }

        if ((c1 <= a1 - b2 ) && ( c2 <= a2))
    { printf("YES"); goto end; }

        if ((c2 <= a2 - b1 ) && ( c1 <= a1))
    { printf("YES"); goto end; }

        if ((c1 <= a2 - b1 ) && ( c2 <= a1))
    { printf("YES"); goto end; }
        }

        printf("NO");

 end:
 return 0;
 }
