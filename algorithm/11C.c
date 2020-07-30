#include<stdio.h>

struct Graph{
  int u,k;
}graph[max];

int num,result[max][max],color[max],find[max],found[max],cnt_found;
int g[max][max];

int main(){
  int i,j;
  scanf("%d",&num);
  for(i=0;i<vertex_num;i++){
      for(j=0;j<vertex_num;j++){
        result[i][j]=0;
      }
    }
  for(i=0;i<num;i++){
    color[i]=WHITE;
    find[i]=0;
    graph[i].u=0;
    graph[i].k=0;
  }
  for(i=1;i<num+1;i++){
    scanf("%d %d",&graph[i].u,&graph[i].k);
    for(j=1;j<(graph[i].k)+1;j++){
      scanf("%d",&g[i][j]);
      result[graph[i].u][g[i][j]]=1;
      }
  }

  dfs(0);
  return 0;
}