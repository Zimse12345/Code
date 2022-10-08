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

const int N=6e4+7,Mod=998244353,INF=1e9+7;
int T,n,m,prime[N],t,pr[N],mu[N],s[N],ans,sum_mu[N];

signed main(){
	mu[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])pr[i]=i,prime[++t]=i,mu[i]=-1;
		for(int j=1;j<=t&&prime[j]*i<N;j++){
			pr[prime[j]*i]=prime[j],mu[prime[j]*i]=-mu[i];
			if(pr[i]==prime[j]){mu[prime[j]*i]=0;break;}
		}
	}
	for(int i=1;i<N;i++)sum_mu[i]=sum_mu[i-1]+mu[i];
	for(int i=1;i<N;i++){
		for(int l=1,r;l<=i;){
			r=i/(i/l);
			s[i]+=(i/l)*(r-l+1);
			l=r+1;
		}
	}
	T=read();
	while(T--){
		n=read(),m=read(),ans=0;
		for(int l=1,r;l<=min(n,m);){
			r=min(n/(n/l),m/(m/l));
			ans+=(sum_mu[r]-sum_mu[l-1])*s[n/l]*s[m/l];
			l=r+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

