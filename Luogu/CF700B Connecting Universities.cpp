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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,k,cnt[N],hd[N],nxt[N],to[N],ec,ans;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs(int u,int from){
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u),cnt[u]+=cnt[v];
		ans+=min(cnt[v],k*2-cnt[v]);
	}
	return;
}

signed main(){
	n=read(),k=read();
	for(int i=1;i<=k*2;i++)cnt[read()]=1;
	for(int i=1,x,y;i<n;i++)x=read(),y=read(),add(x,y),add(y,x);
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}

