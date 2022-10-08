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
#define Lid ch[id][0]
#define Rid ch[id][1]
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,_n,q,h[N],b[N],fa[N],cnt[N],p[N],ct,fr[N][20],val[N];
int hd[N],nxt[N*2],to[N*2],ec,vis[N];
int dfn[N],_dfn[N],sc[N],tot,rt[N];
int sum[N*32],nc,ch[N*32][2];
map<int,int> mp;
struct edge{
	int u,v,w;
	edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
	bool operator < (const edge& A)const{return w<A.w;}
}e[N*5];
inline int F(int x){if(x^fa[x])fa[x]=F(fa[x]);return fa[x];}
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs(int u){
	dfn[u]=++tot,_dfn[tot]=u,sc[u]=1;
	for(int i=hd[u];i;i=nxt[i])dfs(to[i]),sc[u]+=sc[to[i]];
	return;
}

void update(int L,int R,int& id,int _id,int x){
	id=++nc,sum[id]=sum[_id]+1;
	if(L^R){
		if(x<=M)update(L,M,Lid,ch[_id][0],x),Rid=ch[_id][1];
		else update(M+1,R,Rid,ch[_id][1],x),Lid=ch[_id][0];
	}
	return;
}

int query(int L,int R,int id,int _id,int x){
	if(sum[id]-sum[_id]<x)return -1;
	if(L==R)return b[L];
	if(sum[Rid]-sum[ch[_id][1]]>=x)return query(M+1,R,Rid,ch[_id][1],x);
	return query(L,M,Lid,ch[_id][0],x-(sum[Rid]-sum[ch[_id][1]]));
}

signed main(){
	n=ct=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)h[i]=b[i]=read(),fa[i]=p[i]=i,cnt[i]=1;
	sort(b+1,b+n+1),b[0]=-1;
	for(int i=1;i<=n;i++)if(b[i]^b[i-1])b[++_n]=b[i],mp[b[i]]=_n;
	
	for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),e[i]=edge(u,v,w);
	sort(e+1,e+m+1);
	for(int i=1,u,v;i<=m;i++){
		u=e[i].u,v=e[i].v;
		int A=F(u),B=F(v);
		if(A^B){
			if(cnt[A]<cnt[B])swap(A,B);
			fr[p[A]][0]=fr[p[B]][0]=++ct,val[ct]=e[i].w;
			add(ct,p[A]),add(ct,p[B]);
			fa[B]=A,cnt[A]+=cnt[B],p[A]=ct;
		}
	}
	val[0]=INF;
	for(int i=1;i<=18;i++)for(int j=1;j<=ct;j++)fr[j][i]=fr[fr[j][i-1]][i-1];
	for(int i=1,x;i<=n;i++){
		x=p[F(i)];
		if(!vis[x])vis[x]=1,dfs(x);
	}
	for(int i=1;i<=tot;i++){
		if(_dfn[i]<=n)update(1,_n,rt[i],rt[i-1],mp[h[_dfn[i]]]);
		else rt[i]=rt[i-1];
	}
	
	for(int i=1,u,x,k;i<=q;i++){
		u=read(),x=read(),k=read();
		for(int j=18;j>=0;j--)if(val[fr[u][j]]<=x)u=fr[u][j];
		printf("%d\n",query(1,_n,rt[dfn[u]+sc[u]-1],rt[dfn[u]],k));
	}
	return 0;
}

