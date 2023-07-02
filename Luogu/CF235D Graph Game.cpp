// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
// #define int long long
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e6;
int T,n,m,hd[N],nxt[N],to[N],ec,vis[N];
int stk[N],top,ring[N],len,inring[N],instk[N];
double ans;

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs(int u,int from){
    stk[++top]=u,instk[u]=1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        if(instk[v]){
            while(stk[top+1]!=v)inring[stk[top]]=1,ring[++len]=stk[top--];
            return;
        }
        dfs(v,u);
        if(len)return;
    }
    --top,instk[u]=0;
    return;
}

void dfs2(int u,int x,int y){
    vis[u]=1;
    if(y<=1)ans+=1.0/(x+y);
    else{
        int X=x+2,Y=y-2,Z=len-y;
        ans+=1.0/(X+Y)+1.0/(X+Z)-1.0/(X+Y+Z);
    }
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v])continue;
        dfs2(v,x+(inring[v]^1),y+inring[v]);
    }
    return;
}

signed main(){
    n=read();
    for(int i=1,u,v;i<=n;i++){
        u=read()+1,v=read()+1;
        add(u,v),add(v,u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)vis[j]=0;
        dfs2(i,inring[i]^1,inring[i]);
    }
    printf("%.7lf\n",ans);
    return 0;
}

