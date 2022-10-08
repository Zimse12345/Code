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

const int Mod=998244353;//1000000007;
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
inline int _abs(int x){return x<0?-x:x;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}

const int N=2e6+7;
const int INF=1000114514;

int n,m,q,rt,hd[N],nxt[N],to[N],ec=1;
int Hd[N],Nxt[N],To[N],Ec=1;
int dfn[N],Time,low[N],stk[N],top,col[N],Col[N],cnt,Cnt;
int fa[N],dep[N],sz[N],son[N],Dfn[N],Top[N];
int vis[N],p[N],pcnt,qu[N],_v;
vector<int> g[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return y<_.y;}
}a[N];

inline void add_edge(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

inline void Add_edge(int u,int v){
	Nxt[++Ec]=Hd[u],Hd[u]=Ec,To[Ec]=v;
	return;
}

void tarjan(int u,int from){
    dfn[u]=low[u]=++Time,stk[++top]=u;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(!dfn[v]){
            tarjan(v,i);
            if(dfn[u]<low[v]){
                ++cnt;
                while(stk[top+1]^v)col[stk[top--]]=cnt;
            }
        }
        if(i^from^1)low[u]=min(low[u],low[v]);
    }
    if(!from){
    	++cnt;
    	while(top)col[stk[top--]]=cnt;
	}
    return;
}

void Tarjan(int u,int from){
	dfn[u]=low[u]=++Time,stk[++top]=u;
	for(int i=Hd[u],v;i;i=Nxt[i]){
		v=To[i];
		if(!dfn[v]){
			Tarjan(v,i);
			if(dfn[u]<low[v]){
				++Cnt,stk[top+1]=0;
				while(stk[top+1]^v)Col[stk[top--]]=Cnt;
			}
		}
		if(i^from^1)low[u]=min(low[u],low[v]);
	}
	if(!from){
		++Cnt;
		while(top)Col[stk[top--]]=Cnt;
	}
	return;
}

void dfs0(int u,int from){
    fa[u]=from,sz[u]=1,dep[u]=dep[from]+1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        dfs0(v,u),sz[u]+=sz[v];
        if(sz[son[u]]<sz[v])son[u]=v;
    }
    return;
}

void dfs1(int u,int t){
    Dfn[u]=++Time,Top[u]=t;
    if(son[u])dfs1(son[u],t);
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa[u]||v==son[u])continue;
        dfs1(v,v);
    }
    return;
}

inline int getlca(int x,int y){
    while(Top[x]^Top[y]){
        if(dep[Top[x]]<dep[Top[y]])swap(x,y);
        x=fa[Top[x]];
    }
    return dep[x]<dep[y]?x:y;
}

inline void link(int u,int v){
	if(u==rt||v==rt||u==v)return;
	if(!vis[u])vis[u]=1,p[++pcnt]=u;
	if(!vis[v])vis[v]=1,p[++pcnt]=v;
    Add_edge(u,v),Add_edge(v,u);
    return;
}

signed main(){
	n=read(),m=read(),q=read();
    for(int i=1,u,v;i<=m;i++){
    	u=read(),v=read(),add_edge(u,v),add_edge(v,u);
	}
	rt=n+1;
    for(int i=1;i<=n;i++)if(!dfn[i]){
    	tarjan(i,0);
    	g[rt].push_back(cnt); 
    	g[cnt].push_back(rt); 
	}
	Time=0;
    for(int u=1;u<=n;u++){
    	dfn[u]=0;
    	for(int i=hd[u],v;i;i=nxt[i]){
    		v=to[i];
    		if(col[u]!=col[v])g[col[u]].push_back(col[v]);
		}
	}
    dfs0(rt,0);
    dfs1(rt,rt);
    for(int I=1;I<=q;I++){
        int V=read(),E=read(),_V=V;
        for(int i=1,x;i<=V;i++){
        	x=(read()+_v)%n;
        	if(!x)x=n;
        	x=col[x],a[i]=node(x,Dfn[x]),qu[i]=x;
		}
        while(E--){
        	int u=(read()+_v)%n,v=(read()+_v)%n;
        	if(!u)u=n;
        	if(!v)v=n;
        	u=col[u],v=col[v];
        	link(u,v),a[++V]=node(u,Dfn[u]),a[++V]=node(v,Dfn[v]);
		}
        sort(a+1,a+V+1);
		top=0;
        stk[++top]=a[1].x;
        for(int i=2,x,lca;i<=V;i++){
        	if(a[i].x==a[i-1].x)continue;
            x=a[i].x,lca=getlca(x,a[i-1].x);
            while(top>1&&dep[stk[top-1]]>=dep[lca])link(stk[top],stk[top-1]),--top;
            link(lca,stk[top]),stk[top]=lca,stk[++top]=x;
        }
        for(int i=1;i<top;i++)link(stk[i],stk[i+1]);
		
		top=0,Tarjan(qu[1],0);
		int tag=1;
		for(int i=2;i<=_V;i++)if(Col[qu[i]]!=Col[qu[1]]){
			tag=0;
			break;
		}
		if(tag)printf("YES\n"),_v=(_v+I)%n;
		else printf("NO\n");
		
		p[0]=qu[1];
		for(int i=0;i<=pcnt;i++){
			Col[p[i]]=dfn[p[i]]=vis[p[i]]=Hd[p[i]]=0;
		}
		pcnt=0;
		for(int i=1;i<=Ec;i++)Nxt[i]=To[i]=0;
		Ec=1;
    }
	return 0;
}

