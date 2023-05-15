// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
namespace Zimse{const int INF=1.01e9,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int &x,int y){if(x<y)x=y;}
inline void _min(int &x,int y){if(y<x)x=y;}
inline void addmod(int &x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=64,M=1.01e6;
int n,a[N][N],c[N],_c[N],ans,mx=-INF;
unordered_map<int,int> f,g;

int encode(){int x=0;for(int i=n-1;i>=0;i--)x=x*10+c[i];return x;}
void decode(int x){for(int i=0;i<n;i++)c[i]=x%10,x/=10;return;}

int recalc(){
    for(int i=0;i<n;i++)_c[i]=c[i];
    for(int i=0;i<n;i++)if(c[i]&&!c[c[i]-1]){
        for(int j=i+1;j<n;j++)if(c[j]==c[i])c[j]=i+1;
        c[i]=i+1;
    }
    int res=encode();
    for(int i=0;i<n;i++)c[i]=_c[i];
    return res;
}

signed main(){
    n=read();
    f[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=read(),_max(mx,a[i][j]);
            for(auto it=f.begin();it!=f.end();it++){
                int x=it->first,v=it->second;
                decode(x);
                int sz=0,s=c[j];
                for(int t=0;t<n;t++)if(c[t]==s)++sz;
                if((!s||sz>1)){
                    c[j]=0;
                    int y=recalc();
                    if(!g.count(y))g[y]=v;
                    else _max(g[y],v);
                    c[j]=s;
                }
                if(!s&&j)c[j]=c[j-1];
                if(!c[j])c[j]=j+1;
                if(j&&c[j-1]&&c[j-1]!=c[j]){
                    int l=c[j-1],r=c[j];
                    for(int t=0;t<n;t++)if(c[t]==l||c[t]==r)c[t]=min(l,r);
                }
                int y=encode();
                if(!g.count(y))g[y]=v+a[i][j];
                else _max(g[y],v+a[i][j]);
                int tag=1;
                for(int t=0;t<n;t++)if(c[t]&&c[t]!=c[j])tag=0;
                if(tag)_max(ans,v+a[i][j]);
            }
            swap(f,g),g.clear();
        }
    }
    if(mx<0)ans=mx;
    _write(ans);
    return 0;
}

