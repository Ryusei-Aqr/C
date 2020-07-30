#include<stdio.h>
#include<math.h>//マイナス無限大を使うためにインクルードする
#include<string.h>
#define Max 2000000

int size,A[Max];

int RIGHT(int a){
    return 2*a+1;
}
int LEFT(int a){
    return 2*a;
}
int PARENT(int a){
    return a/2;
}

void maxheapify(int i){
    int left,right,largest;
    int temp=0;
    left=LEFT(i);
    right=RIGHT(i);
    if(left<=size && A[left]>A[i]){
        largest=left;
        }else{
            largest=i;
        }
    if(right<=size && A[right]>A[largest]){
        largest=right;
    }
    if(largest!=i){
        //swap
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        maxheapify(largest);
    }
}

void Increase(int i,int key){
    int temp;
    if(key<A[i]){
        //printf("key is smaller than presently number\n");
    }
    A[i]=key;
    while(i > 1 && A[PARENT(i)] < A[i]){
        temp=A[i];
        A[i]=A[PARENT(i)];
        A[PARENT(i)]=temp;

        i=PARENT(i);
    }
}

//集合Aに要素を挿入する
void Insert(int key){
    size+=1;
    A[size]=-INFINITY;
    Increase(size,key);
}

//Aから最大のキーをもつ要素を削除し、その要素を返す
int Extract(){
    int maximum;
    if(size < 1){
        //printf("Heap under flow\n");
        return -INFINITY;
    }
    maximum=A[1];
    A[1]=A[size--];
    maxheapify(1);
    return maximum;
}



int main(){
    char text[8];
    char moji1[7]="insert";
    char moji2[8]="extract";
    char owari[4]="end";
    int num,i,j=0;
    
    while(1){
        scanf("%s",text);
        if(text[0]=='e' && text[2]=='d'){
            return 0;
        }
        //insert
        if(text[0]=='i'){
            scanf("%d",&num);
            Insert(num);
        }//extract
        else{
            printf("%d\n",Extract());
        }
   j++;
    }
    return 0;
}