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

const int N=1e4+7,Mod=998244353,INF=1e9+7;
int n,m,prime[N],t;
int f[N],g[N];

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%m;
		x=(x*x)%m,k/=2;
	}
	return res;
}

signed main(){
	n=read(),m=read();
	int ans=0;
	for(int i=2;i<=n;i++){
		int tag=0;
		for(int j=2;j*j<=i;j++)if(i%j==0){
			tag=1;
			break;
		}
		if(tag==0)prime[++t]=i;
	}
	f[0]=1;
	for(int i=1;i<=t;i++){
		for(int i=0;i<=n;i++)g[i]=f[i];
		for(int k=1;qp(prime[i],k)<=n;k++){
			int w=qp(prime[i],k);
			for(int j=n;j>=w;j--)f[j]=(f[j]+g[j-w]*w)%m;
		}
	}
	for(int i=0;i<=n;i++)ans=(ans+f[i])%m;
	printf("%lld\n",ans);
	return 0;
}
