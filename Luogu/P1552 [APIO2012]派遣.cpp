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
#define tl tree[l]
#define tr tree[r]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,INF=1e9+7;
struct node{int l,r,v,dist;
node(int l=0,int r=0,int v=0,int dist=0):l(l),r(r),v(v),dist(dist){}}tree[N];
int n,master,fa[N],Rt[N];
int to[N],nxt[N],hd[N],ec;
ll m,ld[N],c[N],tot[N],sum[N],ans;

void add(int u,int v){
	to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;
	return;
}
 
int merge(int l,int r){
	if(!l||!r)return l^r;
	if(tl.v<tr.v)swap(l,r);
	tl.r=merge(tl.r,r);
	if(tree[tl.l].dist<tree[tl.r].dist)swap(tl.l,tl.r);
	tl.dist=tree[tl.r].dist+1;
	return l;
}

void dfs(int u){
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		dfs(v),Rt[u]=merge(Rt[u],Rt[v]);
		sum[u]+=sum[v],tot[u]+=tot[v];
	}
	while(sum[u]>m)sum[u]-=tree[Rt[u]].v,Rt[u]=merge(tree[Rt[u]].l,tree[Rt[u]].r),--tot[u];
	ans=max(ans,ld[u]*tot[u]);
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		fa[i]=read(),sum[i]=c[i]=read(),ld[i]=read(),tot[i]=1;
		if(fa[i]==0)master=i;
		else add(fa[i],i);
		Rt[i]=i,tree[i]=node(0,0,c[i],1);
	}
	dfs(master);
	printf("%lld\n",ans);
	return 0;
}
