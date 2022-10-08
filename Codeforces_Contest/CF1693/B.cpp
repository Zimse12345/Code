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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,lv[N],rv[N],mx[N],ans;
vector<int> ch[N];

void dfs(int u){
	for(unsigned i=0;i<ch[u].size();i++){
		int v=ch[u][i];
		dfs(v);
		mx[u]+=mx[v];
	}
	mx[u]=min(mx[u],rv[u]);
	if(mx[u]<lv[u])mx[u]=rv[u],++ans;
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read(),ans=0;
		for(int i=2,f;i<=n;i++)f=read(),ch[f].push_back(i);
		for(int i=1;i<=n;i++)lv[i]=read(),rv[i]=read();
		dfs(1);
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)ch[i].resize(0),mx[i]=0;
	}
	return 0;
}

