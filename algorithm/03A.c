#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top,s[100];

void push(int);
int pop(void);

int main(){
    int first,second;
    char stack[100];
    top=0;

    while(scanf("%s", stack)!=EOF){
        if(stack[0]=='+'){
            second=pop();
            first=pop();
            push(first+second);
        }else if(stack[0]=='-'){
            second=pop();
            first=pop();
            push(first-second);
        }else if(stack[0]=='*'){
            second=pop();
            first=pop();
            push(first*second);
        }else{
            push(atoi(stack));
        }
    }
    printf("%d\n",pop());
    return 0;
}

int pop(){
    top--;
    return s[top+1];
}

void push(int p){
    s[++top]=p;
}

