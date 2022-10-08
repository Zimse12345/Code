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
#define M ((L+R)/2)
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,q,hd[N],nxt[N],to[N],len[N],ec;
int fa[N],cnt[N],dep[N],Dep[N],son[N],dfn[N],_dfn[N],top[N],Time;
int rt[N],ch[N*8][2],sum[N*8],tot;

inline void add(int u,int v,int w){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
	return;
}

void dfs0(int u,int from,int d){
	fa[u]=from,cnt[u]=1,dep[u]=d,Dep[u]=Dep[fa[u]]+1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs0(v,u,d+len[i]),cnt[u]+=cnt[v];
		if(cnt[son[u]]<cnt[v])son[u]=v;
	}
	return;
}

void dfs1(int u,int t){
	dfn[u]=++Time,_dfn[Time]=u,top[u]=t;
	if(son[u])dfs1(son[u],t);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==fa[u]||v==son[u])continue;
		dfs1(v,v);
	}
	return;
}

void update(int& id,int _id,int L,int R,int p){
	id=++tot,sum[id]=sum[_id]+1;
	if(L^R){
		if(p<=M)update(Lid,ch[_id][0],L,M,p),Rid=ch[_id][1];
		else update(Rid,ch[_id][1],M+1,R,p),Lid=ch[_id][0];
	}
	return;
}

int findL(int id1,int id2,int L,int R){
	if(L==R)return L;
	if(sum[ch[id2][0]]-sum[ch[id1][0]]>0)return findL(ch[id1][0],ch[id2][0],L,M);
	return findL(ch[id1][1],ch[id2][1],M+1,R);
}

int findR(int id1,int id2,int L,int R){
	if(L==R)return R;
	if(sum[ch[id2][1]]-sum[ch[id1][1]]>0)return findR(ch[id1][1],ch[id2][1],M+1,R);
	return findR(ch[id1][0],ch[id2][0],L,M);
}

int query(int id1,int id2,int L,int R,int l,int r){
	if(r<L||R<l)return 0;
	if(l<=L&&r>=R){
		return sum[id2]-sum[id1];
	}
	return query(ch[id1][0],ch[id2][0],L,M,l,r)+query(ch[id1][1],ch[id2][1],M+1,R,l,r);
}

int Find(int x,int d){
	while(Dep[fa[top[x]]]>=d)x=fa[top[x]];
	return _dfn[dfn[x]-(Dep[x]-d)];
}

int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

signed main(){
	n=read(),q=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
	}
	dfs0(1,0,0);
	dfs1(1,1);
	for(int i=1;i<=n;i++){
		update(rt[i],rt[i-1],1,n,dfn[i]);
	}
	for(int I=1,ans=0,p,l,r;I<=q;I++){
		p=read()^ans,l=read()^ans,r=read()^ans,ans=0;
		int lp=_dfn[findL(rt[l-1],rt[r],1,n)],rp=_dfn[findR(rt[l-1],rt[r],1,n)];
		int lca=LCA(lp,rp);
		int s=query(rt[l-1],rt[r],1,n,dfn[p],dfn[p]+cnt[p]-1);
		if(s==r-l+1)ans=dep[lca]-dep[p];
		else if(s==0){
			int L=1,R=Dep[p],t=0;
			while(L<=R){
				int k=Find(p,M);
				if(query(rt[l-1],rt[r],1,n,dfn[k],dfn[k]+cnt[k]-1)>0)t=k,L=M+1;
				else R=M-1;
			}
			if(dep[t]<dep[lca])ans=dep[lca]-dep[t]+dep[p]-dep[t];
			else ans=dep[p]-dep[t];
		}
		else ans=0;
		printf("%d\n",ans);
	}
	return 0;
}

