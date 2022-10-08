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
#define M ((L+R)>>1)
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,q,U[N],V[N],fa[N],tp[N],vis[N];
int c1,val1[N],c2,val2[N],fa1[N][21],fa2[N][21];
int s[2][N],c[2],Lt[2][N],Rt[2][N],lc[2][N],rc[2][N];
int pos[N],a[N],rt[N],sum[N*8],ch[N*8][2],tot;
struct edge{int u,v,w;edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
bool operator < (const edge& A)const{return w<A.w;}}e[N];
inline int F(int x){if(fa[x]^x)fa[x]=F(fa[x]);return fa[x];}

void dfs(int u,int t){
	if(u<=n)s[t][++c[t]]=u,Lt[t][u]=Rt[t][u]=c[t];
	else{
		dfs(lc[t][u],t),dfs(rc[t][u],t);
		Lt[t][u]=Lt[t][lc[t][u]],Rt[t][u]=Rt[t][rc[t][u]];
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	if(!id||r<L||R<l)return 0;
	if(l<=L&&r>=R)return sum[id];
	return query(L,M,Lid,l,r)+query(M+1,R,Rid,l,r);
}

void update(int L,int R,int& id,int _id,int x){
	id=++tot,sum[id]=sum[_id]+1;
	if(L!=R){
		if(x<=M)update(L,M,Lid,ch[_id][0],x),Rid=ch[_id][1];
		else update(M+1,R,Rid,ch[_id][1],x),Lid=ch[_id][0];
	}
	return;
}

signed main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;i++)U[i]=read()+1,V[i]=read()+1;
	for(int i=1;i<=m;i++)e[i]=edge(U[i],V[i],min(U[i],V[i]));
	c1=c2=n;
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)fa[i]=tp[i]=val1[i]=i;
	for(int i=m,u,v;i>=1;i--){
		u=e[i].u,v=e[i].v;
		int A=F(u),B=F(v);
		if(A!=B){
			val1[++c1]=e[i].w;
			lc[0][c1]=tp[A],rc[0][c1]=tp[B],fa1[tp[A]][0]=fa1[tp[B]][0]=c1;
			fa[B]=A,tp[A]=c1;
		}
	}
	for(int i=1;i<=m;i++)e[i]=edge(U[i],V[i],max(U[i],V[i]));
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)fa[i]=tp[i]=val2[i]=i;
	for(int i=1,u,v;i<=m;i++){
		u=e[i].u,v=e[i].v;
		int A=F(u),B=F(v);
		if(A!=B){
			val2[++c2]=e[i].w;
			lc[1][c2]=tp[A],rc[1][c2]=tp[B],fa2[tp[A]][0]=fa2[tp[B]][0]=c2;
			fa[B]=A,tp[A]=c2;
		}
	}
	for(int i=1;i<21;i++)for(int j=1;j<=max(c1,c2);j++)fa1[j][i]=fa1[fa1[j][i-1]][i-1],fa2[j][i]=fa2[fa2[j][i-1]][i-1];
	dfs(c1,0),dfs(c2,1);
	val1[0]=-INF,val2[0]=INF;	
	for(int i=1;i<=n;i++)pos[s[1][i]]=i;
	for(int i=1;i<=n;i++)a[i]=pos[s[0][i]];
	for(int i=1;i<=n;i++)update(1,n,rt[i],rt[i-1],a[i]);
	for(int i=1,S,T,L,R;i<=q;i++){
		S=read()+1,T=read()+1,L=read()+1,R=read()+1;
		if(S<L||T>R){
			printf("0\n");
			continue;
		}
		for(int j=20;j>=0;j--)if(val1[fa1[S][j]]>=L)S=fa1[S][j];
		for(int j=20;j>=0;j--)if(val2[fa2[T][j]]<=R)T=fa2[T][j];
		int tag=min(1,query(1,n,rt[Rt[0][S]],Lt[1][T],Rt[1][T])-query(1,n,rt[Lt[0][S]-1],Lt[1][T],Rt[1][T]));
		printf("%d\n",tag);
	}
	return 0;
}

