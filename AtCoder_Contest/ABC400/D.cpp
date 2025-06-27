#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},inf=1e9;
int n,m,sx,sy,tx,ty;
char s[N][N];
int d[N][N],vis[N][N];

struct node{
    int x,y,d;
    node(int x=0,int y=0,int d=0):x(x),y(y),d(d){}
    bool operator < (const node& _)const{return d>_.d;}
};
priority_queue<node> Q;

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++)d[i][j]=inf;
    }
    cin>>sx>>sy>>tx>>ty;
    d[sx][sy]=0;
    Q.push(node(sx,sy,0));
    while(!Q.empty()){
        int x=Q.top().x,y=Q.top().y;
        Q.pop();
        if(vis[x][y]++)continue;
        for(int i=0;i<4;i++){
            int _x=x+dx[i],_y=y+dy[i],_d=d[x][y]+(s[_x][_y]=='.'?0:1);
            if(_x>0&&_x<=n&&_y>0&&_y<=m&&_d<d[_x][_y]){
                d[_x][_y]=_d;
                Q.push(node(_x,_y,_d));
            }
            _x+=dx[i],_y+=dy[i],_d=d[x][y]+1;
            if(_x>0&&_x<=n&&_y>0&&_y<=m&&_d<d[_x][_y]){
                d[_x][_y]=_d;
                Q.push(node(_x,_y,_d));
            }
        }
    }
    printf("%d\n",d[tx][ty]);
    return 0;
}


