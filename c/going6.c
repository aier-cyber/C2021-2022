#include <stdio.h>
#include <stdlib.h>
int field[12][12];
int N, size;
int col[12];
int hasV[12];
void copy(int (*arr)[12]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < size; j++){
            arr[i][j] = field[i][j];
        }
    }
}
void markDiagonal(int r, int c){
    int i, k;
    k = r+1;
    if (k != N){
        for (i = c-1; i >= 0; i--){
            field[k][i] = 1;
            k++;
            if (k == N){
                break;
            }
        }
        k = r+1;
        for (i = c+1; i < size; i++){
            field[k][i] = 1;
            k++;
            if (k == N){
                break;
            }
        }
    }
}
void unmarkDiagonal(int (*arr)[12], int r, int c){
    int i, k;
    k = r+1;
    if (k != N){
        for (i = c-1; i >= 0; i--){
            field[k][i] = arr[k][i];
            k++;
            if (k == N){
                break;
            }
        }
        k = r+1;
        for (i = c+1; i < size; i++){
            field[k][i] = arr[k][i];
            k++;
            if (k == N){
                break;
            }
        }
    }
}
int Rec(int r) {
    int arrcpy[12][12];
    if (r == N) {
      return 1;
    }
    for (int c = 0; c < size; c++) {
        if ((hasV[c]) || (field[r][c]))
            continue;
        col[r] = c;
        hasV[c] = 1;
        copy(arrcpy);
        markDiagonal(r, c);
        if (Rec(r+1))
            return 1;
        unmarkDiagonal(arrcpy, r, c);
        hasV[c] = 0;
        col[r] = 0;
    }
    return 0;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, j;
    char sym;
    scanf("%d %d", &N, &size);
    for (i = 0; i < N; i++){
        for (j = 0; j < size; j++){
            scanf("%c", &sym);
            if (sym == '\n'){scanf("%c", &sym);}
            if (sym == '?'){
                field[i][j] = 0;
            }
            if (sym == '.'){
                field[i][j] = 1;
            }
        }
    }
    if (Rec(0) == 0){
        printf("NO");
    }
    else{
        printf("YES\n");
        for (i = 0; i < N; i++){
            for (j = 0; j < size; j++){
                if (j == col[i]){
                    printf("X");
                }
                else{
                    printf(".");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
