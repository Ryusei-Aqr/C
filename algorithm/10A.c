#include<stdio.h>

int main(){
    long long i,num,fibo0,fibo1,fibo2;
    scanf("%lld",&num);
    i=0;
    fibo0=0;
    fibo1=1;
    while(i<num){
        //printf("%d回目 :",i+1);
        fibo2=fibo1+fibo0;
        //printf("sum = %d\n",fibo2);
        fibo0=fibo1;
        fibo1=fibo2;
        ++i;
  }
  //printf("Finally sum %d or %d or %d\n",fibo0,fibo1,fibo2);
  printf("%lld\n",fibo2);
  return 0;
}