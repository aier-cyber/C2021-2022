#define NDEBUG
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <string.h>
long double parseMonome();
long double parseExpression();
char AllDigits[] = {'0','1','2','3','4','5','6','7','8','9'};

int misdigit (char a)
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
int parseNumber (){
    char curr;
    int ans;
    while(1){
        if ((curr = getchar()) == EOF)
            return ans;
        if(misdigit(curr))
            ans = ans*10 + (int)curr - (int)'0';
        else{
            ungetc(curr, stdin);
            return ans;
        }
    }
}
long double parseAtom(){
    long double ans = 0.0;
    char curr;
    int hold;
    if ((curr = getchar()) == EOF)
        return ans;
    while(curr == ' '){
        if ((curr = getchar()) == EOF)
            return ans;
    }
    if (misdigit(curr)){
        hold = parseNumber();
        ans = (long double)hold;
        return ans;
    }
    else{
        ans = parseExpression();
        return ans;
    }
}
long double ppls(long double curr){
    curr += parseMonome();
    return curr;
}
long double pmns(long double curr){
    curr -= parseMonome();
    return curr;
}
long double pmlt(long double curr){
    curr *= parseAtom();
    return curr;
}
long double pdiv(long double curr){
    curr /= parseAtom();
    return curr;
}

long double parseMonome(){
    long double ans = 0.0;
    char curr;
    int hold;
    while(1){
        if ((curr = getchar()) == EOF){
            return ans;}
        while(curr == ' '){
            if ((curr = getchar()) == EOF){
                return ans;}
        }
        if ((misdigit(curr)) || (curr == '(')){
            ungetc(curr, stdin);
            ans = parseAtom();
            continue;
        }
        if ((curr == '+') || (curr == '-')){
            ungetc(curr, stdin);
            return ans;
        }
        if (curr == '*'){
            ans = pmlt(ans);
            continue;
        }
        if (curr == '/'){
            ans = pdiv(ans);
            continue;
        }
        if (curr == ')'){
            ungetc(curr, stdin);
            return ans;
        }
    }
}
long double parseExpression(){
    long double ans = 0.0;
    char curr;
    int hold;
    while(1){
        if ((curr = getchar()) == EOF)
            return ans;
        while(curr == ' '){
            if ((curr = getchar()) == EOF)
                return ans;
        }
        if ((misdigit(curr)) || (curr == '(')){
            ungetc(curr, stdin);
            ans = parseMonome();
            continue;
        }
        if (curr == '+'){
            ans = ppls(ans);
            continue;
        }
        if (curr == '-'){
            ans = pmns(ans);
            continue;
        }
        if (curr == ')'){
            return ans;
        }
        return ans;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long double ans = 0.0;
    ans = parseExpression();
    printf("%0.20lf", (double)ans);
    return 0;
}
