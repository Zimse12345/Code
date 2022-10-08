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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7;
int T,n,num[N],dp[N],hd[N],nxt[N*2],to[N*2],ec,l=0,r=1000000000;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs(int x,int sz,int from){
	dp[x]=0;
	for(int i=hd[x],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,sz,x);
		dp[x]+=dp[v];
	}
	dp[x]=max(dp[x]-1,0ll),dp[x]+=(num[x]>=sz);
	return;
}

signed main(){
	n=read();
	for(int i=2;i<=n;++i)num[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	while(l<=r){
		int mid=(l+r)>>1ll;
		dfs(1,mid,0);
		if(!dp[1])r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",r);
	return 0;
}

