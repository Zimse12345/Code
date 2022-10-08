/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-21
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
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

const int MB=1<<20;
struct FastIO{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	char read_char(){
		if(p==q){
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename T>
	void read_int(T& x){
		char c=read_char(),l=0;
		for(x=0;!isdigit(c);c=read_char())l=c;
		for(;isdigit(c);c=read_char())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void write_char(char c){
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename T>
	void write_int(T x){
		if(x<0)write_char('-'),x=-x;
		do stk[++tp]=x%10+'0';
		while(x/=10);
		while(tp)write_char(stk[tp--]);
	}
}IO;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
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

inline int read(){
	int x;
	IO.read_int(x);
	return x;
}

const int N=6e5+7;

int n,hd[N],nxt[N*2],to[N*2],ec,p[N];
ll ans;
int fa[N],cnt[N],dep[N],son[N],top[N],dfn[N],Time;

struct node{
    int sum;ll sumdep;
}tr[N*8];
int tag[N*8];

node qsum(int id,int L,int R,const int& l,const int& r){
    if(tag[id]){
        tr[id].sum=0,tr[id].sumdep=0;
        tag[Lid]=tag[Rid]=1,tag[id]=0;
    }
    if(r<L||R<l)return tr[0];
    if(l<=L&&r>=R){
    	node res=tr[id];
    	tr[id].sum=0,tr[id].sumdep=0;
    	tag[Lid]=tag[Rid]=1;
    	return res;
	}
    node ls=qsum(Lid,L,M,l,r);
	node rs=qsum(Rid,M+1,R,l,r);
	tr[id].sum=tr[Lid].sum+tr[Rid].sum,tr[id].sumdep=tr[Lid].sumdep+tr[Rid].sumdep;
    ls.sum+=rs.sum,ls.sumdep+=rs.sumdep;
    return ls;
}

void insert(int id,int L,int R,const int& x,const int& sum,const ll& sumdep){
    if(tag[id]){
        tr[id].sum=0,tr[id].sumdep=0;
        tag[Lid]=tag[Rid]=1,tag[id]=0;
    }
    if(L==R)tr[id].sum+=sum,tr[id].sumdep+=sumdep;
    else{
        if(x<=M)insert(Lid,L,M,x,sum,sumdep);
        else insert(Rid,M+1,R,x,sum,sumdep);
        if(!tag[Lid]&&!tag[Rid])tr[id].sum=tr[Lid].sum+tr[Rid].sum,tr[id].sumdep=tr[Lid].sumdep+tr[Rid].sumdep;
        else if(!tag[Lid])tr[id].sum=tr[Lid].sum,tr[id].sumdep=tr[Lid].sumdep;
        else if(!tag[Rid])tr[id].sum=tr[Rid].sum,tr[id].sumdep=tr[Rid].sumdep;
        else tr[id].sum=tr[id].sumdep=0;
    }
    return;
}

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs(int u,int from){
    fa[u]=from,cnt[u]=1,dep[u]=dep[from]+1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs(v,u);
        cnt[u]+=cnt[v];
        if(cnt[son[u]]<cnt[v])son[u]=v;
    }
    return;
}

void dfs2(int u,int t){
    top[u]=t,dfn[u]=++Time;
    if(son[u])dfs2(son[u],t);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
    return;
}

inline int LCA(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}

signed main(){
    ifile("easy.in"),ofile("easy.out");
    n=read();
    for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
    dfs(1,0);
    dfs2(1,1);
    p[0]=1;
    ll res=0;
    for(int i=1,lca,L,R;i<=n;i++){
        p[i]=read();
        lca=LCA(p[i-1],p[i]);
        L=dfn[lca],R=dfn[lca]+cnt[lca]-1;
        node a=qsum(1,1,n,L,R);
        res-=a.sumdep;
        a.sumdep=1ll*a.sum*dep[lca];
        res+=a.sumdep;
        insert(1,1,n,dfn[lca],a.sum,a.sumdep);
        res+=dep[p[i]];
        a.sum=1,a.sumdep=dep[p[i]];
        insert(1,1,n,dfn[p[i]],a.sum,a.sumdep);
        ans+=res;
    }
    printf("%lld\n",ans);
	return 0;
}

