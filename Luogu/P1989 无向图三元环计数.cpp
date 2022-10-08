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
int n,m,eu[N*2],ev[N*2],deg[N],vis[N],ans;
vector<int> e[N];

signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)eu[i]=read(),ev[i]=read(),++deg[eu[i]],++deg[ev[i]];
	for(int i=1,u,v;i<=m;i++){
		u=eu[i],v=ev[i];
		if(deg[v]>deg[u]||(deg[v]==deg[u]&&v>u))e[u].push_back(v);
		else e[v].push_back(u);
	}
	for(int u=1;u<=n;u++){
		for(int i=0;i<signed(e[u].size());i++)vis[e[u][i]]=u;
		for(int i=0,v;i<signed(e[u].size());i++){
			v=e[u][i];
			for(int j=0;j<signed(e[v].size());j++)if(vis[e[v][j]]==u)++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}

