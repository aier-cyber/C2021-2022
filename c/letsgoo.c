#include <stdio.h>
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char c;
    int count;
    int guard = 0;
    scanf(" %c", &c);
    while(c != ' ')
    {

        if (c == '\n')
            break;

        if (c != '.')
        {
            if (guard == 0)
            { count++; guard++; }
        }
        else guard = 0;
        scanf("%c", &c);
    }

    printf("%d", count);

    return 0;
}
