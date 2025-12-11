#include <bits/stdc++.h>
using namespace std;

const int N=15,inf=1e9;
char s[N][N];
int n,m,f[N][N][N][N][N][N];
int X,Y;

struct node{
    int lx,rx,ly,ry,x,y;
    node(int lx=0,int rx=0,int ly=0,int ry=0,int x=0,int y=0):lx(lx),rx(rx),ly(ly),ry(ry),x(x),y(y){}
};
queue<node> Q;

void ck(int lx,int rx,int ly,int ry,int x,int y,int d){
    if(f[lx][rx][ly][ry][x][y]==inf){
        f[lx][rx][ly][ry][x][y]=d;
        Q.push(node(lx,rx,ly,ry,x,y));
    }
    return;
}

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++){
            if(s[i][j]=='T')X=i,Y=j;
        }
    }
    for(int lx=0;lx<N;lx++){
        for(int rx=0;rx<N;rx++){
            for(int ly=0;ly<N;ly++){
                for(int ry=0;ry<N;ry++){
                    for(int x=0;x<N;x++){
                        for(int y=0;y<N;y++)f[lx][rx][ly][ry][x][y]=inf;
                    }
                }
            }
        }
    }
    f[1][n][1][m][1][1]=0;
    Q.push(node(1,n,1,m,1,1));
    int ans=inf;
    while(!Q.empty()){
        node u=Q.front();
        Q.pop();
        int lx=u.lx,rx=u.rx,ly=u.ly,ry=u.ry,x=u.x,y=u.y;
        int p=0,dis=f[lx][rx][ly][ry][x][y];
        for(int i=lx;i<=rx;i++){
            for(int j=ly;j<=ry;j++)if(s[i][j]=='#')p=1;
        }
        if(!p){
            ans=dis;
            break;
        }
        int xl=rx-lx,yl=ry-ly;
        if(x<=X&&X<=x+xl&&y<=Y&&Y<=y+yl&&s[lx+(X-x)][ly+(Y-y)]=='#')continue;
        
        
        ck(x==1?lx+1:lx , rx , ly , ry , max(x-1,1) , y,dis+1);
        ck(lx , x+xl==n?rx-1:rx , ly , ry , min(x+1,n) , y,dis+1);
        ck(lx , rx , y==1?ly+1:ly , ry , x , max(y-1,1),dis+1);
        ck(lx , rx , ly , y+yl==m?ry-1:ry , x , min(y+1,m),dis+1);
    }
    if(ans==inf)ans=-1;
    printf("%d\n",ans);
    return 0;
}


