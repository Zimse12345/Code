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

#define int long long
#define Lid ch[id][0]
#define Rid ch[id][1]
#define M ((L+R)>>1ll)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e5+7,Mod=1e9+7,INF=1e12+7;
int n,pos[N],rg[N],Lrg[N*4],Rrg[N*4],ans;
int tot=1,ch[N*4][2],p[N];
int hd[N*4],ec;
signed nxt[N*20],to[N*20];
int dfn[N*4],low[N*4],ct,st[N*4],tp,vis[N*4];
int scc,cl[N*4],Lto[N*4],Rto[N*4];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
vector<int> g[N*4];
 
void build(int L,int R,int id){
	if(L==R)p[L]=id;
	else{
		Lrg[id]=L,Rrg[id]=R;
		Lid=++tot,Rid=++tot,add(id,Lid),add(id,Rid);
		build(L,M,Lid),build(M+1,R,Rid);
	}
	return;
}

void update(int L,int R,int id,int l,int r,int _id){
	if(r<L||R<l)return;
	if(l<=L&&r>=R)add(_id,id);
	else update(L,M,Lid,l,r,_id),update(M+1,R,Rid,l,r,_id);
	return;
}

void tarjan(int u){
	dfn[u]=low[u]=++ct,st[++tp]=u,vis[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(vis[v])low[u]=min(low[u],dfn[v]); 
	}
	if(dfn[u]^low[u])return;
	++scc,Lto[scc]=INF;
	do{
		int v=st[tp];
		cl[v]=scc,vis[v]=0;
		Lto[scc]=min(Lto[scc],Lrg[v]);
		Rto[scc]=max(Rto[scc],Rrg[v]);
	}while(st[tp--]!=u);
	return;
}

void dfs(int u){
	if(vis[u]++)return;
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i],dfs(v);
		Lto[u]=min(Lto[u],Lto[v]),Rto[u]=max(Rto[u],Rto[v]);
	}
	return;
}

signed main(){
	n=read();
	build(1,n,1);
	for(int i=1;i<=n;i++)pos[i]=read(),rg[i]=read();
	for(int i=1,L,R;i<=n;i++){
		L=1,R=i;
		while(L<=R){
			if(pos[i]-pos[M]<=rg[i])Lrg[p[i]]=M,R=M-1;
			else L=M+1;
		}
		L=i,R=n;
		while(L<=R){
			if(pos[M]-pos[i]<=rg[i])Rrg[p[i]]=M,L=M+1;
			else R=M-1;
		}
		update(1,n,1,Lrg[p[i]],Rrg[p[i]],p[i]);
	}
	tarjan(1);
	for(int u=1;u<=tot;u++){
		for(int j=hd[u],v;j;j=nxt[j]){
			v=to[j];
			if(cl[u]^cl[v])g[cl[u]].push_back(cl[v]);
		}
	}
	for(int i=1;i<=scc;i++){
		sort(g[i].begin(),g[i].end());
		unique(g[i].begin(),g[i].end());
		vis[i]=0;
	}
	for(int i=1;i<=scc;i++)dfs(i);
	for(int i=1;i<=n;i++)ans=(ans+i*(Rto[cl[p[i]]]-Lto[cl[p[i]]]+1))%Mod;
	printf("%lld\n",ans);
	return 0;
}

