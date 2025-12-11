#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,inf=1e9;
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int n,m;
vector<int> a[N],d[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};
deque<node> Q;

void bfs(){
    for(int i=1;i<=n;i++){
        d[i].resize(m+1);
        for(int j=1;j<=m;j++){
            if(a[i][j]==1)d[i][j]=0,Q.push_back(node(i,j));
            else d[i][j]=inf;
        }
    }
    while(!Q.empty()){
        node p=Q.front();
        Q.pop_front();
        for(int w=0;w<4;w++){
            int x=p.x+dx[w],y=p.y+dy[w];
            if(1<=x&&x<=n&&1<=y&&y<=m&&d[x][y]==inf){
                d[x][y]=d[p.x][p.y]+1;
                Q.push_back(node(x,y));
            }
        }
    }
    return;
}

bool ck(int x){
    int lx=-inf,rx=inf,ly=-inf,ry=inf;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)if(d[i][j]>x){
            lx=max(lx,i+j-x),rx=min(rx,i+j+x);
            ly=max(ly,i-j-x),ry=min(ry,i-j+x);
        }
    }
    if(lx==rx&&ly==ry&&(lx+ly)%2==1)return false;
    return lx<=rx&&ly<=ry;
}

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        a[i].resize(m+1);
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    bfs();
    int L=0,R=n+m,ans=0;
    while(L<=R){
        int M=(L+R)/2;
        if(ck(M))ans=M,R=M-1;
        else L=M+1;
    }
    printf("%d\n",ans);
    return 0;
}


