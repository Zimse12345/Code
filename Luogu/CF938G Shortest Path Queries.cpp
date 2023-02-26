/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

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
#define pb push_back
#define ll long long
// #define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
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

const int N=1000007;

int n,m,q,qu[N],qv[N],fa[N],cnt[N],fw[N],f[N];
int *ptr[N],val[N],tot;

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{
        if(x==_.x)return y<_.y;
        return x<_.x;
    }
};
map<node,node> mp;

struct edge{
    int u,v,w;
    edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
};
vector<edge> t[N];

void update(int id,int L,int R,int l,int r,edge e){
    // printf("(%d %d) (%d %d %d)\n",l,r,e.u,e.v,e.w);
    // return;
    if(l<=L&&r>=R)t[id].pb(e);
    else if(r<L||R<l)return;
    else update(Lid,L,M,l,r,e),update(Rid,M+1,R,l,r,e);
    return;
}

void ins(int x){
    // printf("ins %d\n",x);
    for(int i=30;i>=0;i--)if(x&(1<<i)){
        if(f[i])x^=f[i];
        else{
            ptr[++tot]=&f[i],val[tot]=f[i];
            f[i]=x;
            break;
        }
    }
    return;
}

void link(edge e){
    // printf("add(%d %d %d)\n",e.u,e.v,e.w);
    int u=e.u,v=e.v,px=0;
    while(fa[u]!=u)px^=fw[u],u=fa[u];
    while(fa[v]!=v)px^=fw[v],v=fa[v];
    if(u==v)ins(px^e.w);
    else{
        if(cnt[u]<cnt[v])swap(u,v);
        ptr[++tot]=&fa[v],val[tot]=fa[v];
        ptr[++tot]=&cnt[u],val[tot]=cnt[u];
        fa[v]=u,cnt[u]+=cnt[v],fw[v]=(px^e.w);
    }
    return;
}

void solve(int id,int L,int R){
    // printf("[%d %d]\n",L,R);
    int _tot=tot;
    for(unsigned i=0;i<t[id].size();i++)link(t[id][i]);
    if(L==R){
        if(qu[L]){
            int u=qu[L],v=qv[L],px=0;
            while(fa[u]!=u)px^=fw[u],u=fa[u];
            while(fa[v]!=v)px^=fw[v],v=fa[v];
            // printf("px=%d\n",px);
            for(int i=30;i>=0;i--)if((px^f[i])<px)px^=f[i];
            _write(px);
        }
    }
    else solve(Lid,L,M),solve(Rid,M+1,R);
    while(tot>_tot)*ptr[tot]=val[tot],--tot;
    return;
}

signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++)fa[i]=i,cnt[i]=1;
    for(int i=1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        mp[node(min(u,v),max(u,v))]=node(1,w);
    }
    q=read();
    for(int i=1;i<=q;i++){
        int ty=read(),x=read(),y=read();
        if(ty==1)mp[node(min(x,y),max(x,y))]=node(i,read());
        else if(ty==2){
            update(1,1,q,mp[node(x,y)].x,i-1,edge(x,y,mp[node(x,y)].y));
            mp[node(min(x,y),max(x,y))].x=0;
        }
        else qu[i]=x,qv[i]=y;
    }
    for(map<node,node>::iterator it=mp.begin();it!=mp.end();it++){
        // printf("[%d %d] --> e(%d %d)\n",it->second.x,it->second.y,it->first.x,it->first.y);
        if(it->second.x)update(1,1,q,it->second.x,q,edge(it->first.x,it->first.y,it->second.y));
    }
    solve(1,1,q);
    return 0;
}
