/* コッホ曲線　異なる三点を決めて二つを頂点とする */
#include<math.h>
#include<stdio.h>
struct Point{
double x,y;
};
double theata = M_PI*60.0/180.0;

void koch(int num, struct Point p1, struct Point p2){
    struct Point s,t,u;
    //printf("Debug:%d %f %f ",num,p1.x,p2.x);
    if(num==0){
        return ;
    }

    s.x=(2.0*p1.x+1.0*p2.x)/3.0;
    s.y=(2.0*p1.y+1.0*p2.y)/3.0;
    t.x=(1.0*p1.x+2.0*p2.x)/3.0;
    t.y=(1.0*p1.y+2.0*p2.y)/3.0;
    u.x=(t.x-s.x)*cos(theata)-(t.y-s.y)*sin(theata)+s.x;
    u.y=(t.x-s.x)*sin(theata)+(t.y-s.y)*cos(theata)+s.y;

    /* p1とp2から s,t,u を計算 再帰的に求める*/
    koch(num-1,p1,s);
    printf("%.8f %.8f\n",s.x,s.y);
    koch(num-1,s,u);
    printf("%.8f %.8f\n",u.x,u.y);
    koch(num-1,u,t);
    printf("%.8f %.8f\n",t.x,t.y);
    koch(num-1,t,p2);
}

int main(){
    struct Point p1,p2;\
    int num;
    p1.x=0;
    p1.y=0;
    p2.x=100;
    p2.y=0;
    scanf("%d",&num);
    //端点
    printf("%.8f %.8f\n",p1.x,p1.y);
    koch(num,p1,p2);
    //端点
    printf("%.8f %.8f\n",p2.x,p2.y);

    return 0;
}