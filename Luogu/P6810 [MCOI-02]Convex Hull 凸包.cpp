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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,m,p,prime[N],tot,pr[N],d[N],sigma[N],ans;

signed main(){
	n=read(),m=read(),p=read();
	sigma[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])prime[++tot]=i,pr[i]=i,d[i]=1,sigma[i]=2;
		for(int j=1,x;j<=tot&&prime[j]*i<N;j++){
			x=prime[j]*i;
			pr[x]=prime[j],d[x]=1,sigma[x]=sigma[i]*2;
			if(pr[i]==prime[j]){d[x]=d[i]+1,sigma[x]=sigma[i]/d[x]*(d[x]+1);break;}
		}
	}
	for(int T=1;T<=min(n,m);T++){
		int s1=0,s2=0;
		for(int i=1;i*T<=n;i++)(s1+=sigma[i*T])%=p;
		for(int i=1;i*T<=m;i++)(s2+=sigma[i*T])%=p;
		(ans+=s1*s2)%=p;
	}
	printf("%lld\n",ans);
	return 0;
}

