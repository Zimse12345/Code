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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,t[N],ans,ed[N];
vector<int> pr[N];

void dfs(int u){
	if(ed[u]++)return;
	ans+=t[u];
	for(int i=0;i<signed(pr[u].size());i++)dfs(pr[u][i]);
	return;
}

signed main(){
	n=read();
	for(int i=1,m;i<=n;i++){
		t[i]=read(),m=read();
		for(int j=1;j<=m;j++)pr[i].push_back(read());
	}
	dfs(n);
	printf("%lld\n",ans);
	return 0;
}
