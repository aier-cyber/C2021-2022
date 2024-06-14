#include <stdio.h>
#include <stdlib.h>
typedef struct Point{
    int WayLength;
    int* OtherPoints;
    int amount;
    int isCalled;
} Point;
Point all[200002];
int mstack[200002];
void AvalanceMarking(Point* curr, int* mstackLen){
    if (curr->isCalled == 0){
        for (int l = 0; l < curr->amount; l++){
            if (all[curr->OtherPoints[l]].WayLength == -1){
                all[curr->OtherPoints[l]].WayLength = curr->WayLength+1;
                *mstackLen += 1;
                mstack[*mstackLen] = curr->OtherPoints[l];
            }
        }
        curr->isCalled = 1;
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int M, N, i, from, to;
    scanf("%d %d", &M, &N);
    for (i = 1; i <= 200001; i++){
        all[i].WayLength = -1;
        all[i].OtherPoints = NULL;
        all[i].amount = 0;
        all[i].isCalled = 0;
        mstack[i] = -1;
    }
    for (i = 0; i < N; i++){
        scanf("%d %d", &from, &to);
        all[from].amount++;
        all[from].OtherPoints = (int*)realloc(all[from].OtherPoints, 4*all[from].amount);
        all[from].OtherPoints[all[from].amount-1] = to;
    }
    /*
    for (i = 1; i <= M; i++){
        for (int j = 0; j < all[i].amount; j++){
            printf("**%d(%d): %d\n", i, all[i].amount, all[i].OtherPoints[j]);
        }
    }
    */
    int e = 0;
    mstack[0] = 1;
    i = 0;
    all[1].WayLength = 0;
    while(mstack[i] != -1){
        AvalanceMarking(&all[mstack[i]], &e);
        i++;
    }
    for (i = 1; i <= M; i++){
        printf("%d\n", all[i].WayLength);
    }
    return 0;
}
