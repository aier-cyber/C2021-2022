#include <stdio.h>
#include <stdlib.h>
typedef struct Cell{      // j =   012
    int state;            // i = 0 ###
    struct Cell* left;    // i = 1 ##...
    struct Cell* right;
    struct Cell* up;
    struct Cell* down;
} Cell;
Cell field[1001][1001];
struct Cell guard;
void AvalancePaint(Cell* curr){
    if (curr->state == 0){
        curr->state = 1;
        AvalancePaint(curr->down);
        AvalancePaint(curr->right);
        AvalancePaint(curr->up);
        AvalancePaint(curr->left);
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    guard.state = 1;
    char sym;
    int N, i, j, ans = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            scanf("%c", &sym);
            if (sym == '\n'){scanf("%c", &sym);}
            if (sym == ' '){
                field[i][j].state = 0;
            }
            if (sym == '*'){
                field[i][j].state = 1;
            }
            if ((i == 0) || (i == N-1)){
                if (i == 0){
                    field[i][j].up = &guard;
                    field[i][j].down = &field[i+1][j];
                }
                if (i == N-1){
                    field[i][j].up = &field[i-1][j];
                    field[i][j].down = &guard;
                }
            }
            else{
                field[i][j].up = &field[i-1][j];
                field[i][j].down = &field[i+1][j];
            }
            if ((j == 0) || (j == N-1)){
                if (j == 0){
                    field[i][j].left = &guard;
                    field[i][j].right = &field[i][j+1];
                }
                if (j == N-1){
                    field[i][j].left = &field[i][j-1];
                    field[i][j].right = &guard;
                }
            }
            else{
                field[i][j].left = &field[i][j-1];
                field[i][j].right = &field[i][j+1];
            }
        }
    }
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (field[i][j].state == 0){
                if (i == 0){
                    AvalancePaint(&field[i][j]);
                }
                else{
                    ans++;
                    AvalancePaint(&field[i][j]);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
