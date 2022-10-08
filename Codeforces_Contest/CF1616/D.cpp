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
int T,n,a[N],x,f[N],g[N],k[N],ans; 

signed main(){
	T=read();
	while(T--){
		n=read(),ans=1;
		for(int i=1;i<=n;i++)a[i]=read();
		x=read();
		f[1]=1,k[1]=a[1]-x;
		for(int i=2;i<=n;i++){
			a[i]-=x;
			f[i]=g[i-1]+1,g[i]=max(f[i-1],g[i-1]);
			if(a[i]+k[i-1]>=0&&f[i-1]+1>f[i])f[i]=f[i-1]+1,k[i]=min(k[i-1]+a[i],a[i]);
			else k[i]=a[i];
			ans=max(ans,max(f[i],g[i]));
		}
		printf("%d\n",ans);
	}
	return 0;
}

