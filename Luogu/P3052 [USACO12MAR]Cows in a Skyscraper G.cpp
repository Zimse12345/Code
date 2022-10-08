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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,w,a[N],f[N],g[N];

signed main(){
	n=read(),w=read();
	for(int i=0;i<n;i++)a[i]=read();
	for(int i=0;i<(1<<n);i++)f[i]=INF;
	f[0]=1,g[0]=w;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++)if(!(i&(1<<j))){
			int t=i|(1<<j),p=f[i],rm=g[i]-a[j];
			if(rm<0)rm=w-a[j],++p;
			if(p<f[t]){
				f[t]=p,g[t]=g[i]-a[j];
				if(g[t]<0)g[t]=w-a[j];
			}
			else if(p==f[t]&&rm>g[t])g[t]=rm;
		}
	}
	printf("%lld\n",f[(1<<n)-1]);
	return 0;
}

