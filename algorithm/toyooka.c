#include<stdio.h>
#include<stdlib.h>

int Puzzle[3][3];
int tmp[3][3];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void Empty(int *, int *);
void swap(int *, int *);
int Cal();
int DFS(int, int, int, int, int);

int main(){
  int i, j, l;
  int x, y, a;

  for(i = 0 ; i < 3 ; i++){
    for(j = 0 ; j < 3 ; j++){
      scanf("%d",&Puzzle[i][j]);
    }
  }

  Empty(&x,&y);
  printf("%d,%d\n",x,y);
  for(l = 0 ; l < 100 ; l++){
    for(i = 0 ; i < 3 ; i++){
      for(j = 0 ; j < 3 ; j++){
	tmp[i][j] = Puzzle[i][j];
      }
    }
    //printf("%d\n",tmp[2][2]);

    a = DFS(x, y, -1, 0, l);
    if(a != -1){
      //printf("%d\n",a);
      //printf("%d\n",l);
      break;
    }
//printf("after DFS\n");
    for(i = 0 ; i < 3 ; i++){
      for(j = 0 ; j < 3 ; j++){
	Puzzle[i][j] = tmp[i][j];
      }
    }
    
    a = -1;
   if(l == 99) printf("%d\n",a);
  }
//printf("befoer return\n");
  return 0;
}

void Empty(int *x, int *y){
  int i, j;

  for(i = 0 ; i < 3 ; i++){
    for(j = 0 ; j < 3 ; j++){
      if(!Puzzle[i][j]){
	*x = j;
	*y = i;
	return;
      }
    }
  }
}

void swap(int *a, int *b){
  int tmp;
  
  tmp = *a;
  *a = *b;
  *b = tmp;
}


int Cal(){
  int i, a;
  int sum = 0;

  for(i = 0 ; i < 9 ; i++){
    a = Puzzle[i/3][i%3];
    if(a){
      a--;
      sum += abs(i/3 - a/3)  + abs(i%3 - a%3);
    }
  }
printf("sun=%d\n",sum);
  return sum;
}

int DFS(int x, int y, int p, int dep, int limit){
  int i, h, nx, ny, res;
  //printf("aiueo\n");
  //h = Cal();
  
  if(Cal() == 0) {
      printf("%d\n",dep);
    return dep;
  }
  printf("計算:%d\n",Cal());
  if(dep + Cal() > limit) {
    //printf("kakikukeko\n");
    return -1;
  }
  for(i = 0 ; i < 4 ; i++){
    nx = x + dx[i];
    ny = y + dy[i];

    if(~p && i == (p+2)%4) {
      continue;
    }
    if(!(0 <= nx && nx < 3 && 0 <= ny && ny < 3)) {
      continue;
    }
    swap(&Puzzle[y][x], &Puzzle[ny][nx]);
    //]printf("%d\n",Puzzle[2][2]);
    res = DFS(nx, ny, i, dep+1, limit);
    //printf("%d\n",res);
    if(~res) {
      //printf("%d\n",res);
      return res;
    }
    swap(&Puzzle[y][x], &Puzzle[ny][nx]);
    //printf("after 2swap\n");
  }
  return -1;
}
    
