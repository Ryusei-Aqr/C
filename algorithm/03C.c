#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
  unsigned int key;
  struct node *next;
  struct node *prev;
};

typedef struct node * NodePointer;

NodePointer nil;
//与えられたキーをもつノードを探し、そのポインタを返す
NodePointer listSearch(int key){
    /* your code */
    NodePointer *x;
    x=&nil->next;
    while((*x)!=nil && (*x)->key!=key){
        x=&(*x)->next;
    }
    return *x;
}
//双方向連結リストの初期化
void init(){
  nil = malloc(sizeof(struct node));
  nil->next = nil;
  nil->prev = nil;
}

void printList(){
  NodePointer cur = nil->next;
  int isf = 1;
  while(1){
    if ( cur == nil ) break;
    if ( isf == 0)  printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
    isf = 0;
  }
  printf("\n");
}
//ポインタを繋ぎかえることで指定されたノードを削除する
void deleteNode(NodePointer t){
  /* your code */
  if(t==nil){
      return;
  }
  t->prev->next=t->next;
  t->next->prev=t->prev;
}

void deleteFirst(){
  NodePointer t = nil->next;
  if ( t == nil ) return;
  deleteNode(t);
}
//それぞれのノードのprevとnextが指すノードを削除する
void deleteLast(){
  /* your code */
  deleteNode(nil->prev);
}
//削除するキーが指定される、検索したノードの削除

void delete(int key){
  /* your code */
deleteNode(listSearch(key));
}

//与えられたキーをもつノードを生成しリストの先頭に追加する
void insert(int key){
  NodePointer x;
  x = malloc(sizeof(struct node));
  x->key = key;

  /* your code */
  //ni->nextが次のノードを指す
  x->next=nil->next;
  nil->next->prev=x;
  nil->next=x;
  x->prev=nil;
}

int main(){
  int key, n, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;
  scanf("%d", &n);
  init();
  for ( i = 0; i < n; i++ ){
    scanf("%s%d", com, &key);
    if ( com[0] == 'i' ) {insert(key); np++; size++;}
    else if ( com[0] == 'd' ) {
      if (strlen(com) > 6){
	if ( com[6] == 'F' ) deleteFirst();
	else if ( com[6] == 'L' ) deleteLast();
      } else {
	delete(key); nd++; 
      }
      size--;
    }
  }

  printList();
  return 0;
}