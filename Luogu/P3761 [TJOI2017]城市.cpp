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

const int N=1e4+7,Mod=998244353,INF=1e9+7;
int n,hd[N],nxt[N],to[N],len[N],ec,U[N],V[N],W[N];
int f[N],dis,ans=INF,g[N],D;

inline void add(int u,int v,int w){
	to[++ec]=v,len[ec]=w,nxt[ec]=hd[u],hd[u]=ec;
	return;
}

void dfs(int u,int from){
	f[u]=0;
	for(int i=hd[u],v,w;i;i=nxt[i]){
		v=to[i],w=len[i];
		if(v==from)continue;
		dfs(v,u);
		f[u]=max(f[u],f[v]+w);
	}
//	printf("f[%d]=%d\n",u,f[u]);
	return;
}

void dp(int u,int from,int fw){
	f[u]=max(f[u],fw),dis=min(dis,f[u]);
	int m1=0,m2=0,c1=0;
	for(int i=hd[u],v,w;i;i=nxt[i]){
		v=to[i],w=len[i];
		if(v==from)continue;
		if(f[v]+w==m1)++c1;
		else if(f[v]+w>m1)m2=m1,m1=f[v]+w,c1=1;
		else if(f[v]+w>m2)m2=f[v]+w;
	}
	if(c1>1)g[u]=m1*2;
	else g[u]=m1+m2;
//	printf("g[%d]=%d (%d  %d) fw=%d\n",u,g[u],m1,m2,fw);
	D=max(D,g[u]);
	for(int i=hd[u],v,w;i;i=nxt[i]){
		v=to[i],w=len[i];
		if(v==from)continue;
		if(c1==1&&f[v]+w==m1)dp(v,u,max(fw+w,m2+w));
		else dp(v,u,max(fw+w,m1+w));
	}
	return;
}

int main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		U[i]=u,V[i]=v,W[i]=w;
		add(u,v,w),add(v,u,w);
	}
	for(int i=1,u,v,w,A,B,X,Y;i<n;i++){
		u=U[i],v=V[i],w=W[i];
		dfs(u,v),dis=INF,D=0,dp(u,v,0),A=dis,X=D;
		dfs(v,u),dis=INF,D=0,dp(v,u,0),B=dis,Y=D;
//		printf("(X=%d Y=%d A=%d B=%d) %d\n",X,Y,A,B,max(max(X,Y),A+B+w));
		ans=min(max(max(X,Y),A+B+w),ans);
	}
	printf("%d\n",ans);
	return 0;
}
