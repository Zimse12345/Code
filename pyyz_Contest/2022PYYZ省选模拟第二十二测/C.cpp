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

const int N=5e6+7,Mod=998244353,INF=1e9+7;
int n,prime[N],t,pr[N],phi[N],mu[N],sigma[N],e[N],ans;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}

signed main(){
	n=read();
	mu[1]=sigma[1]=phi[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])prime[++t]=i,pr[i]=i,phi[i]=i-1,mu[i]=-1,sigma[i]=2,e[i]=1;
		for(int j=1,v;j<=t&&prime[j]*i<N;j++){
			v=prime[j]*i;
			pr[v]=prime[j],phi[v]=(prime[j]-1)*phi[i],mu[v]=-mu[i],sigma[v]=sigma[i]*2,e[v]=1;
			if(pr[i]==prime[j]){phi[v]=prime[j]*phi[i],mu[v]=0,sigma[v]=sigma[i]/(e[i]+1)*(e[i]+2),e[v]=e[i]+1;}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(gcd(i,j)==1){
		for(int k=1;k<=n;k++)ans=(ans+mu[i*j]*phi[i*k]%Mod*sigma[j*k])%Mod;
	}
	ans=(ans+Mod)%Mod;
	printf("%lld\n",ans);
	return 0;
}

