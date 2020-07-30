#include<stdio.h>
#include<string.h>

int x;

int main(){
    char str_arr[20][20]={"water","air","milk","coffee"};

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
        printf("%c",str_arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}