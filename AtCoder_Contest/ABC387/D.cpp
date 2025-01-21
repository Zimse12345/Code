#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3,inf=1e9;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int n,m,f[N][N][2],vis[N][N][2],ans;
char s[N][N];
struct node{
    int x,y,w,d;
    node(int x=0,int y=0,int w=0,int d=0):x(x),y(y),w(w),d(d){}
    bool operator < (const node& _)const{return d>_.d;}
};
priority_queue<node> Q;

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++){
            f[i][j][0]=f[i][j][1]=inf;
            if(s[i][j]=='S'){
                f[i][j][0]=f[i][j][1]=0;
                Q.push(node(i,j,0,0));
                Q.push(node(i,j,1,0));
            }
        }
    }
    while(!Q.empty()){
        int x=Q.top().x,y=Q.top().y,w=Q.top().w,d=Q.top().d;
        Q.pop();
        if(vis[x][y][w]++)continue;
        for(int W=w*2;W<w*2+2;W++){
            int _x=x+dx[W],_y=y+dy[W];
            if(_x<1||_x>n||_y<1||_y>m||s[_x][_y]=='#')continue;
            if(d+1<f[_x][_y][w^1]){
                f[_x][_y][w^1]=d+1;
                Q.push(node(_x,_y,w^1,d+1));
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)if(s[i][j]=='G'){
            ans=min(f[i][j][0],f[i][j][1]);
            if(ans==inf)ans=-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}


