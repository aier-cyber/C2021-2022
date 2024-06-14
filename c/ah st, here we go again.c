#include <stdio.h>
#include <string.h>
char s[1000005];
int c = 0;

char *concat(char *pref, char *suff)
{
while (*suff != '\0')
    {
    s[c] = *suff;
    c++;
    suff++;
    }
}
void main()
{
int n;
char st[101];

scanf("%d", &n);
scanf("%s", st);
concat(s, st);
for (int i=0; i < n-1; ++i)
    {
    scanf("%s", st);
    concat(s, st);
    }
printf("%s", s);
}
