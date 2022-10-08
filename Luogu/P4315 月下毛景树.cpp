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
int T,n,a[N],val[N],br[N],Id[N];
int fa[N],cnt[N],top[N],dfn[N],hv[N],dep[N],tot;
int mx[N<<2],len[N<<2],tag1[N<<2],tag2[N<<2];
struct edge{
	int to,w,id;
	edge(int to=0,int w=0,int id=0):to(to),w(w),id(id){};
};
vector<edge> g[N];
vector<int> ch[N];
char op[N];

void dfs1(int u,int pr,int dp){
	dep[u]=dp,fa[u]=pr,cnt[u]=1;
	for(int i=0;i<int(g[u].size());i++){
		int v=g[u][i].to,w=g[u][i].w;
		if(v==pr)continue;
		dfs1(v,u,dp+1),cnt[u]+=cnt[v],a[v]=w;
		ch[u].push_back(v),br[v]=g[u][i].id;
		if(cnt[v]>cnt[hv[u]])hv[u]=v;
	}
	return;
}

void dfs2(int u,int pr){
	dfn[u]=++tot,val[dfn[u]]=a[u],top[u]=pr,Id[br[u]]=tot;
	if(hv[u])dfs2(hv[u],pr);
	for(int i=0;i<int(ch[u].size());i++)if(ch[u][i]!=hv[u])dfs2(ch[u][i],ch[u][i]);
	return;
}

void build(int L,int R,int id){
	len[id]=R-L+1;
	if(L==R)mx[id]=val[L];
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
		mx[id]=max(mx[id<<1],mx[(id<<1)|1]);
	}
	return;
}

void pushdown(int id){
	if(tag1[id]){
		mx[id]=tag1[id];
		tag1[id<<1]=tag1[(id<<1)|1]=tag1[id];
		tag1[id]=tag2[id<<1]=tag2[(id<<1)|1]=0;
	}
	if(tag2[id]){
		mx[id]+=tag2[id];
		if(tag1[id<<1])tag1[id<<1]+=tag2[id];
		else tag2[id<<1]+=tag2[id];
		if(tag1[(id<<1)|1])tag1[(id<<1)|1]+=tag2[id];
		else tag2[(id<<1)|1]+=tag2[id];
		tag2[id]=0;
	}
	return;
}

void Set(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&r>=R)tag1[id]=x,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)Set(L,M,id<<1,l,r,x);
		if(r>M)Set(M+1,R,(id<<1)|1,l,r,x);
		pushdown(id<<1),pushdown((id<<1)|1);
		mx[id]=max(mx[id<<1],mx[(id<<1)|1]);
	}
	return;
}

void Add(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&r>=R)tag2[id]=x,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)Add(L,M,id<<1,l,r,x);
		if(r>M)Add(M+1,R,(id<<1)|1,l,r,x);
		pushdown(id<<1),pushdown((id<<1)|1);
		mx[id]=max(mx[id<<1],mx[(id<<1)|1]);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return mx[id];
	int res=0,M=(L+R)>>1;
	if(l<=M)res=max(res,query(L,M,id<<1,l,r));
	if(r>M)res=max(res,query(M+1,R,(id<<1)|1,l,r));
	return res;
}

int main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		g[u].push_back(edge(v,w,i)),g[v].push_back(edge(u,w,i));
	}
	dfs1(1,0,0),dfs2(1,1),build(1,n,1);
	while(1){
		scanf("%s",op+1);
		if(op[1]=='S')break;
		if(op[2]=='h'){
			int k=read(),w=read();
			Set(1,n,1,Id[k],Id[k],w);
			continue;
		}
		int ty=3,ans=0,u=read(),v=read(),w=0;
		if(op[1]=='C')ty=1,w=read();
		if(op[1]=='A')ty=2,w=read();
		
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]])T=u,u=v,v=T;
			if(ty==1)Set(1,n,1,dfn[top[u]],dfn[u],w);
			if(ty==2)Add(1,n,1,dfn[top[u]],dfn[u],w);
			if(ty==3)ans=max(ans,query(1,n,1,dfn[top[u]],dfn[u]));
			u=fa[top[u]];
		}
		if(u!=v){
			if(dep[u]>dep[v])T=u,u=v,v=T;
			if(ty==1)Set(1,n,1,dfn[u]+1,dfn[v],w);
			if(ty==2)Add(1,n,1,dfn[u]+1,dfn[v],w);
			if(ty==3)ans=max(ans,query(1,n,1,dfn[u]+1,dfn[v]));
		}
		if(ty==3)printf("%d\n",ans);
	}
	return 0;
}
