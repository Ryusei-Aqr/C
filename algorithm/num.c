#include <stdio.h>

#define N 1000000

int main(){

  int i,j,k,swap,x,array[101];
  FILE fp;

  fp = fopen("C.txt","r");

  for(i = 0;i < N;i ++)
    {
      fscanf(fp,"%d ",&x);
      if(i <= 100)
        k = i;
      else
        k = 100;
      array[k] = x;
      for(j = k ; j > 0 ; j--){
        if(array[j] > array[j-1])
          {
            swap = array[j];
            array[j] = array[j-1];
            array[j-1] = swap;
          }
      }
    }

  /*for(i = 0 ; i < N ; i++)
    {
      printf("%d ",array[i]);
      }*/


  printf("%d\n",array[99]);



  return 0;
}

/* これは配列の100番目を求める問題 */