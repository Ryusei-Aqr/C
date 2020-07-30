//partitionSort
int partition(int part[],int start,int end){
  int x,i,j,temp;

  x=part[end];
  i=start-1;

  for(j=start;j<=end-1;j++){
    if(part[j]<=x){
        i+=1;
        //交換
        temp=part[i];
        part[i]=part[j];
        part[j]=temp;
      }
  }
    //交換
      temp=part[i+1];
      part[i+1]=part[end];
      part[end]=temp;
    return i+1;
}
