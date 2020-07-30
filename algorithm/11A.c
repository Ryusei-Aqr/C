#include<stdio.h>
#define max 100
struct Graph{
  int u,k;
};
struct Graph graph[max];
int g[max][max];
int result[max][max];
int main(){
  int num,i,j;
  scanf("%d",&num);
  //初期化
  for(i=0;i<num;i++){
      for(j=0;j<num;j++){
        result[i][j]=0;
         g[i][j]=0;
      }
    }
  for(i=0;i<num;i++){
    graph[i].u=0;
    graph[i].k=0;
  }
  
  for(i=1;i<num+1;i++){
    scanf("%d %d",&graph[i].u,&graph[i].k);
    for(j=1;j<(graph[i].k)+1;j++){
      scanf("%d",&g[i][j]);//一つしか入力できないのに二つやろうとしているためできない
      result[graph[i].u][g[i][j]]=1;
      }
  }
  //result[1][1]=2;
  //out
  for(i=1;i<num+1;i++){
    for(j=1;j<num;j++){   
      printf("%d ",result[i][j]);
      //printf("u,%d:k,%d\n",graph[i].u,graph[i].k);
      //printf("%d",result[i][j+1]);
    }
      printf("%d\n",result[i][num]);
  }
  
  
  return 0;
}
