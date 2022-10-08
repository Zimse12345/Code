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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,prime[N],t,pr[N],mu[N],g[N],ans;

signed main(){
	n=read(),m=read();
	if(m<n)swap(n,m);
	mu[1]=g[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])pr[i]=i,prime[++t]=i,mu[i]=-1,g[i]=i-1;
		for(int j=1;j<=t&&prime[j]*i<N;j++){
			pr[prime[j]*i]=prime[j],mu[prime[j]*i]=-mu[i],g[prime[j]*i]=g[prime[j]]*g[i];
			if(pr[i]==prime[j]){mu[prime[j]*i]=0,g[prime[j]*i]=prime[j]*g[i];break;}
		}
	}
	for(int i=1;i<=n;i++)ans=ans+g[i]*(n/i)*(m/i);
	printf("%lld\n",ans*2-n*m);
	return 0;
}

