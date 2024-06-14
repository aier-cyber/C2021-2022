#include <stdio.h>

int main() {
freopen("input.txt", "r", stdin);

int n, m;
scanf("%d", &n);
scanf("%d", &m);
int x[300] = { 0 };
int y[90000] = { 0 };
for (int i = 0; i < m; i++) {
scanf("%d", &x[i]);
scanf("%d", &y[i]);
}

for (int i = 0; i < m; i++) {
for (int j=i+1;j<m;j++)
if (x[i] == x[j]) {
printf("0");
return 0;
}
}

printf("1");

int z = 0;
for (int i = 0; i < m; i++) {
if (x[i] > n) z++;
if (n > m) z++;
}

if (z == 0) printf(" 2");
z = 0;
for (int i = 0; i < m; i++) {
for (int j = i + 1; j < m; j++)
if (y[i] == y[j]) {
z++;
}
}
if (z == 0) printf(" 3");
int z1 = 0;
for (int i = 0; i < m; i++) {
if (y[i] > n) z1++;
if (n > m) z1++;
}
if (z1 == 0) printf(" 4");
if ((z == 0) && (z1 == 0)) printf(" 5");

return 0;
}
