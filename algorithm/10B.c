#include<stdio.h>
#include<math.h>
#define ROW 1000
#define COLUM 1000
#define infinity 10000000
//動的計画法を用いた連鎖行列積
//行列のテーブルを作ってi番目からj番目までの行列をかけた際最小のコスト
int main(){
    int i,j,k,num,mat[ROW+1][COLUM+1],length,q,p[ROW+1],minimum;
    scanf("%d",&num);
    //初期化
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
        mat[i][j]=0;
        }
    }
    for(i=1;i<=num;i++){
        scanf("%d%d",&p[i-1],&p[i]);
    }
    for(i=1;i<=num;i++){
    //printf("確認：%d番目:%d,%d\n",i,p[i-1],p[i]);
    }
    /* MatrixChainOrder */
    //MatrixchainOrderの実装
for(length=2;length<=num;length++){
    for(i=1;i<=num-length+1;i++){
        j=i+length-1;
         mat[i][j]=infinity;
        for(k=i;k<=j-1;k++){
            q=mat[i][k]+mat[k+1][j]+(p[i-1]*p[k]*p[j]);
            //printf("計算結果: %d\n",q);
            if(q<mat[i][j]){
                mat[i][j]=q;
            }
        }
    }
}
/*
for(i=0;i<num;i++){
    for(j=0;j<num;j++){
        printf("%d行%d列目：%d\n",i,j,mat[i][j]);
    }
  }*/
  printf("%d\n",mat[1][num]);
    return 0;
}
/* わかったこと
二次元配列は10000個の要素は用意できない
無限大を使う際はINFINITYは使わない方がいい */