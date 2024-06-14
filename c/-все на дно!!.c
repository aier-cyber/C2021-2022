#include <stdio.h>
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

char next, curr;
while(1)
{
    if ( scanf ("%c", & curr ) != 1)
            break ;
    if (curr == '/')
    {
        if ( scanf ("%c", & next) != 1)
        { printf("%c", curr); break; }

        if ((next == '*')||(next == '/'))
        {
            if (next == '/')
            {////////////////////////////////////////////////////////////////////
                while(1)
                {
                if ( scanf ("%c", & next) != 1)
                    break;
                if (next == '\n')
                { printf("%c", next); break; }
                }
            }////////////////////////////////////////////////////////////////////
            if (next == '*')
            {/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
                while(1)
                {
                    if ( scanf ("%c", & next) != 1)
                        break;
                        if (next == '\n')
                            printf("%c", next);

                    if (next == '*')
                    {
                        if ( scanf ("%c", & curr) != 1)
                            break;
                        if (curr == '/')
                            break;
                        ungetc(curr, stdin);
                    }
                }
            }/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
        }
        else { printf("%c", curr); ungetc(next,stdin);}
    }
    else printf("%c", curr);

}

return 0;
}
