#include<stdio.h>
#define max 100
#define BLACK 2
#define WHITE 0
#define GRAY 1
//変数
struct Graph{
  int u,k;
}graph[max];
int num,result[max][max],color[max],find[max],found[max],cnt_found;
int g[max][max];
//関数
void dfs();
void visit(int);

int main(){
  int i,j;
  scanf("%d",&num);
  for(i=0;i<num;i++){
      for(j=0;j<num;j++){
        result[i][j]=0;
      }
    }
  for(i=0;i<num;i++){
    color[i]=WHITE;
    find[i]=0;
    found[i]=0;
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

  dfs();
  return 0;
}
void dfs(){
  int u;
  cnt_found=0;
  for(u=1;u<num+1;u++){
  if(color[u]==WHITE){
    visit(u);
  }
  }
  for(u=1;u<num+1;u++){
    printf("%d %d %d\n",u,find[u],found[u]);
  }
}

void visit(int u){
  int v;
  color[u]=GRAY;
  find[u]=++cnt_found;
  for(v=1;v<num+1;v++){
    if(result[u][v]==0){
      continue;
    }
    if(color[v]==WHITE){
      visit(v);
    }
  }
  color[u]=BLACK;
  found[u]=++cnt_found;
}