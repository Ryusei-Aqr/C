//トランプの整理
#include<stdio.h>
#define sum 54
#define false 0
#define true 1
int n,q,w;
//構造体配列を使う時はこのように宣言する
struct trump{
    int num;
    char sym;
};

void swap(struct trump a[q],struct trump b[w]){
    struct trump temp;
    temp=a[q];
    a[q]=b[w];
    b[w]=temp;
}
//出力
void out(struct trump c[]){
    for(int i=0;i<n-1;i++){
     printf("%c%d ",c[i].sym,c[i].num);
    }
    printf("%c%d\n",c[n-1].sym,c[n-1].num);
}
//安定かどうかを調べる
int isStable(struct trump c1[],struct trump c2[]){
    int i;
    for(i=0;i<n;i++){
      if(c1[i].sym!=c2[i].sym){
        return false;
      }
    }
    return true;
}
//バブルソート、隣どうしを比較するので安定
void bubble(struct trump c[]){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=n-1;j>i;j--){
            if(c[j].num < c[j-1].num){
                swap(&c[j],&c[j-1]);
            }
        }
    }
}
//選択ソート、最小値を見つけて挿入するので不安定
void Selection(struct trump c[]){
    int i,j,minj;
    for(i=0;i<n-1;i++){
        minj=i;
        for(j=i+1;j<n;j++){
            if(c[j].num < c[minj].num){
                minj=j;
            }
        }
        if(minj!=i){
            swap(&c[i],&c[minj]);
        }
    }
}

int main(){
    int i,j;
    struct trump card[sum],Bcard[sum],Scard[sum];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        //一文字読み込むためにスペースを開ける必要がある
        scanf(" %c%d",&card[i].sym, &card[i].num);
    }
    //カードのコピー
    for(i=0;i<n;i++){
        Bcard[i]=card[i];
        Scard[i]=card[i];
    }
    //出力
    bubble(Bcard);
    Selection(Scard);
    out(Bcard);
    printf("Stable\n");
    out(Scard);
     if(isStable(Bcard,Scard)){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }
    return 0;
}
/* 構造体配列を渡す際は
   構造体配列名で渡し
   struct 構造体名　引数とする構造体の名前で受け取る */