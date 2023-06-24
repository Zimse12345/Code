// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
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
const double eps=1e-9;
int n,m,ans[N];

struct point{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){}
}p[N];
vector<int> s[2];

struct Dinic{
    int sz,Source,Sink,hd[N],h[N],nxt[N],ec,d[N];
    struct Arc{
        int v,f;
        Arc(int v=0,int f=0):v(v),f(f){}
    }E[N];
    inline void init(){for(int i=1;i<=sz;i++)hd[i]=0;ec=1,sz=0;return;}
    inline void link(int u,int v,int f){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=Arc(v,f);return;}
    inline void Link(int u,int v,int f){link(u,v,f),link(v,u,0);return;}

    queue<int> Q;
    bool bfs(){
        for(int i=1;i<=sz;i++)d[i]=0;
        d[Source]=1,Q.push(Source);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(int i=hd[u];i;i=nxt[i])if(E[i].f&&!d[E[i].v])d[E[i].v]=d[u]+1,Q.push(E[i].v);
        }
        return d[Sink];
    }

    int dfs(int u,int maxf){
        if(u==Sink||!maxf)return maxf;
        int flow=0;
        for(int i=h[u];i;i=nxt[i]){
            if(d[u]+1==d[E[i].v]){
                int f=dfs(E[i].v,min(maxf,E[i].f));
                flow+=f,maxf-=f,E[i].f-=f,E[i^1].f+=f;
                if(!maxf)break;
            }
            h[u]=nxt[h[u]];
        }
        if(!flow)d[u]=0;
        return flow;
    }

    int dinic(int source,int sink){
        Source=source,Sink=sink;
        int res=0;
        while(bfs()){
            for(int i=1;i<=sz;i++)h[i]=hd[i];
            res+=dfs(Source,INF);
        }
        return res;
    }
}f;

inline double Dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline bool eq(point a,point b){
    return abs(a.x-b.x)<eps&&abs(a.y-b.y)<eps;
}

inline bool Inline(point a,point b,point c){
    if(eq(a,b)||eq(a,c)||eq(b,c))return true;
    if(abs(a.x-b.x)<eps&&abs(a.x-c.x)<eps)return true;
    if(abs(a.x-b.x)<eps||abs(a.x-c.x)<eps||abs(b.x-c.x)<eps)return false;
    return abs((a.y-b.y)/(a.x-b.x)-(a.y-c.y)/(a.x-c.x))<eps;
}

signed main(){
    iF("challenge.in");
    oF("challenge.out");

    n=read(),m=read();
    for(int i=1,x,y;i<=n;i++){
        x=read(),y=read();
        p[i]=point(x,y);
    }
    ans[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            point a=p[i],b=p[j];
            double d=Dis(a,b);
            int t=2;
            for(int k=1;k<=n;k++)if(k!=i&&k!=j){
                point c=p[k];
                if(Dis(a,c)>d+eps||Dis(b,c)>d+eps)continue;
                if(Inline(a,b,c)){
                    ++t;
                    continue;
                }
                int w=0;
                if(abs(a.x-b.x)<eps){
                    if(c.x>a.x)w=1;
                }
                else{
                    double K=(a.y-b.y)/(a.x-b.x);
                    double B=a.y-K*a.x;
                    double pos=K*c.x+B;
                    if(c.y>pos)w=1;
                }
                s[w].pb(k);
            }
            f.init();
            int s0=s[0].size(),s1=s[1].size(),S=s0+s1+1,T=S+1;
            f.sz=T;
            for(int u=0;u<s0;u++)f.Link(S,u+1,1);
            for(int v=0;v<s1;v++)f.Link(s0+v+1,T,1);
            for(int u=0;u<s0;u++){
                for(int v=0;v<s1;v++){
                    if(Dis(p[s[0][u]],p[s[1][v]])>d+eps)f.Link(u+1,s0+v+1,1);
                }
            }
            int mx=f.dinic(S,T);
            _max(ans[int(ceil(d))],t+s0+s1-mx);
            s[0].resize(0),s[1].resize(0);
        }
    }
    for(int i=0;i<=m;i++){
        if(i)_max(ans[i],ans[i-1]);
        wri(ans[i]);
    }
    pc(10);
    return 0;
}

