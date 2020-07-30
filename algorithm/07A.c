#include<stdio.h>
#define max 100000
#define null -1

typedef struct{
    int parent,left,right;
}node;

node tree[max];
int num,depth[max];
/*
int Depth(int deep){
    d=0;
    while(tree[deep].parent!=-1){
        deep=tree[deep].parent
        d++;
    }
    return d;
} */

void record(int a,int p){
       depth[a]=p;
       if(tree[a].right!=null){
           record(tree[a].right,p);
       }
       if(tree[a].left!=null){
           record(tree[a].left,p+1);
       }
}

void pri(int result){
    int i,child;

    printf("node %d: ",result);
    printf("parent = %d, ",tree[result].parent);
    printf("depth = %d, ",depth[result]);

    if(tree[result].parent==null){
        printf("root, ");
    }else if(tree[result].left==null){
        printf("leaf, ");
    }else{
        printf("internal node, ");
    }

    printf("[");

    for(i=0,child=tree[result].left; child!=null; i++,child=tree[child].right){
      if(i){
          printf(", ");
      }
          printf("%d",child);
    }
    printf("]\n");
}

int main(){
     int i,j;
     int v,dep,child,left,right;

     scanf("%d",&num);

     for(i=0;i<num;i++){
         tree[i].parent=null;
         tree[i].left=null;
         tree[i].right=null;
     }

     for(i=0;i<num;i++){
       scanf("%d%d",&v,&dep);

        for(j=0;j<dep;j++){
            scanf("%d",&child);
            if(j==0){
                tree[v].left=child;
            }else{
                tree[left].right=child;
            }
            left=child;
            tree[child].parent=v;
        }
     }  
     for(i=0;i<num;i++){
         if(tree[i].parent==null){
             right=i;
         }
     }
      
      record(right,0);

     for(i=0;i<num;i++){
         pri(i);
     }
    return 0;
}