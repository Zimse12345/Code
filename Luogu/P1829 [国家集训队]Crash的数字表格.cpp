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

const int N=5e6+7,INF=1e9+7,P=20101009;
int n,m,ans,inv2;
int prime[N],t,pr[N],phi[N],mu[N],f[N];
map<int,int> val;
inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%P;x=(x*x)%P,k/=2;}return res;}
inline int inv(int x){return qp(x,P-2);}
inline int calc(int x){x%=P;return x*(x+1)%P*inv2%P;}

signed main(){
	n=read(),m=read();
	if(m<n)swap(n,m);
	phi[1]=mu[1]=f[1]=1,inv2=inv(2);
	for(int i=2;i<N;i++){
		if(!pr[i])prime[++t]=i,pr[i]=i,phi[i]=(i-1)%P,mu[i]=-1,f[i]=1-i;
		for(int j=1;j<=t&&prime[j]*i<N;j++){
			pr[prime[j]*i]=prime[j],phi[prime[j]*i]=phi[i]*(prime[j]-1)%P,mu[prime[j]*i]=-mu[i],f[prime[j]*i]=(f[i]*f[prime[j]])%P;
			if(pr[i]==prime[j]){phi[prime[j]*i]=phi[i]*prime[j]%P,mu[prime[j]*i]=0,f[prime[j]*i]=f[i];break;}
		}
	}
	for(int T=1;T<=n;T++){
		ans=(ans+calc(n/T)*calc(m/T)%P*T%P*f[T])%P;
	}
	ans=(ans+P)%P;
	printf("%lld\n",ans);
	return 0;
}

