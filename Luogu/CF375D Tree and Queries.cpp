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

#define ll long long
#define ull unsigned long long
	
using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,val[N],cnt[N],son[N],ct,ans[N];
int hd[N],nxt[N],to[N],ec,tot[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
struct query{int k,id;query(int k=0,int id=0):k(k),id(id){}};
vector<query> q[N];

int tr[N];
inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void update(int x,int t){for(;x<=n;ub(x))tr[x]+=t;return;}
inline int qu(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}

void dfs1(int u,int from){
	cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs1(v,u),cnt[u]+=cnt[v];
		if(cnt[son[u]]<cnt[v])son[u]=v;
	}
	return;
}

void dfs3(int u,int from,int t){
	if(tot[val[u]])update(tot[val[u]],-1);
	tot[val[u]]+=t;
	if(tot[val[u]])update(tot[val[u]],1);
	for(int i=hd[u];i;i=nxt[i])if(to[i]^from)dfs3(to[i],u,t);
	return;
}

void dfs2(int u,int from,int tag){
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,0);
	}
	if(son[u])dfs2(son[u],u,1);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs3(v,u,1);
	}
	if(tot[val[u]])update(tot[val[u]],-1);
	tot[val[u]]+=1;
	if(tot[val[u]])update(tot[val[u]],1);
	for(unsigned i=0;i<q[u].size();i++){
		if(q[u][i].k<=n)ans[q[u][i].id]=qu(n)-qu(q[u][i].k-1);
	}
	if(tag==0)dfs3(u,from,-1);
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	for(int i=1,u,k;i<=m;i++)u=read(),k=read(),q[u].push_back(query(k,i));
	dfs1(1,0);
	dfs2(1,0,1);
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}

