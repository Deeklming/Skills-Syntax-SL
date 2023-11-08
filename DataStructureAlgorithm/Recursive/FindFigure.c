//2차 배열에서 도형 찾기
#include <stdio.h>

#define n 6//도형 크기

void pr(char a[][n]){//출력
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n------------------------------\n\n");
}

void r(char t[][n], int a, int b){//재귀로 인접한 1 도형 찾기
    if(a<0 || a>=n || b<0 || b>=n) return;
    if(t[a][b]!=1) return;
    else t[a][b]=2;
    r(t, a+1, b);
    r(t, a, b+1);
    r(t, a-1, b);
    r(t, a, b-1);
}

int main(){
    char figure1[n][n] =
    {
        {0,0,1,1,1,0},
        {0,0,0,1,0,0},
        {0,1,1,0,0,0},
        {1,1,0,1,1,0},
        {1,0,0,0,1,0},
        {0,0,0,1,1,1},
    };
    char figure2[n][n] =
    {
        {0,0,1,1,1,0},
        {0,1,0,1,0,0},
        {0,1,1,1,0,0},
        {0,0,0,0,0,0},
        {1,0,0,1,0,1},
        {0,0,0,1,0,0},
    };

    int findFigure1 = 0;
    int findFigure2 = 0;

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(figure1[i][j]==1){
                ++findFigure1;
                r(figure1, i, j);
                printf("findFigure1 count: %d\n", findFigure1);
                pr(figure1);
            }
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(figure2[i][j]==1){
                ++findFigure2;
                r(figure2, i, j);
                printf("findFigure2 count: %d\n", findFigure2);
                pr(figure2);
            }
        }
    }

    printf("findFigure1: %d\n", findFigure1);
    printf("findFigure2: %d\n", findFigure2);
    return 0;
}