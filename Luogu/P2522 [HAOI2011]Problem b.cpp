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
int T,pr[N],prime[N],t,mu[N],sm[N];

int sol(int n,int m,int k){
	n/=k,m/=k;
	int ans=0;
	for(int l=1,r;l<=min(n,m);l=r+1){
		r=min(n/(n/l),m/(m/l));
		r=min(r,min(n,m));
		ans+=(n/l)*(m/l)*(sm[r]-sm[l-1]);
	}
	return ans;
}

signed main(){
	T=read();
	for(int i=2;i<N;i++){
		if(!pr[i])pr[i]=i,prime[++t]=i;
		for(int j=1;j<=t&&prime[j]*i<N;j++){
			pr[i*prime[j]]=prime[j];
			if(pr[i]==prime[j])break;
		}
	}
	sm[1]=mu[1]=1;
	for(int i=2;i<N;i++){
		if((i/pr[i])%pr[i]==0)mu[i]=0;
		else mu[i]=-mu[i/pr[i]];
		sm[i]=sm[i-1]+mu[i];
	}
	
	while(T--){
		int a=read(),b=read(),c=read(),d=read(),k=read();//(a,c),(b,d)
		printf("%lld\n",sol(b,d,k)-sol(a-1,d,k)-sol(b,c-1,k)+sol(a-1,c-1,k));
	}
	return 0;
}

