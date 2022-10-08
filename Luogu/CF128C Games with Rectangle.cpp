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

const int N=1e3+7,Mod=1e9+7;
int n,m,k,ans,f[N],g[N];

signed main(){
	n=read(),m=read(),k=read();
	if(n<m)swap(n,m);
	for(int i=1;i<=n;i++)f[i]=1;
	for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)g[j]=(g[j-1]+f[j])%Mod,f[j]=(f[j-1]+((j>1)?g[j-2]:0))%Mod;
	ans=f[n]*f[m]%Mod;
	printf("%lld\n",ans);
	return 0;
}

