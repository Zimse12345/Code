#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
const int N = 512,inf=1e9;
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int read(){
    int x = 0,f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int n,m,sx,sy,tx,ty,dis[N][N][2],vis[N][N][2];
char s[N][N];
struct node{
    int x,y,z,v;
    node(int x=0,int y=0,int z=0,int v=0):x(x),y(y),z(z),v(v){}
    bool operator < (const node& _)const{return v>_.v;}
};
priority_queue<node> Q;
inline void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++){
            if(s[i][j]=='S')sx=i,sy=j;
            if(s[i][j]=='G')tx=i,ty=j;
            dis[i][j][0]=dis[i][j][1]=inf;
        }
    }
    dis[sx][sy][0]=0;
    Q.push(node(sx,sy,0,0));
    while(!Q.empty()){
        int x=Q.top().x,y=Q.top().y,z=Q.top().z;
        Q.pop();
        if(vis[x][y][z]++)continue;
        for(int w=0;w<4;w++){
            int xx=x+dx[w],yy=y+dy[w];
            if(!(1<=xx&&xx<=n&&1<=yy&&yy<=m))continue;
            if(s[xx][yy]=='#')continue;
            if(s[xx][yy]=='x'&&z==0)continue;
            if(s[xx][yy]=='o'&&z==1)continue;
            int zz=z;
            if(s[xx][yy]=='?')zz^=1;
            if(dis[x][y][z]+1<dis[xx][yy][zz]){
                dis[xx][yy][zz]=dis[x][y][z]+1;
                Q.push(node(xx,yy,zz,dis[xx][yy][zz]));
            }
        }
    }
    int ans=min(dis[tx][ty][0],dis[tx][ty][1]);
    if(ans==inf)ans=-1;
    printf("%d\n",ans);
}
int main() {
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}

