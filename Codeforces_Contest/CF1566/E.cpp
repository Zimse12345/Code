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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();break;}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,vis[N],tot[N],ans;
vector<int> g[N],ch[N];

void mt(int u,int fa){
	if(vis[u]++)return;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!vis[v])ch[u].push_back(v),mt(v,u);
	}
	tot[u]+=ch[u].size();
	int tag=1;
	for(int i=0;i<ch[u].size();i++)if(tot[ch[u][i]]){tag=0;break;}
	if(tot[u]&&tag&&u!=1){
		ans+=tot[u]-1;
		--tot[fa],tot[u]=0;
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read(),ans=0;
		for(int i=1;i<=n;i++)ch[i].resize(0),g[i].resize(0),vis[i]=tot[i]=0;
		for(int i=1,u,v;i<n;i++){
			u=read(),v=read();
			g[u].push_back(v),g[v].push_back(u);
		}
		mt(1,0);
		ans+=max(1,tot[1]);
		printf("%d\n",ans);
	}
	return 0;
}
