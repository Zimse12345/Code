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

const int N=2e4+7,Mod=998244353,INF=1e5;
int n,m,c[N],f[N][3],ans=INF;
int hd[N],nxt[N],to[N],ec;

void add(int u,int v){
	to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;
	return;
}

void dp(int u,int from){
	f[u][0]=f[u][1]=f[u][2]=0;
	if(u<=m){
		f[u][0]=1;
		if(c[u]==1)f[u][2]=INF;
		if(c[u]==2)f[u][1]=INF;
	}
	else{
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(v==from)continue;
			dp(v,u),f[u][0]+=f[v][0];
			f[u][1]+=min(f[v][1],f[v][0]),f[u][2]+=min(f[v][2],f[v][0]);
		}
		f[u][0]=min(f[u][0],min(f[u][1]+1,f[u][2]+1));
	}
	return;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)c[i]=read()+1;
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		add(u,v),add(v,u);
	}
	dp(m+1,0),ans=min(ans,f[m+1][0]);
	printf("%d\n",ans);
	return 0;
}
