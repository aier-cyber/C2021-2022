#include <stdio.h>
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char curr, next, swapper;
    while (1)
    {
            if ( scanf ("%c", & curr ) != 1)
            break ;
            if (curr == '/')
            {
                if ( scanf("%c", & next ) != 1)
                { printf("%c", curr); break; }
                if (next == '/')
                {
                    while(1)
                    {
                    if ( scanf ("%c", & next ) != 1)
                        break ;
                    if (next == '\n')
                    { printf("%c", next); break; }
                    }
                }
                else
                {
                 if (next == '*')
                 {
                     while(1)
                     {
                         if ( scanf ("%c", & next ) != 1)
                            break ;

                         if (next == '\n') printf("%c", next);

                         if ((curr == '*')&&(next == '/'))
                            break;

                         if (next == '*')
                         {
                             if ( scanf ("%c", & curr ) != 1)
                                break ;
                             if (curr == '\n') printf("%c", curr);
                             if (curr == '/')
                                break;
                        }
                     }
                 }
                 else
                 printf("%c%c", curr, next);
                }
            }
            else printf("%c", curr);
}
    return 0;
}
