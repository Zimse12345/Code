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

const int N=1e5+7,Mod=1e9+7,INF=1e9+7;
int T,n,a[N],b[N],d[N],to[N],vis[N],pa[N],cnt;

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),vis[i]=0,pa[a[i]]=i;
		for(int i=1;i<=n;i++)b[i]=read(),to[pa[b[i]]]=i;
		for(int i=1;i<=n;i++){
			d[i]=read();
			if(d[i]){
				int j=i;
				while(!vis[j])vis[j]=1,j=to[j];
			}
		}
		cnt=0;
		int ans=1;
		for(int i=1;i<=n;i++)if(!vis[i]&&!d[i]){
			int sz=0,j=i;
			while(!vis[j])vis[j]=1,++sz,j=to[j];
			if(sz>1)ans=(ans*2)%Mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

