#include<stdio.h>
#define max 100000
int size;

double parent(int h){
    return h/2;
}
int left(int i){
    return 2*i;
}
int right(int i){
    return 2*i+1;
}

int main(){
    int A[max+1],i,p,r,l;
    scanf("%d",&size);
    //二分岐には0が存在しないので１から始める
    for(i=1;i<=size;i++){
        scanf("%d",&A[i]);
    }
    for(i=1;i<=size;i++){
        printf("node %d: key = %d, ",i,A[i]);
        if((p=parent(i)) >= 1){
             printf("parent key = %d, ",A[p]);
        }
        if((l=left(i))<= size){
            printf("left key = %d, ",A[l]);
        }else{
            //printf("\n");
        }
         if((r=right(i)) <= size){
            printf("right key = %d, \n",A[r]);
        }else{
            printf("\n");
        }
    }
    return 0;
}