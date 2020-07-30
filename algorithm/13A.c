#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 8
#define exist -1
#define not 1

int num;
int mat_r[max],mat_c[max],dp[2*max-1],dn[2*max-1];
struct Input{
  int r,c;
}in[max];
int queen[max][max];

void iniesta(){
 int i,j;
    for(i=0;i<max;i++){
        mat_r[i]=exist;
        mat_c[i]=exist;
    }
    for(i=0;i<2*max-1;i++){
        dp[i]=exist;
        dn[i]=exist;
    }
}

void print_queen(){
    int i,j;
    for(i=0;i<max;i++){
        for(j=0;j<max;j++){
            if(queen[i][j]){
                if(mat_r[i]!=j){
                    return ;
                }
            }
        }
    }
    for(i=0;i<max;i++){
        for(j=0;j<max;j++){
        if(mat_r[i]==j){
        printf("Q");
        }else{
            printf(".");
        }
     }
     printf("\n");
    }
    return ;
}
void solve_queen(int i){
    int j;
if(i==max){
    print_queen();
    return;
}
for(j=0;j<max;j++){
    if(mat_c[j]==not || dp[i+j]==not || dn[i-j+max-1]==not){
        continue;
    }
    mat_r[i]=j;
    mat_c[j]=not;
    dp[i+j]=not;
    dn[i-j+max-1]=not;
    solve_queen(i+1);
    mat_r[i]=exist;
    mat_c[j]=exist;
    dp[i+j]=exist;
    dn[i-j+max-1]=exist;
}
}
int main(){
  int i,j,r,c;
  //初期化
  for(i=0;i<max;i++){
    for(j=0;j<max;j++){
      queen[i][j]=0;
    }
  }
  iniesta();
  scanf("%d",&num);
  for(i=0;i<num;i++){
      scanf("%d %d",&in[i].r,&in[i].c);
      queen[in[i].r][in[i].c]=1;
    }
  //printf("%d,%d\n",in[0].r,in[0].c);
  solve_queen(0);
  return 0;
}
