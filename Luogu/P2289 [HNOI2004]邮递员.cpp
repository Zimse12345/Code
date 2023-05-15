// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int __int128
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
inline void addmod(int &x,int y){(x+=y);}
}using namespace Zimse;using namespace std;

const int N=64,M=1.1e6;
int n,m,f[M],g[M],a[M],b[M],cnt,_l[M],_r[M],stk[M],top;
char s[N][N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node &_)const{
        if(x==_.x)return y<_.y;
        return x<_.x;
    }
};
inline int calc(int x,int y){
    return (x<<(m+1))+y;
}
map<int,int> mp;

signed main(){
    n=read(),m=read();
    swap(n,m);
    if(n==1||m==1){
        _write(1);
        return 0;
    }
    for(int i=0;i<(1<<(m+1));i++){
        for(int j=i;;j=(j-1)&i){
            int s=0;
            for(int k=0;k<=m;k++)if(i&(1<<k)){
                if(j&(1<<k))++s;
                else --s;
                if(s<0)break;
            }
            if(s==0)mp[calc(i,j)]=++cnt,a[cnt]=i,b[cnt]=j;
            if(!j)break;
        }
    }
    f[1]=1;
    int rm=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)if(s[i][j]!='*')++rm;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]!='*')--rm;
            for(int u=1;u<=cnt;u++)if(f[u]){
                int l=(1<<j),r=(l<<1);
                if(s[i][j]=='*'){
                    if(a[u]&(l|r))continue;
                    addmod(g[u],f[u]);
                    continue;
                }
                if(a[u]&l){
                    if(a[u]&r){
                        if((b[u]&l)&&(!(b[u]&r))){
                            if(!rm){
                                if(a[u]!=(l^r))f[u]=0;
                                _write(f[u]*2);
                                return 0;
                            }
                        }
                        for(int k=0;k<=m;k++)_l[k]=_r[k]=-1;
                        for(int k=0;k<=m;k++)if(a[u]&(1<<k)){
                            if(b[u]&(1<<k))stk[++top]=k;
                            else _l[k]=stk[top],_r[stk[top]]=k,--top;
                        }
                        int _b=b[u];
                        int s=(_l[j]==-1)?_r[j]:_l[j],t=(_l[j+1]==-1)?_r[j+1]:_l[j+1];
                        if(_b&l)_b^=l;
                        if(_b&r)_b^=r;
                        _b|=(1<<min(s,t));
                        if(_b&(1<<max(s,t)))_b^=(1<<max(s,t));
                        addmod(g[mp[calc(a[u]^l^r,_b)]],f[u]);
                    }
                    else{
                        addmod(g[u],f[u]);
                        addmod(g[mp[calc(a[u]^l^r,(b[u]&l)?(b[u]^l^r):b[u])]],f[u]);
                    }
                }
                else{
                    if(a[u]&r){
                        addmod(g[u],f[u]);
                        addmod(g[mp[calc(a[u]^l^r,(b[u]&r)?(b[u]^l^r):b[u])]],f[u]);
                    }
                    else{
                        addmod(g[mp[calc(a[u]^l^r,b[u]^l)]],f[u]);
                    }
                }
            }
            for(int u=1;u<=cnt;u++)f[u]=g[u],g[u]=0;
        }
        for(int u=1;u<=cnt;u++)if(!(a[u]&(1<<m))){
            g[mp[calc(a[u]*2,b[u]*2)]]=f[u];
        }
        for(int u=1;u<=cnt;u++)f[u]=g[u],g[u]=0;
    }
    _write(0);
    return 0;
}

