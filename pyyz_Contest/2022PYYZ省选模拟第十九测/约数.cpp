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

const int N=2e7+7,Mod=998244353,INF=1e9+7;
int n,prime[N],t,pr[N],mu[N],d[N],ct[N],ans,sd[N],smu[N];
unordered_map<int,int> SUMD,Mu;

int sum_mu(int x){
	if(x<N)return smu[x];
	if(Mu.count(x))return Mu[x];
	int res=1;
	for(int l=2,r;l<=x;){
		r=x/(x/l);
		res-=(r-l+1)*sum_mu(x/l);
		l=r+1;
	}
	Mu[x]=res;
	return res;
}

int sum_d(int x){
	if(x<N)return sd[x];
	if(SUMD.count(x))return SUMD[x];
	int res=x;
	for(int l=2,r;l<=x;){
		r=x/(x/l);
		res-=sum_d(x/l)*(sum_mu(r)-sum_mu(l-1));
		l=r+1;
	}
	SUMD[x]=res;
	return res;
}

signed main(){
	freopen("d.in","r",stdin);
	mu[1]=d[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])pr[i]=i,prime[++t]=i,mu[i]=-1,d[i]=2,ct[i]=1;
		for(int j=1,x;j<=t&&prime[j]*i<N;j++){
			x=prime[j]*i;
			pr[x]=prime[j],mu[x]=-mu[i],d[x]=d[i]*2,ct[x]=1;
			if(pr[i]==prime[j]){mu[x]=0,ct[x]=ct[i]+1,d[x]=d[i]/ct[x]*(ct[x]+1);break;}
		}
	}
	for(int i=1;i<N;i++)sd[i]=sd[i-1]+d[i],smu[i]=smu[i-1]+mu[i];
	n=read();
	for(int l=1,r;l<=n;){
		r=n/(n/l);
		ans+=(n/l)*(sum_d(r)-sum_d(l-1));
		l=r+1;
	}
	printf("%lld\n",ans);
	return 0;
}

