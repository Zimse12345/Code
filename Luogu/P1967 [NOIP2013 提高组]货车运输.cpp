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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,q,fa[N],cnt[N],ct,p[N];
int hd[N],nxt[N],to[N],c[N],ec,vis[N];
int dep[N],Fa[N][18],fw[N][18]; 
struct edge{
	int u,v,w;
	edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
	bool operator < (const edge& A)const{return w>A.w;}
}e[N];
inline int F(int x){if(fa[x]!=x)fa[x]=F(fa[x]);return fa[x];}
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,c[ec]=w;return;}

void dfs(int u,int d){
	dep[u]=d;
	for(int i=hd[u];i;i=nxt[i])dfs(to[i],d+1);
	return;
}

signed main(){
	n=ct=read(),m=read();
	for(int i=1;i<=n;i++)fa[i]=p[i]=i,cnt[i]=1;
	for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),e[i]=edge(u,v,w);
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int A=F(e[i].u),B=F(e[i].v);
		if(A^B){
			if(cnt[A]<cnt[B])swap(A,B);
			++ct,add(ct,p[A],e[i].w),add(ct,p[B],e[i].w);
			Fa[p[A]][0]=Fa[p[B]][0]=ct,fw[p[A]][0]=fw[p[B]][0]=e[i].w;
			cnt[A]+=cnt[B],fa[B]=A,p[A]=ct;
		}
	}
	for(int i=1,x;i<=n;i++){
		x=F(i);
		if(!vis[x])vis[x]=1,dfs(p[x],1);
	}
	q=read();
	for(int i=1;i<=17;i++)for(int j=1;j<=ct;j++)Fa[j][i]=Fa[Fa[j][i-1]][i-1],fw[j][i]=min(fw[j][i-1],fw[Fa[j][i-1]][i-1]);
	while(q--){
		int x=read(),y=read(),A=F(x),B=F(y),ans=INF;
		if(A^B)printf("-1\n");
		else{
			if(dep[x]<dep[y])swap(x,y);
			for(int i=17;i>=0;i--)if(dep[Fa[x][i]]>=dep[y])ans=min(ans,fw[x][i]),x=Fa[x][i];
			for(int i=17;i>=0;i--)if(Fa[x][i]^Fa[y][i])ans=min(ans,min(fw[x][i],fw[y][i])),x=Fa[x][i],y=Fa[y][i];
			if(x^y)ans=min(ans,min(fw[x][0],fw[y][0]));
			printf("%d\n",ans);
		}
	}
	return 0;
}

