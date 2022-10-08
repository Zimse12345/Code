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
int n,m,vis[N],ans;
int fa[N],cnt[N],dep[N],hv[N],dfn[N],top[N],a[N],val[N],tot;
int ff[N],ccnt[N],mx[N<<2];
struct edge{
	int u,v,w;edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
	bool operator <(const edge& A)const{return w<A.w;}
}e[N];
struct eg{int to,w;eg(int to=0,int w=0):to(to),w(w){}};
vector<eg> G[N];
vector<int> ch[N];
int F(int x){if(ff[x]!=x)ff[x]=F(ff[x]);return ff[x];}

void dfs1(int u,int pr,int dp){
	dep[u]=dp,cnt[u]=1;
	for(int i=0;i<int(G[u].size());i++){
		int v=G[u][i].to;
		if(v==pr)continue;
		dfs1(v,u,dp+1),ch[u].push_back(v);
		cnt[u]+=cnt[v],fa[v]=u,a[v]=G[u][i].w;
	}
	return;
}

void dfs2(int u,int pr){
	top[u]=pr,dfn[u]=++tot;
	for(int i=0;i<int(ch[u].size());i++)if(cnt[hv[u]]<cnt[ch[u][i]])hv[u]=ch[u][i];
	if(hv[u])dfs2(hv[u],pr);
	for(int i=0;i<int(ch[u].size());i++)if(hv[u]!=ch[u][i])dfs2(ch[u][i],ch[u][i]);
	return;
}

void build(int L,int R,int id){
	if(L==R)mx[id]=val[L];
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
		mx[id]=max(mx[id<<1],mx[(id<<1)|1]);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	if(l<=L&&r>=R)return mx[id];
	int M=(L+R)>>1,res=0;
	if(l<=M)res=max(res,query(L,M,id<<1,l,r));
	if(r>M)res=max(res,query(M+1,R,(id<<1)|1,l,r));
	return res;
}

int main(){
	n=read(),m=read();
	for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),e[i]=edge(u,v,w);
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)ff[i]=i,ccnt[i]=1;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int A=F(u),B=F(v);
		if(A!=B){
			if(ccnt[A]<ccnt[B])ff[A]=B,ccnt[B]+=ccnt[A];
			else ff[B]=A,ccnt[A]+=ccnt[B];
			vis[i]=1,G[u].push_back(eg(v,w)),G[v].push_back(eg(u,w));
		}
	}
	dfs1(1,0,0),dfs2(1,1);
	for(int i=1;i<=n;i++)val[dfn[i]]=a[i];
	build(1,n,1);
	for(int i=1;i<=m;i++)if(!vis[i]){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int M=0;
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]]){int T=u;u=v,v=T;}
			int A=top[u];
			M=max(M,query(1,n,1,dfn[A],dfn[u]));
			u=fa[A];
		}
		if(dep[u]>dep[v]){int T=u;u=v,v=T;}
		if(u!=v)M=max(M,query(1,n,1,dfn[u]+1,dfn[v]));
		if(M>=w)++ans;
	}
	printf("%d\n",ans);
	return 0;
}
