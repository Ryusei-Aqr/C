#include<stdio.h>
#define max 1000
#define inf 1000000
#define b 2
#define w 0
#define true 1
int vertex_num,admat[max][max];

void Dijkstra(){
  int vertex,min_vertex;
  struct d{
  int distance,parent,color;
  }dijk[max];
  
  int i,j;
  //初期化
  for(i=0;i<vertex_num;i++){
    dijk[i].distance=inf;
    dijk[i].color=w;
  }
  
  dijk[0].distance=0;
  dijk[0].color=1;
  
  while(true){
    min_vertex=inf;
    vertex=-1;
    for(i=0;i<vertex_num;i++){
      if(dijk[i].distance<min_vertex && dijk[i].color!=b){
        vertex=i;
        min_vertex=dijk[i].distance;
      }
    }
    if(vertex==-1){
      break;
    }
    dijk[vertex].color=b;
    for(i=0;i<vertex_num;i++){
      if(dijk[i].color!=b && admat[vertex][i]!=inf){
        if(dijk[vertex].distance+admat[vertex][i]<dijk[i].distance){
          dijk[i].distance=dijk[vertex].distance+admat[vertex][i];
          dijk[i].color=1;
        }
      }
    }
  }
  for(i=0;i<vertex_num;i++){
    printf("%d ",i);
    if(dijk[i].distance==inf){
      printf("-1\n");
    }else{
      printf("%d\n",dijk[i].distance);
    }
  }
}




int main(){
  int i,j;
  int vertex,num,min_ver;

  scanf("%d",&vertex_num);
  for(i=0;i<vertex_num;i++){
    for(j=0;j<vertex_num;j++){
    admat[i][j]=inf;
    }
  }
  
  for(i=0;i<vertex_num;i++){
    scanf("%d",&vertex);
    scanf("%d",&num);
    for(j=0;j<num;j++){
      scanf("%d",&min_ver);
      scanf("%d",&admat[vertex][min_ver]);
    }
  }
  Dijkstra();
  return 0;
}

/*この問題はダイクストラ法、単一始点最短経路に関する問題
入力
5
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3
出力
0 0
1 2
2 2
3 1
4 3
*/

