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

int n,m,q;

struct edge{
    int u,v;
    edge(int u=0,int v=0):u(u),v(v){}
}e[N];
vector<edge> t[N*2],T;
int hd[N],nxt[N],to[N],ec;

inline void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

int dfn[N],low[N],st[N],ins[N],top,cl[N],cc,Time,vis[256][256],nx[N];
void tarjan(int u){
    dfn[u]=low[u]=++Time,st[++top]=u,ins[u]=1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(!dfn[v])tarjan(v),_min(low[u],low[v]);
        else if(ins[v])_min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        ++cc;
        int x=u;
        while(st[top+1]!=u){
        	ins[st[top]]=0,cl[st[top]]=cc;
        	nx[st[top]]=x,x=st[top];
			st[top+1]=0,--top;
		}
        st[top+1]=0;
    }
    return;
}

bool ck(edge x){
    int u=cl[x.u],v=cl[x.v];
    if(u==v||vis[u][v])return false;
    vis[u][v]++;
    return true;
}

vector<edge> merge(const vector<edge>& x,const vector<edge>& y){
    for(unsigned i=0;i<x.size();i++)add(x[i].u,x[i].v);
    for(unsigned i=0;i<y.size();i++)add(y[i].u,y[i].v);
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    vector<edge> res;
    for(int i=1;i<=n;i++){
    	int p=i;
    	while(nx[p]>0&&nx[p]!=i){
    		res.pb(edge(p,nx[p]));
    		int pre=p;
    		p=nx[p];
    		nx[pre]=0;
		}
	}
    for(unsigned i=0;i<x.size();i++)if(ck(x[i]))res.pb(x[i]);
    for(unsigned i=0;i<y.size();i++)if(ck(y[i]))res.pb(y[i]);
    for(int i=1;i<=n;i++)dfn[i]=hd[i]=0;
    Time=cc=top=ec=0;
    for(unsigned i=0;i<res.size();i++)vis[cl[res[i].u]][cl[res[i].v]]=0;
    return res;
}

void build(int id,int L,int R){
    if(L==R)t[id].pb(e[L]);
    else build(Lid,L,M),build(Rid,M+1,R),t[id]=merge(t[Lid],t[Rid]);
    return;
}

vector<edge> query(int id,int L,int R,int l,int r){
    if(l<=L&&r>=R)return t[id];
    if(r<=M)return query(Lid,L,M,l,r);
    if(l>M)return query(Rid,M+1,R,l,r);
    return merge(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
	// ifile("t.in");
	// ofile("t.out");
    n=read(),m=read(),q=read();
    int tag=1;
    for(int i=1,u,v;i<=m;i++){
        u=read(),v=read(),e[i]=edge(u,v);
        if(i>1&&(e[i].u<e[i-1].u||e[i].v<e[i-1].v))tag=0;
    }
    if(tag){
        while(q--)_write(0);
        return 0;
    }
    build(1,1,m);
    while(q--){
        int l=read(),r=read(),ans=0;
        T=query(1,1,m,l,r);
        for(unsigned i=0;i<T.size();i++)add(T[i].u,T[i].v);
        for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
        for(int i=1;i<=n;i++){
    		int p=i,sz=1;
    		while(nx[p]>0&&nx[p]!=i){
    			int pre=p;
    			p=nx[p];
    			nx[pre]=0,++sz;
			}
			nx[p]=0;
			ans+=sz*(sz-1)/2;
		}
        for(int i=1;i<=n;i++)dfn[i]=hd[i]=0;
        Time=cc=top=ec=0;
        _write(ans);
    }
    return 0;
}
