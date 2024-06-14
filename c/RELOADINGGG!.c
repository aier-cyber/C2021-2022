#include <stdio.h>
#include <string.h>

char* concat(char *pref, char *suff) {
int j = 0;
while (*(suff+j)!=1) {
*(pref+j) = *(suff+j);
j++;
}
}

char str[1000000];

int main() {
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

int n;
int len = 0;;
scanf("%d", &n);
char s[100];
for (int i = 0; i < n; i++) {
scanf("%s", &s);
concat(&str[len], s);
len += strlen(s);
}
printf("%s", str);

return 0;
}
