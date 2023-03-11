/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
// #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
const int INF=114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=2048;

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
}preF[N][N],pref[N*2][3][N];

int n,m,vis[N],col[N],f[N*2][3][N],Tag,sz[N];
int id[N],nxt[N*2],pre[N*2],V[N*2],tf;
int F[N][N],Sz,ans,rt[N];
char str[N][N];
int A,B,C,D;
queue<int> aa,bb;
queue<node> cc;
vector<int> g[N];

void dfs(int u,int from){
    for(int val=0;val<3;val++)for(int x=0;x<=1;x++)f[u][val][x]=INF;
    vis[u]=1,sz[u]=1,col[u]=(u<=n?0:1),id[u]=u;
    f[u][0][0]=0;
    if(col[u])f[u][1][1]=0;
    else f[u][1][0]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        if(vis[v])Tag=1;
        else{
            dfs(v,u);
            ++tf;
            for(int val=0;val<3;val++)for(int x=0;x<=sz[u]+sz[v];x++)f[tf][val][x]=INF;
            for(int val=0;val<3;val++){
                for(int _val=0;_val<3;_val++){
                    int _v=(_val%2)^1;
                    if(val+_v>2)continue;
                    for(int x=0;x<=sz[u];x++){
                        for(int y=0;y<=sz[v];y++){
                            if(f[id[u]][val][x]+f[id[v]][_val][y]<f[tf][val+_v][x+y]){
                                f[tf][val+_v][x+y]=f[id[u]][val][x]+f[id[v]][_val][y];
                                pref[tf][val+_v][x+y]=node(_val,y);
                            }
                        }
                    }
                }
            }
            sz[u]+=sz[v],nxt[id[u]]=tf,pre[tf]=id[u],id[u]=tf,V[tf]=v;
        }
    }
    return;
}

void dfs2(int u,int val,int x){
    if(x+f[id[u]][val][x]==0)return;
    while(id[u]!=u){
        node p=pref[id[u]][val][x];
        dfs2(V[id[u]],p.x,p.y);
        id[u]=pre[id[u]],val-=(p.x%2)^1,x-=p.y;
    }
    if(val){
        if(!col[u]){
            if(!bb.empty())str[u][bb.front()]='#',bb.pop();
            else str[u][cc.front().y]='#',cc.pop();
        }
        else{
            if(!aa.empty())str[aa.front()][u-n]='#',aa.pop();
            else str[cc.front().x][u-n]='#',cc.pop();
        }
    }
    return;
}

signed main(){
    n=read(),m=read(),tf=n+m;
    for(int i=1;i<=n;i++){
        scanf("%s",str[i]+1);
        for(int j=1;j<=m;j++)if(str[i][j]=='#')g[i].pb(j+n),g[j+n].pb(i);
    }
    int tot=0;
    for(int i=1;i<=n+m;i++)if(!vis[i]){
        dfs(i,0);
        if(Tag){
            _write(-1);
            return 0;
        }
        rt[++tot]=i;
        for(int x=0;x<=Sz+sz[i];x++)F[tot][x]=INF;
        for(int val=0;val<3;val+=2){
            for(int x=0;x<=Sz;x++){
                for(int y=0;y<=sz[i];y++){
                    if(F[tot-1][x]+f[id[i]][val][y]<F[tot][x+y]){
                        F[tot][x+y]=F[tot-1][x]+f[id[i]][val][y];
                        preF[tot][x+y]=node(val,y);
                    }
                }
            }
        }
        Sz+=sz[i];
        if(sz[i]==1){
            if(col[i])++B,bb.push(i-n);
            else ++A,aa.push(i);
        }
        else if(f[id[i]][0][0]==0||f[id[i]][2][0]==0){
            ++C;
            if(col[i])cc.push(node(g[i][0],i-n));
            else cc.push(node(i,g[i][0]-n));
        }
        else ++D;
    }
    ans=INF;
    for(int x=0,y=0;x<=Sz;x++){
        y=F[tot][x];
        if(max(0,x-A)+max(0,y-B)<=C+max(0,D-1)){
            _min(ans,x+y);
        }
    }
    if(ans==INF)ans=-1;
    _write(ans);
    for(int x=0,y=0;x<=Sz;x++){
        y=F[tot][x];
        if(max(0,x-A)+max(0,y-B)<=C+max(0,D-1)){
            if(ans==x+y){
                while(tot){
                    node p=preF[tot][x];
                    int v=rt[tot];
                    dfs2(v,p.x,p.y);
                    if(sz[v]==1){
                        if(col[v])bb.push(v-n);
                        else aa.push(v);
                    }
                    else{
                        if(col[v])cc.push(node(g[v][0],v-n));
                        else cc.push(node(v,g[v][0]-n));
                    }
                    x-=p.y,--tot;
                }
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++)pc(str[i][j]);
                    pc(10);
                }
                return 0;
            }
        }
    }
    return 0;
}
