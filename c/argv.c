#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{         //main ����� ��������� ��� ���������
    char* all;
    char* empt;
    empt = ' ';
    for (int i = 0; i < argc; i++) {        //argc --- ���������� ���������� + 1
      strcat(all, argv[i]);
      strcat(all, empt);   //argv[0] --- ������ ���� � ������������� �����
    }                                       //argv[>0] --- ��������� ��������� ������ � ������� �������
    return 7;                               //������������ �������� main = "��� ��������"
}
