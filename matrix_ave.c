#include<stdio.h>
#define N 3
int main(){
     int mat[N][N]={{65,80,95,},
                    {70,68,75},
                    {60,98,88}};
    int i,j;
    double row_sum=0,col_sum=0;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           printf("%3d",mat[i][j]);
        }
        printf("\n");
    }
    printf("行の平均\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           row_sum+=mat[i][j];
           //col_sum+=mat[j][i];
        }
        printf("%d行目の平均：%lf\n",i+1,(double)row_sum/3.0);
        //printf("%d列目の平均：%lf\n",j+1,(double)col_sum/N);
        //初期化
        row_sum=0;
        //col_sum=0;
    }
    printf("列の平均\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           //row_sum+=mat[i][j];
           col_sum+=mat[j][i];
        }
        //printf("%d行目の平均：%lf\n",i+1,(double)row_sum/N);
        printf("%d列目の平均：%lf\n",i+1,(double)col_sum/3.0);
        //初期化
        //row_sum=0;
        col_sum=0;
    }
    return 0;
}