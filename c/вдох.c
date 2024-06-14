#include <stdio.h>
#include <string.h>
char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int CDtoID (char c)
{
    for (int i = 0; i<10; i++)
    {
        if (c == digits[i])
        {
            return i;
        }
    }
    return 99;
}
int readTime ( char *iStr , int *oHours , int *oMinutes , int *oSeconds )
{
    int Correctness = 1, t = 0, k = 0, j = 1;
    int CorrectCount[2];
    while(1)
    {
        if ((*(iStr+t) == ':')||(*(iStr+t) == '\n'))
        {
            if (Correctness == 1)
            {
                if (j == 1)
                {
                    if (k == 1)
                    {
                        *oHours = CorrectCount[0];
                    }
                    else
                    {
                        *oHours = CorrectCount[0]*10 + CorrectCount[1];
                        if (*oHours > 23)
                        {
                            *oHours = (-1);
                            if (oMinutes != 0)
                                *oMinutes = (-1);
                            if (oSeconds != 0)
                                *oSeconds = (-1);
                            Correctness = 0;
                        }
                    }
                }
                if (j == 2)
                {
                    if (k == 1)
                    {
                        if ( oMinutes != 0)
                        *oMinutes = CorrectCount[0];
                    }
                    else
                    {
                        if (CorrectCount[0]*10+CorrectCount[1] > 59)
                        {
                            *oHours = (-1);
                            if (oMinutes != 0)
                                *oMinutes = (-1);
                            if (oSeconds != 0)
                                *oSeconds = (-1);
                            Correctness = 0;
                        }
                        else
                        {
                            if ( oMinutes != 0)
                            *oMinutes = CorrectCount[0]*10+CorrectCount[1];

                        }
                    }
                }
                if (j == 3)
                {
                    if (k == 1)
                    {
                        if ( oSeconds != 0)
                        *oSeconds = CorrectCount[0];
                    }
                    else
                    {
                        if (CorrectCount[0]*10+CorrectCount[1] > 59)
                        {
                            *oHours = (-1);
                            if (oMinutes != 0)
                                *oMinutes = (-1);
                            if (oSeconds != 0)
                                *oSeconds = (-1);
                            Correctness = 0;
                        }
                        else
                        {
                            if ( oSeconds != 0)
                            *oSeconds = CorrectCount[0]*10+CorrectCount[1];

                        }
                    }
                }
            }
            j++;
            k = 0;
            if (*(iStr+t) == '\n')
                break;
            t++;
        }
        else
        {
            if (*(iStr+t) == '|')
            {
                *oHours = (-1);
                if (oMinutes != 0)
                    *oMinutes = (-1);
                if (oSeconds != 0)
                    *oSeconds = (-1);
                Correctness = 0;
                t++;
            }
            else
            {
                if (k != 2)
                {
                    CorrectCount[k] = CDtoID(*(iStr+t));
                    k++;
                    t++;
                }
                else
                {
                    *oHours = (-1);
                    if (oMinutes != 0)
                        *oMinutes = (-1);
                    if (oSeconds != 0)
                        *oSeconds = (-1);
                    Correctness = 0;
                    t++;
                }
            }
        }
    }
    printf("%d ", Correctness);
    printf("%d ", *oHours);
    if (oMinutes != 0)
        printf("%d ", *oMinutes);
    if (oSeconds != 0)
        printf("%d", *oSeconds);
    printf("\n");
}
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

int SolveHelper, Hours, Minutes, Seconds;
char str[100];
scanf("%s", &str);
SolveHelper = strlen(str);
str[SolveHelper]='\n';
Hours = 0;
Minutes = 0;
Seconds = 0;
readTime(&str[0], &Hours, &Minutes, &Seconds);
readTime(&str[0], &Hours, &Minutes, 0);
readTime(&str[0], &Hours, 0, 0);
return 0;
}
