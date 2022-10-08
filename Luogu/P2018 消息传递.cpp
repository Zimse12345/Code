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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,f[N],t[N],ans=INF;
vector<int> g[N];

void dfs(int u,int from){
	f[u]=0;
	vector<int> a;a.resize(0);
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v==from)continue;
		dfs(v,u),a.push_back(f[v]);
	}
	sort(a.begin(),a.end());
	for(int i=signed(a.size())-1,j=1;i>=0;i--,j++)f[u]=max(f[u],a[i]+j);
	return;
}

int main(){
	n=read();
	for(int i=2,s;i<=n;i++)s=read(),g[s].push_back(i),g[i].push_back(s);
	for(int i=1;i<=n;i++)dfs(i,0),t[i]=f[i],ans=min(ans,t[i]);
	printf("%d\n",ans+1);
	for(int i=1;i<=n;i++)if(ans==t[i])printf("%d ",i);
	printf("\n");
	return 0;
}
