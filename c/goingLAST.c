#include <stdio.h>
#include <stdlib.h>
int min (int a, int b){
    if (a > b)
        return b;
    else
        return a;
}
int memo[1001][1001];
int Rec(int Sum, int Last, int p) {
    if (memo[Sum][Last] == -1) {
        int res = 0;
        if (Sum == p){
            res = 1;
        }
        else {
            for (int x = 1; x <= min(Last, p-Sum); x++){
                res += Rec(Sum+x, x, p);
                res %= 1000000007;
            }
        }
        memo[Sum][Last] = res;
    }
    return memo[Sum][Last];
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, i, j;
    for (i = 0; i < 1001; i++){
        for (j = 0; j < 1001; j++){
            memo[i][j] = -1;
        }
    }
    scanf("%d", &N);
    printf("%d", Rec(0, N, N));
    return 0;
}
