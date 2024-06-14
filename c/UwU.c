#include <stdio.h>
#include <string.h>
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char c, all[100];
    int i = 0, len;
    gets(all);
    len = strlen(all);
    for (i = 0; i < len; i++)
    {
        if (all[i] == '"')
        {
            printf("[");
            i++;
            while(all[i] != '"')
            {
                printf("%c", all[i]);
                i++;
            }
            printf("]\n");
        }
        else
        {
            if(all[i] == ' ')
            {
                continue;
            }
            else
            {
                printf("[");
                while((all[i] != ' ') && (i < len))
                {
                    printf("%c", all[i]);
                    i++;
                }
                printf("]\n");
                if (i == len)
                    break;
            }
        }
    }
    return 0;
}
