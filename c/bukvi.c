#include <stdio.h>
#include <string.h>
void LowerThousandConvert(int a, int checker)
{
    int curr;
    curr = a/100;
    if (curr == 1)
    { printf("sto "); }
    if (curr == 2)
    { printf("dvesti "); }
    if (curr == 3)
    { printf("trista "); }
    if (curr == 4)
    { printf("chetyresta "); }
    if (curr == 5)
    { printf("pyat'sot "); }
    if (curr == 6)
    { printf("shest'sot "); }
    if (curr == 7)
    { printf("sem'sot "); }
    if (curr == 8)
    { printf("vosem'sot "); }
    if (curr == 9)
    { printf("devyat'sot "); }

    curr = a%100;
    if (curr < 20)
    {
        if ((curr == 1) && (checker == 3))
            printf("odin ");
        if ((curr == 1) && (checker != 3))
            printf("odna ");
        if ((curr == 2) && (checker == 3))
            printf("dva ");
        if ((curr == 2) && (checker != 3))
            printf("dve ");
        if (curr == 3)
            printf("tri ");
        if (curr == 4)
            printf("chetyre ");
        if (curr == 5)
            printf("pyat' ");
        if (curr == 6)
            printf("shest' ");
        if (curr == 7)
            printf("sem' ");
        if (curr == 8)
            printf("vosem' ");
        if (curr == 9)
            printf("devyat' ");
        if (curr == 10)
            printf("desyat' ");
        if (curr == 11)
            printf("odinnadtsat' ");
        if (curr == 12)
            printf("dvenadtsat' ");
        if (curr == 13)
            printf("trinadtsat' ");
        if (curr == 14)
            printf("chetyrnadtsat' ");
        if (curr == 15)
            printf("pyatnadtsat' ");
        if (curr == 16)
            printf("shestnadtsat' ");
        if (curr == 17)
            printf("semnadtsat' ");
        if (curr == 18)
            printf("vosemnadtsat' ");
        if (curr == 19)
            printf("devyatnadtsat' ");
    }
    else
    {
        if (curr/10 == 2)
            printf("dvadtsat' ");
        if (curr/10 == 3)
            printf("tridtsat' ");
        if (curr/10 == 4)
            printf("sorok ");
        if (curr/10 == 5)
            printf("pyat'desyat ");
        if (curr/10 == 6)
            printf("shest'desyat ");
        if (curr/10 == 7)
            printf("sem'desyat ");
        if (curr/10 == 8)
            printf("vosem'desyat ");
        if (curr/10 == 9)
            printf("devyanosto ");

        if ((curr%10 == 1) && (checker == 3))
            printf("odin ");
        if ((curr%10 == 1) && (checker != 3))
            printf("odna ");
        if ((curr%10 == 2) && (checker == 3))
            printf("dva ");
        if ((curr%10 == 2) && (checker != 3))
            printf("dve ");
        if (curr%10 == 3)
            printf("tri ");
        if (curr%10 == 4)
            printf("chetyre ");
        if (curr%10 == 5)
            printf("pyat' ");
        if (curr%10 == 6)
            printf("shest' ");
        if (curr%10 == 7)
            printf("sem' ");
        if (curr%10 == 8)
            printf("vosem' ");
        if (curr%10 == 9)
            printf("devyat' ");
    }
}

void ToThousandsDemounted(int b)
{
    int curr;
    int Rank;
    curr = b/1000000;
    if (curr != 0)
    {
        Rank = 3;
        LowerThousandConvert(curr, Rank);
        if (curr%100 < 21)
        {
            if ((curr%100 > 4)||(curr%100 == 0))
                printf("millionov ");

            if ((curr%100 == 2)||(curr%100 == 3)||(curr%100 == 4))
                printf("milliona ");

            if (curr%100 == 1)
                printf("million ");
        }
        else
        {
            if (curr%10 == 1)
            printf("million ");

            if ((curr%10 > 1) && (curr%10 < 5))
            printf("milliona ");

            if ((curr%10 == 0)||(curr%10 > 4))
            printf("millionov ");
        }
    }
    curr = (b%1000000)/1000;
    if (curr != 0)
    {
        Rank = 2;
        LowerThousandConvert(curr, Rank);
        if (curr%100 < 21)
        {
            if ((curr%100 > 4)||(curr%100 == 0))
                printf("tysyach ");

            if ((curr%100 > 1) && (curr%100 < 5))
                printf("tysyachi ");

            if (curr%100 == 1)
                printf("tysyacha ");
        }
        else
        {
            if (curr%10 == 1)
                printf("tysyacha ");

            if ((curr%10 > 1) && (curr%10 < 5))
                printf("tysyachi ");

            if ((curr%10 == 0)||(curr%10 > 4))
                printf("tysyach ");
        }
    }
    curr = b%1000;
    Rank = 1;
    if (curr != 0)
        LowerThousandConvert(curr, Rank);

    if (curr%100 < 21)
        {
            if ((curr%100 > 4)||(curr%100 == 0))
                printf("strok\n");

            if ((curr%100 > 1) && (curr%100 < 5))
                printf("stroki\n");

            if (curr%100 == 1)
                printf("stroka\n");
        }
        else
        {
            if (curr%10 == 1)
                printf("stroka\n");

            if ((curr%10 > 1) && (curr%10 < 5))
                printf("stroki\n");

            if ((curr%10 == 0)||(curr%10 > 4))
                printf("strok\n");
        }

}

int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int n, i, value;
scanf("%d", &n);

for(i=1; i<=n; i++)
{
    scanf("%d", &value);
        ToThousandsDemounted(value);
}

return 0;
}
