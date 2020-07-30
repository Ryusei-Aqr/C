#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define true 1
#define false 0

int isPrime(int);
int main(){
    int x,*prime,i,cnt=0,p;
    //要素数の決定
    scanf("%d",&x);
    prime=malloc(sizeof(int)*(x+1));
    //素数入力と判定
    for(i=0;i<x;i++){
    scanf("%d",&prime[i]);
    }
    for(i=0;i<x;i++){
       p=isPrime(prime[i]);
       
       if(p==false){
           cnt+=0;
           //printf("false\n");
       }else{
           cnt+=1;
           //printf("true\n");
       }
    }
     printf("%d\n",cnt);    
    free(prime);
    return 0;
}

int isPrime(int a){
    int i=3;
        if(a==1){
            return false;
        }
        else if(a>2 && a%2==0){
            return false;
        }
        while(i<=sqrt(a)){
             if(a%i==0){
                return false;
             }
             i+=2;
        }
    return true;
}
