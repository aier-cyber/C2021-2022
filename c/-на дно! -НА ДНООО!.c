#include <stdio.h>
#include <string.h>
char AllLetters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
char AllBLetters[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
char AllDigits[] = {'0','1','2','3','4','5','6','7','8','9'};

int isDigit (char a)
{
int i;
for(i=0; i<10; i++)
{
    if (a == AllDigits[i])
       {
           return 1;
       }
}
return 0;
}

int isLetter (char a)
{
for (int i = 0; i<26; i++)
{
    if (a == AllLetters[i])
    {
        return 1;
    }
}
return 0;
}

int isBLetter (char a)
{
for (int i = 0; i<26; i++)
{
    if (a == AllBLetters[i])
    {
        return 1;
    }
}
return 0;
}

int calcLetters ( char *iStr , int *oLowerCnt , int *oUpperCnt , int *oDigitsCnt )
{
    *oLowerCnt = 0;
    *oDigitsCnt = 0;
    *oUpperCnt = 0;
    int ya = 0;
    while(*(iStr+ya) != '\n')
    {
        if (isDigit(*(iStr+ya)))
        {
            ++*oDigitsCnt;
        }
        if (isBLetter(*(iStr+ya)))
        {
            ++*oUpperCnt;
        }
        if (isLetter(*(iStr+ya)))
        {
            ++*oLowerCnt;
        }
        ya++;
    }
    printf("%d chars: %d are letters (%d lower, %d upper), %d are digits.\n", ya, *oLowerCnt+*oUpperCnt, *oLowerCnt, *oUpperCnt, *oDigitsCnt);
}

int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int LowerCnt, UpperCnt, DigitsCnt;
char Str[101];
char ping;
int n=0;
int SolveHelper = 0;
while (1)
{
    if ( scanf ("%c", &ping) != 1)
                        break;
    ungetc(ping, stdin);

    gets(Str);
    SolveHelper = strlen(Str);
    Str[SolveHelper] = '\n';
    n++;
    printf("Line %d has ", n);
    calcLetters(&Str[0], &LowerCnt, &UpperCnt, &DigitsCnt);
}
return 0;
}
