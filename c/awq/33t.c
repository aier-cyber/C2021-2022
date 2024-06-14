#include <stdio.h>
#include <string.h>
char all[500000];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    gets(all);
    char k = 9999;
    printf("%s %d", all, (int)k);
    return 0;
}
