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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,cnt[N],ans;
vector<int> to[N];

void dfs(int u,int from){
	cnt[u]=1;
	int s1=0,s2=0;
	int sum=0,sum2=0;
	for(unsigned i=0;i<to[u].size();i++){
		int v=to[u][i];
		if(v==from)continue;
		dfs(v,u);
		cnt[u]+=cnt[v];
		sum2+=cnt[v]*cnt[v];
		int k=cnt[v]*(cnt[v]-1)/2;
		s1+=k,s2+=k*k;
	}
	sum=cnt[u]-1;
	sum+=(sum*sum-sum2)/2;
	ans+=sum*(n-cnt[u])*(n-cnt[u]-1);
	ans-=(s1*s1-s2);
	return;
}

signed main(){
	n=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		to[u].push_back(v),to[v].push_back(u);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}

