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
#define	M ((L+R)>>1)
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,q,val[N],_p[N];
int hd[N],nxt[N],to[N],ec;
int rt[N],fa[21][N],sz[N],dep[N];
int ch[N*96][2],sum[N*96],Rt[N],tot;
set<int> v;
map<int,int> p;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

int update(int L,int R,int id,int x){
	int _id=++tot;
	if(L==R)sum[_id]=sum[id]+1;
	else{
		if(x<=M)ch[_id][0]=update(L,M,Lid,x),ch[_id][1]=Rid;
		else ch[_id][1]=update(M+1,R,Rid,x),ch[_id][0]=Lid;
		sum[_id]=sum[ch[_id][0]]+sum[ch[_id][1]];
	}
	return _id;
}

void dfs(int u,int t){
	rt[u]=t,++sz[t],dep[u]=dep[fa[0][u]]+1;
	Rt[u]=update(1,n,Rt[fa[0][u]],val[u]);
	for(int i=hd[u];i;i=nxt[i])if(rt[to[i]]^rt[u]){
		fa[0][to[i]]=u;
		for(int j=1;j<=20;j++)fa[j][to[i]]=fa[j-1][fa[j-1][to[i]]];
		dfs(to[i],t);
	}
	return;
}

int query(int L,int R,int id1,int id2,int id3,int id4,int k){
	if(L==R)return L;
	int lsum=sum[ch[id1][0]]+sum[ch[id2][0]]-sum[ch[id3][0]]-sum[ch[id4][0]];
	if(k<=lsum)return query(L,M,ch[id1][0],ch[id2][0],ch[id3][0],ch[id4][0],k);
	return query(M+1,R,ch[id1][1],ch[id2][1],ch[id3][1],ch[id4][1],k-lsum);
}

signed main(){
	T=read();
	T=1;
	while(T--){
		n=read(),m=read(),q=read();
		for(int i=1;i<=n;i++)val[i]=read(),v.insert(val[i]);
		int id=0;
		for(set<int>::iterator it=v.begin();it!=v.end();it++)p[*it]=++id,_p[id]=*it;
		for(int i=1;i<=n;i++)val[i]=p[val[i]];
		
		for(int i=1,x,y;i<=m;i++)x=read(),y=read(),add(x,y),add(y,x);
		for(int i=1;i<=n;i++)if(!rt[i])dfs(i,i);
		for(int i=1,op,x,y,k,ans=0;i<=q;i++){
			do{op=getchar();}while(op!='Q'&&op!='L');
			x=read()^ans,y=read()^ans;
			if(op=='Q'){
				k=read()^ans;
				int u=x,v=y,lca;
				if(dep[u]<dep[v])swap(u,v);
				for(int j=20;j>=0;j--)if(dep[fa[j][u]]>=dep[v])u=fa[j][u];
				for(int j=20;j>=0;j--)if(fa[j][u]!=fa[j][v])u=fa[j][u],v=fa[j][v];
				if(u==v)lca=u;
				else lca=fa[0][u];
				ans=query(1,n,Rt[x],Rt[y],Rt[lca],Rt[fa[0][lca]],k);
				ans=_p[ans];
				printf("%d\n",ans);
			}
			else{
				if(sz[rt[x]]<sz[rt[y]])swap(x,y);
				add(x,y),add(y,x);
				fa[0][y]=x;
				for(int j=1;j<=20;j++)fa[j][y]=fa[j-1][fa[j-1][y]];
				dfs(y,rt[x]);
			}
		}
	}
	return 0;
}

