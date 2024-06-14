#include <stdio.h>
#include <string.h>
long long int OperFunc (char *type, int ft, int sd)
{
    long long int ans;
    if (type[0] == 'm')
    {
        ans = (long long int)ft * (long long int)sd;
        return ans;
    }
    else
    {
        if (type[0] == 'a')
        {
            ans = (long long int)ft + (long long int)sd;
            return ans;
        }
        else
        {
            ans = (long long int)ft - (long long int)sd;
            return ans;
        }
    }
}
int main(int argc, char **all)
{
    int A, B, Mod;
    long long int answer;
    if (argc < 4)
    {
        fprintf(stderr, "No parameters specified.");
        return 13;
    }
    if (argc == 4)
    {
        sscanf(all[2], "%d", &A);
        sscanf(all[3], "%d", &B);
        answer = OperFunc(all[1], A, B);
        printf("%lld", answer);
        return 0;
    }
    if (argc == 6)
    {
        if (*(all[1]+0) == '-')
        {
            sscanf(all[2], "%d", &Mod);
            sscanf(all[4], "%d", &A);
            sscanf(all[5], "%d", &B);
            A %= Mod;
            B %= Mod;
            answer = OperFunc(all[3], A, B);
            answer %= (long long int)Mod;
            if (answer < 0)
                answer += Mod;
            printf("%lld", answer);
            return 0;
        }
        else
        {
            sscanf(all[5], "%d", &Mod);
            sscanf(all[2], "%d", &A);
            sscanf(all[3], "%d", &B);
            A %= Mod;
            B %= Mod;
            answer = OperFunc(all[1], A, B);
            answer %= (long long int)Mod;
            if (answer < 0)
                answer += Mod;
            printf("%lld", answer);
            return 0;
        }
    }
}
