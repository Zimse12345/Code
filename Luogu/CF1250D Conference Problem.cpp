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

const int N=1.01e3;
int T,n,m,v[N],tot,num,f[N][N],ans,g[N],s[N][N],a[N];
map<int,int> mp;

struct node{
    int l,r,c;
    node(int l=0,int r=0,int c=0):l(l),r(r),c(c){}
    bool operator < (const node &_)const{return r<_.r;}
}p[N];

inline void add(int &x,int y){
    if(x==-1||y==-1)x=-1;
    else if(!x)x=y;
    else if(y&&x!=y)x=-1;
    return;
}

signed main(){
    T=read();
    while(T--){
        n=read();
        for(int i=1,l,r,c;i<=n;i++){
            l=read(),r=read(),c=read();
            p[i]=node(l,r,c);
            v[++tot]=l,v[++tot]=r;
            _max(m,c+1);
        }
        sort(v+1,v+tot+1);
        for(int i=1;i<=tot;i++)if(v[i]!=v[i-1])mp[v[i]]=++num;
        for(int l=0;l<=num+1;l++){
            a[l]=0;
            for(int r=0;r<=num+1;r++)s[l][r]=0;
        }
        for(int i=1;i<=n;i++){
            p[i].l=mp[p[i].l],p[i].r=mp[p[i].r];
            for(int j=p[i].l;j<=p[i].r;j++)add(a[j],p[i].c);
        }
        for(int l=1;l<=num;l++){
            for(int r=l;r<=num;r++)s[l][r]=s[l][r-1],add(s[l][r],a[r]);
        }
        for(int i=0;i<=num;i++)for(int j=0;j<=m;j++)f[i][j]=0;
        for(int l=1;l<=num;l++){
            for(int r=l;r<=num;r++){
                int x=0,L=l;
                for(int k=1;k<=n;k++){
                    if(p[k].l<l&&p[k].r>=l&&!p[k].c)_min(L,p[k].l);
                    if(l<=p[k].l&&r>=p[k].r)++x;
                }
                for(int c=1;c<=m;c++){
                    _max(f[r][c],f[l-1][c]);
                    if(!(s[l][r]==c||s[l][r]==0))continue;
                    _max(f[r][c],max(f[l-1][c],g[L-1])+x);
                }
            }
            g[l]=0;
            for(int c=1;c<=m;c++)_max(g[l],f[l][c]);
        }
        for(int i=1;i<=m;i++)_max(ans,f[num][i]);
        _wri(ans);
        tot=num=ans=m=0;
        mp.clear();
    }
    return 0;
}

