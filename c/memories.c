#include <stdio.h>
#include <string.h>
int ConvertToRank(int b)
{
    int i = 0;
    while (b/10 > 0)
    {
        i++;
        b = b/10;
    }
    i++;
    return i;
}
int ImprovedPrint(int maxR, int Const)
{
    while (maxR-ConvertToRank(Const)>0)
    {
        printf(" ");
        maxR--;
    }
    printf("%d", Const);

}
int DefaultConnect (int a, int b, int c, char *d)
{
    int i = 2;
    *d = '+';
    *(d+1) = '-';
    while(a>0)
    {
        *(d+i) = '-';
        i++;
        a--;
    }
    *(d+i) = '-';
    i++;
    *(d+i) = '+';
    i++;
    *(d+i) = '-';
    i++;
    while(b>0)
    {
        *(d+i) = '-';
        i++;
        b--;
    }
    *(d+i) = '-';
    i++;
    *(d+i) = '+';
    i++;
    *(d+i) = '-';
    i++;
    while (c>0)
    {
        *(d+i) = '-';
        i++;
        c--;
    }
    *(d+i) = '-';
    i++;
    *(d+i) = '+';
}

int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int ID[1001];
int VLengthOfID[1001];
int MaxID = -1, MaxAmount = -1, MaxLength = -1, i, n, CurrID, CurrLen;
char mimic[1000];
scanf("%d", &n);
for (i = 0; i<1001; i++)
{
    ID[i] = 0;
    VLengthOfID[i] = 0;
}

for (i = 0; i<n; i++)
{
    scanf("%d %d", &CurrID, &CurrLen);
    VLengthOfID[CurrID] += CurrLen;
    ID[CurrID]++;

    if (CurrID > MaxID)
        MaxID = CurrID;

    if (ID[CurrID] > MaxAmount)
        MaxAmount = ID[CurrID];

    if (VLengthOfID[CurrID] > MaxLength)
        MaxLength = VLengthOfID[CurrID];
}

MaxLength = ConvertToRank(MaxLength);
MaxAmount = ConvertToRank(MaxAmount);
MaxID = ConvertToRank(MaxID);
DefaultConnect(MaxID, MaxAmount, MaxLength, mimic);
printf("%s\n", mimic);

for (i=0; i<1001; i++)
{
    if (ID[i] != 0)
    {
        printf("| ");
        ImprovedPrint(MaxID, i);
        printf(" | ");
        ImprovedPrint(MaxAmount, ID[i]);
        printf(" | ");
        ImprovedPrint(MaxLength, VLengthOfID[i]);
        printf(" |\n");
        printf("%s\n", mimic);
    }
}

return 0;
}
