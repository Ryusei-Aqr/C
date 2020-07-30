#include<stdio.h>
#define max 1000
#define inf 100000

int vertex_num,admat[max][max];

int Prims(){
  int i,j,u,v,cost[max][max],min_distance;
  int visit[max],no_edges,min_cost,distance[max],from[max];
  
  for(i=0;i<vertex_num;i++){
    for(j=0;j<vertex_num;j++){
      if(admat[i][j]==0){
          cost[i][j]=inf;
      }else{
          cost[i][j]=admat[i][j];
      }
    }
  }
  distance[0]=0;
  visit[0]=1;

  for(i=1;i<vertex_num;i++){
      distance[i]=cost[0][i];
      from[i]=0;
      visit[i]=0;
  }
  min_cost=0;
  no_edges=vertex_num-1;

  while(no_edges>0){
     min_distance=inf;
     for(i=1;i<vertex_num;i++){
         if(visit[i]==0 && distance[i]<min_distance){
             v=i;
             min_distance=distance[i];
         }
     }
     u=from[v];
     no_edges--;
     visit[v]=1;
     for(i=1;i<vertex_num;i++){
         if(visit[i]==0 && cost[i][v]<distance[i]){
             distance[i]=cost[i][v];
             from[i]=v;
         }
     }
     min_cost+=cost[u][v];
  }
  
  return min_cost;
}

int main(){
  //admatは隣接行列
  int i,j;

  scanf("%d",&vertex_num);
  for(i=0;i<vertex_num;i++){
    for(j=0;j<vertex_num;j++){
      scanf("%d",&admat[i][j]);
    }
  }
  for(i=0;i<vertex_num;i++){
    for(j=0;j<vertex_num;j++){
       if(admat[i][j]==-1){
           admat[i][j]=0;
       }
       //printf("%d ",admat[i][j]);
    }
  }
  
  printf("%d\n",Prims());
  return 0;
}
