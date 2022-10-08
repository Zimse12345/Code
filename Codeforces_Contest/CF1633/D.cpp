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
int T,n,k,g[N],a[N],c[N],f[N*N];

signed main(){
	T=read();
	g[1]=0;
	for(int i=2;i<N;i++){
		g[i]=INF;
		for(int j=1;j<i;j++){
			for(int x=1;x<=j;x++)if(j+j/x==i)g[i]=min(g[i],g[j]+1);
		}
	}
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;i++)a[i]=g[read()];
		for(int i=1;i<=n;i++){
			c[i]=read();
			for(int j=k;j>=a[i];j--)f[j]=max(f[j],f[j-a[i]]+c[i]);
		}
		int ans=0;
		for(int i=0;i<=k;i++)ans=max(ans,f[i]),f[i]=0;
		printf("%d\n",ans);
	}
	return 0;
}

