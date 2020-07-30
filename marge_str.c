#include<stdio.h>
#include<string.h>
#define N 20

void MergeSort(int left,int right,char a[N][N]);

void MergeSort(int left,int right,char a[N][N]){
  int m,i,j,k;
  char temp[N][N];
  
  //printf("%d,%d,%d\n",left,right,a[0]);
  if(left>=right){
    return;
  }
  //ここまではok
  
  m=(left+right)/2;
  //左側を再起で呼び出し
  MergeSort(left,m,a);
  //右側を呼び出し
  MergeSort(m+1,right,a);
  
  //a[left]からa[m]を作業領域にコピー
  for(i=left;i<=m;i++){
      strcpy(temp[i],a[i]);
  }

  //a[m+1]からa[right]を逆順にコピー　
  for(i=m+1,j=right;i<=right;i++,j--){
      strcpy(temp[i],a[j]);
  }

  i=left;
  j=right;
  //小さい方から配列に戻す
  for(k=left;k<=right;k++){
    if(strcmp(temp[i],temp[j])<0){
        strcpy(a[k],temp[i++]);
    }else{
        strcpy(temp[k],temp[j--]);
    }
  }
        
}

int main(){
  
  char str_arr[N][N]={"water","air","milk","coffee"};
  int length=sizeof(str_arr);

  MergeSort(0,length-1,str_arr);

  for(int i=0;i<length;i++){
    printf("%s ",str_arr[i]);
  }
  return 0;
}