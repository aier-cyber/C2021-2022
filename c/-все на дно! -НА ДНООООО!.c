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
          if ((curr == '*')&&(mimic == '/')&&(keeper.devastator == 0)) keeper.devastatorr = 1; //**//������� ��������� �������������

          if (keeper.devastatorr == 1)
            distance++;

          if ((keeper.devastator == 0)&&(keeper.devastatorr == 0)) // ��������� ���� �� ������������
              {
                  if  (curr == '/')
          { keeper.hodor = 1; } //��������������� - ��� ����� ���� ������ �����������
                  else
                  {
                    if ((keeper.hodor == 1)&&(mimicc != '*')) //��������� �� ������������� �� � ������� ���, � �� �������� �� ���������� ���� ������ ������������
                  { printf("%c", mimic); } //���� �������������, ���������������� � ������� ������� ������
                  printf("%c", curr); //�������, ���� ������� ������ �� ���� � ��� ������������ ����, ������� ������
                  keeper.hodor = 0;
                  }
              }

          }
          mimicc = mimic;
          mimic = curr;
          }

return 0;
}//
