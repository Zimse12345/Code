/********************************
*FileName:
*Author: Zimse
*Data:
*Description:
*Other:
********************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define ll long long
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||c>57){if(c==45)y=-1;c=gc();}while(c>=48&&c<=57)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1e6+7;

int T,n,hd[N],nxt[N],to[N],ec,fa[N],cnt[N],sz[N];

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

int F(int x){
    if(fa[x]!=x)fa[x]=F(fa[x]);
    return fa[x];
}

inline void link(int x,int y){
    x=F(x),y=F(y);
    if(x==y)return;
    if(sz[x]<sz[y])swap(x,y);
    fa[y]=x,cnt[x]+=cnt[y],sz[x]+=sz[y];
    return;
}

signed main(){
    T=read();
    while(T--){
        int ans=0;
        n=read();
        for(int i=1,u,v;i<n;i++){
            u=read(),v=read();
            add(u,v),add(v,u);
        }
        for(int i=1;i<=n;i++)fa[i]=i,cnt[i]=1,sz[i]=1;
        for(int u=1;u<=n;u++){
            int tot=0;
            for(int i=hd[u],v;i;i=nxt[i]){
                v=to[i];
                if(v>u)continue;
                if(cnt[F(v)])++tot;
                link(u,v);
            }
            if(tot>1)cnt[F(u)]-=3,++ans;
        }
        _write(ans);
        for(int i=1;i<=ec;i++)nxt[i]=to[i]=0;
        for(int i=1;i<=n;i++)hd[i]=0;
        ec=0;
    }
    return 0;
}
