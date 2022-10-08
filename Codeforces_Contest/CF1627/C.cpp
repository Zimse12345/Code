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
int T,n,lc[N],rc[N],lid[N],rid[N],ans[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		int tag=0;
		for(int i=1;i<=n;i++)lc[i]=rc[i]=0;
		for(int i=1,u,v;i<n;i++){
			u=read(),v=read();
			if(!lc[u])lc[u]=v,lid[u]=i;
			else if(!rc[u])rc[u]=v,rid[u]=i;
			else tag=1;
			if(!lc[v])lc[v]=u,lid[v]=i;
			else if(!rc[v])rc[v]=u,rid[v]=i;
			else tag=1;
		}
		if(tag){
			printf("-1\n");
			continue;
		}
		int u=0;
		for(int i=1;i<=n;i++)if(!rc[i]){
			u=i;
			break;
		}
		int from=0,p=0;
		while(1){
			if(lc[u]==from)ans[rid[u]]=p?2:3,from=u,u=rc[u];
			else ans[lid[u]]=p?2:3,from=u,u=lc[u];
			p^=1;
			if(!rc[u])break;
		}
		for(int i=1;i<n;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}

