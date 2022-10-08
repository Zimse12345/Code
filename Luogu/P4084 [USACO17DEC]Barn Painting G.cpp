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

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=1e9+7,INF=1e9+7;
int n,k,c[N],f[N][3],t;
vector<int> g[N];

void dp(int u,int from){
	f[u][0]=f[u][1]=f[u][2]=1;
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v==from)continue;
		dp(v,u);
		f[u][0]=(f[u][0]*((f[v][1]+f[v][2])%Mod))%Mod;
		f[u][1]=(f[u][1]*((f[v][0]+f[v][2])%Mod))%Mod;
		f[u][2]=(f[u][2]*((f[v][0]+f[v][1])%Mod))%Mod;
	}
	if(c[u])t=f[u][c[u]-1],f[u][0]=f[u][1]=f[u][2]=0,f[u][c[u]-1]=t;
	return;
}

signed main(){
	n=read(),k=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1,x,y;i<=k;i++)x=read(),y=read(),c[x]=y;
	dp(1,0);
	printf("%lld\n",(f[1][0]+f[1][1]+f[1][2])%Mod);
	return 0;
}
