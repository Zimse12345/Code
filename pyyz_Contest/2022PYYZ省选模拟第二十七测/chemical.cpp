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
#include <bitset>

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,hd[N],nxt[N],to[N],c[N],ec,vis[N],ans[N],K;
bitset<2100> f[N*6];
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,c[ec]=w;return;}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int ct=0;
		for(int j=0;j<n;j++)if(i&(1<<j))++ct;
		if(ct%2==0){
	 		for(int u=0;u<n;u++)if(!(i&(1<<u))){
				for(int e=hd[u],v;e;e=nxt[e]){
					v=to[e];
					if(!(i&(1<<v)))if(u<v){
						int _i=(i|(1<<u)|(1<<v));
						f[_i]|=(f[i]<<c[e]);
					}
				}
			}
		}
	}
	for(int i=0;i<=n*20;i++)if(f[(1<<n)-1][i]==1)++K;
	if(!K){
		printf("YOU ARE IN TROUBLE\n");
		return 0;
	}
	printf("%d\n",K);
	for(int i=0;i<=n*20;i++)if(f[(1<<n)-1][i]==1)printf("%d ",i);
	printf("\n");
	return 0;
}

