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
#include <unordered_map>

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e7+7,Mod=998244353,INF=1e9+7;
int T,n,prime[N],t,pr[N],phi[N],mu[N];
int sum_phi[N],sum_mu[N];
unordered_map<int,int> Phi,Mu;

int calc_phi(int x){
	if(x<N)return sum_phi[x];
	if(Phi.count(x))return Phi[x];
	int res=x*(x+1)/2,l=2,r;
	while(1){
		r=x/(x/l);
		res-=(r-l+1)*calc_phi(x/l);
		l=r+1;
		if(l>x)break;
	}
	Phi[x]=res;
	return res;
}

int calc_mu(int x){
	if(x<N)return sum_mu[x];
	if(Mu.count(x))return Mu[x];
	int res=1,l=2,r;
	while(1){
		r=x/(x/l);
		res-=(r-l+1)*calc_mu(x/l);
		l=r+1;
		if(l>x)break;
	}
	Mu[x]=res;
	return res;
}

signed main(){
	phi[1]=mu[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])pr[i]=i,prime[++t]=i,phi[i]=i-1,mu[i]=-1;
		for(int j=1,x;j<=t&&prime[j]*i<N;j++){
			x=prime[j]*i;
			pr[x]=prime[j],phi[x]=(prime[j]-1)*phi[i],mu[x]=-mu[i];
			if(pr[i]==prime[j]){phi[x]=prime[j]*phi[i],mu[x]=0;break;}
		}
	}
	for(int i=1;i<N;i++)sum_phi[i]=sum_phi[i-1]+phi[i],sum_mu[i]=sum_mu[i-1]+mu[i];
	
	T=read();
	while(T--){
		n=read();
		printf("%lld %lld\n",calc_phi(n),calc_mu(n));
	}
	return 0;
}

