#include <stdio.h>
#include <math.h>
int myDegree(int a, int b) // (c, 2), c==0
{
    int mimic = b; // mimic = 2
    b = 1;

    for (int rrand = 1; rrand <= a; rrand++) // c==0 => ����������
        b = b*mimic;

    return b; //b = 1
}

int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

int n,i,a,c,sum;
char mb;
scanf("%d", &n);
sum = 0;

for (i=1; i<=n/8; i++) //���������� �������
{
    for (c = 0; c<=7; c++) //����� �����
    {
        //printf("%d  ", myDegree(c, 2));
        scanf(" %c", &mb);
        if (mb == '1') // ��������� ������� ���������� �������
        {
            sum = sum + myDegree(c,2);
        }
    }
    printf("%d ", sum);
   //printf("\n");
   sum = 0;
}

for (i=0; i<n%8; i++) //� ������ ������� ������� �����
{
        scanf(" %c", &mb);
        if (mb == '1')
        {
            sum = sum + myDegree(i,2);
        }
    if (i == (n%8)-1) //������� �������� ����� ������ ��� ������� i
        printf("%d", sum);
}
return 0;
}
