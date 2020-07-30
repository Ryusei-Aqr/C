#include<stdio.h>
#include<stdlib.h>
#define max 3
#define hund 100

int puz[max][max],swap[max][max];
int mat_x[4]={0,1,0,-1},mat_y[4]={1,0,-1,0};

void change(int *x, int *y){
  int tmp;
  
  tmp = *x;
  *x = *y;
  *y = tmp;
}
//ok
void emp(int *a, int *b){
    int i,j;
    for(i=0;i<max;i++){
        for(j=0;j<max;j++){
            if(!puz[i][j]){
                *a=j;
                *b=i;
                return;
            }
        }
    }
}
//ok
int calculation(){
    int i,x,sum=0;
    for(i=0;i<(max*max);i++){
        x=puz[i/max][i%max];
        if(x){
            x-=1;
            sum+=abs(i/max - x/max) + abs(i%max - x%max);
        }
    }
    printf("sun=%d\n",sum);
    return sum;
}
//ok

int depth_first_search(int a,int b,int lim,int depth,int point){
    int i,node_x,node_y,result;
    
    //printf("aiueo\n");
    if(calculation()==0){
        printf("%d\n",depth);
        return depth;
    }
     printf("計算:%d\n",calculation());
    if(depth + calculation() > lim){
        //printf("kakikukeko\n");
        return -1;
    }
    for(i=0;i<4;i++){
        node_x=a + mat_x[i];
        node_y=b + mat_y[i];
//ok
        if(~point && i == (point+2)%4){
            continue;
        }
        if(!(0 <= node_x && node_x < max && 0<=node_y && node_y < max)){
            continue;
        }
        change(&puz[b][a], &puz[node_y][node_x]);
        printf("%d\n",puz[2][2]);
        result=depth_first_search(node_x,node_y,lim,depth+1,i);
         printf("%d\n",result);
        if(~result){
            printf("%d\n",result);
            return result;
        }
        change(&puz[b][a],&puz[node_y][node_x]);
        printf("after 2change\n");
    }
    return -1;
}
//ok

//main ok
int main(){
    int i,j,k,a,b,d;
    for(i=0;i<max;i++){
        for(j=0;j<max;j++){
            scanf("%d",&puz[i][j]);
        }
    }
    /*
     for(i=0;i<max;i++){
        for(j=0;j<max;j++){
            printf("%d",puz[i][j]);
        }
        printf("\n");
    }*/

    //ok
emp(&a,&b);
printf("%d,%d\n",a,b);
for(i=0;i<hund;i++){
    for(j=0;j<max;j++){
        for(k=0;k<max;k++){
            swap[j][k]=puz[j][k];
        }
    }
    //printf("%d\n",swap[2][2]);//ここで無限ループ
    //ok
    //printf("debug_main:%d\n",i);
    //point,depth,lim
    d=depth_first_search(a,b,i,0,-1);
    if(d!=-1){
        printf("%d\n",d);
        //printf("debug_break:%d\n",i);
        break;
    }
    //printf("depth_first_search\n");
    /*ここでも無限ループ,本来はこいつがn回出力されて終わり*/
    for(i=0;i<max;i++){
        for(j=0;j<max;j++){
            puz[i][j]=swap[i][j];
        }
    }
    if(i==99){
        printf("-1\n");
    }
}
    return 0;
}//ok

/*
2 0 3
1 5 6
4 7 8
*/