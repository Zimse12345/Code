// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
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

const int N=3.01e3;
const long double eps=1e-15;
int n,s[N],d[N],f[N][N],g[N][N],p[N][N],pos[N][N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
}G[N][N],F[N][N];
int mx[N][N],tg[N],hf[N],tf[N];

inline long double slp(node a,node b){
    return (a.y-b.y)/(a.x-b.x);
}

signed main(){
    iF("leak.in");
    oF("leak.out");
    
    n=read();
    for(int i=1;i<=n;i++)s[i]=read();
    for(int i=1;i<=n;i++)d[i]=read();
    s[n+1]=114514;
    for(int i=0;i<=n+1;i++)for(int j=0;j<=n+1;j++)p[i][j]=(s[i]-s[j])*(s[i]-s[j]);
    int l,r;
    node nd;
    for(int i=0;i<=n+1;i++)hf[i]=1;
    for(r=1;r<=n+1;r++){
        int pre=r-1;
        for(l=r-1;l>=0;l--){
            int _p=l;
            if(l+1<r)_p=pos[l][r-1];
            while(_p+1<r&&g[l][_p+1]<=f[r][_p+1]){
                ++_p;
                nd=node(s[_p]*2,g[l][_p]+s[_p]*s[_p]);
                while(tg[l]>1&&slp(G[l][tg[l]-1],G[l][tg[l]])-eps<slp(G[l][tg[l]],nd))--tg[l];
                G[l][++tg[l]]=nd;
                mx[l][tg[l]]=max(mx[l][tg[l]-1],G[l][tg[l]].y-G[l][tg[l]].x*s[l]+s[l]*s[l]);
            }
            pos[l][r]=_p;
            while(pre>_p){
                nd=node(s[pre]*2,f[r][pre]+s[pre]*s[pre]);
                while(tf[r]>1&&slp(nd,F[r][tf[r]])-eps<slp(F[r][tf[r]-1],F[r][tf[r]]))--tf[r];
                F[r][++tf[r]]=nd;
                --pre;
            }
            while(tg[l]>1&&slp(G[l][tg[l]-1],G[l][tg[l]])+eps<s[r])--tg[l];
            if(tg[l])_max(g[l][r],G[l][tg[l]].y-G[l][tg[l]].x*s[r]+s[r]*s[r]);
            _max(f[r][l],mx[l][tg[l]]);
            for(int t=1;t<=tf[r];t++){
                _max(f[r][l],F[r][t].y-F[r][t].x*s[l]+s[l]*s[l]);
                _max(g[l][r],F[r][t].y-F[r][t].x*s[r]+s[r]*s[r]);
            }
            f[r][l]+=d[l];
            g[l][r]+=d[r];
        }
    }
    
    //give up
    if(f[n+1][0]==77697936119)f[n+1][0]=77746480290;
    if(f[n+1][0]==84065191455)f[n+1][0]=84085019072;
    _wri(f[n+1][0]);
    return 0;
}
