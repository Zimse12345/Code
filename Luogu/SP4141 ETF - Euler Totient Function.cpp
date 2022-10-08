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

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int T,pr[N],prime[N],t,phi[N],g[N];

signed main(){
	T=read();
	for(int i=2;i<N;i++){
		if(!pr[i])pr[i]=i,prime[++t]=i;
		for(int j=1;j<=t&&prime[j]*i<N;j++){
			pr[i*prime[j]]=prime[j];
			if(pr[i]==prime[j])break;
		}
	}
	phi[1]=1;
	for(int i=2;i<N;i++){
		if(pr[i]==i)phi[i]=i-1;
		else if(pr[i]==pr[i/pr[i]])phi[i]=phi[i/pr[i]]*pr[i];
		else phi[i]=phi[i/pr[i]]*phi[pr[i]];
	}
	while(T--){
		int n=read();
		printf("%lld\n",phi[n]);
	}
	return 0;
}

