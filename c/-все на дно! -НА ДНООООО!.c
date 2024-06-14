#include <stdio.h>
#include <string.h>
struct keeper {
int devastator, devastatorr, hodor;
} keeper;
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

char c, curr, mimic, mimicc;
int distance;
keeper.devastator = 0;

while (1) {
 if ( scanf ("%c", & curr ) != 1)
     { if ((mimic == '/')&&(keeper.devastator == 0)&&(keeper.devastatorr == 0)&&(mimicc!='*'))
      { printf("%c", mimic); }
      break; }
          if (curr == '\n')
          {
              keeper.hodor = 0;
              keeper.devastator = 0;
              printf("%c", curr);
          }
          else {

          if (curr == '/') {
          if ((mimic == '/')&&(mimicc != '*')&&(keeper.devastatorr == 0)) keeper.devastator = 1; /*/*///
          if ((mimic == '*')&&(distance > 1)) { keeper.devastatorr = 0; distance = 0; keeper.hodor = 0; } } /**//**/
          if ((curr == '*')&&(mimic == '/')&&(keeper.devastator == 0)) keeper.devastatorr = 1; //**//условия включения опустошителей

          if (keeper.devastatorr == 1)
            distance++;

          if ((keeper.devastator == 0)&&(keeper.devastatorr == 0)) // проверяем бдят ли опустошители
              {
                  if  (curr == '/')
          { keeper.hodor = 1; } //настораживаемся - это может быть начало комментария
                  else
                  {
                    if ((keeper.hodor == 1)&&(mimicc != '*')) //проверяем не насторажились мы в прошлый раз, и не является ли предыдущий слеш частью переключения
                  { printf("%c", mimic); } //если насторожились, расстораживаемся и выводим прошлый символ
                  printf("%c", curr); //наконец, если текущий символ не слеш и оба опустошителя спят, выводим символ
                  keeper.hodor = 0;
                  }
              }

          }
          mimicc = mimic;
          mimic = curr;
          }

return 0;
}//
