# include "modular.h" //в этом хедере должны быть объ€влени€
# include <assert.h>
int main () {
MOD = 13; //устанавливаем глобальный модуль
int a = 45;
a = pnorm (a);
assert (a == 6);
a = -17;
a = pnorm(a);
assert (a == 9);
int b = 23;
MOD = 17;
a = pmul(pnorm(a), pnorm(b));
assert (a == 3);
a = -3;
a = pmul(pnorm(a), pnorm(b));
assert (a == 16);
b = -5;
assert (padd(pnorm(a),pnorm(b)) == 11);
assert (padd(pnorm(b),pnorm(a)) == 11);
a = -3;
assert (padd(pnorm(a),pnorm(b)) == 9);
assert (psub(pnorm(a),pnorm(b)) == 2);
a = 178;
b = 23;
assert (pdiv(pnorm(a),pnorm(b)) == 7);
MOD = 23;
assert (psub(2, 20) == 5);
MOD = 10000019;
assert (pmul(10000018, 10000018) == 1);
assert (pdiv(10000018, 10000018) == 1);
MOD = 433494437;
assert (pdiv(433494436, 433494436) == 1);
return 0;
}
