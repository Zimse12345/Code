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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,pr[N],prime[N],t,phi[N],g[N];

signed main(){
	T=read(),phi[1]=g[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])pr[i]=i,prime[++t]=i,phi[i]=i-1,g[i]=i*(i-1)+1;
		for(int j=1;j<=t&&prime[j]*i<N;j++){
			pr[i*prime[j]]=prime[j];
			if(pr[i]==prime[j]){
				phi[i*prime[j]]=phi[i]*prime[j];
				g[i*prime[j]]=g[i]+(g[i]-g[i/prime[j]])*prime[j]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
			g[i*prime[j]]=g[i]*g[prime[j]];
		}
	}
	while(T--){
		int n=read();
		printf("%lld\n",n*(g[n]+1)/2);
	}
	return 0;
}

