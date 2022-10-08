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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();break;}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];
int fac[N],_fac[N];

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		k/=2ll,x=(x*x)%Mod;
	}
	return res;
}

int inv(int x){
	return qp(x,Mod-2);
}

int C(int x,int y){
	if(y>x)return 0;
	return fac[x]*_fac[y]%Mod*_fac[x-y]%Mod;
}

signed main(){
	fac[0]=1,_fac[0]=inv(fac[0]);
	for(int i=1;i<N;i++)fac[i]=(i*fac[i-1])%Mod,_fac[i]=inv(fac[i]);
	
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		
		if(n==1){
			if(a[1]<=1)printf("1\n");
			else printf("0\n");
			continue;
		}
		if(a[n]==a[n-1]){
			printf("%lld\n",fac[n]);
			continue;
		}
		if(a[n]-a[n-1]>1){
			printf("0\n");
			continue;
		}
		
		int c=0;
		for(int i=1;i<=n;i++)if(a[i]==a[n-1])++c;
		int ans=0,p=fac[n-c-1],pp=fac[n-1];
		
		for(int i=1;i<=n;i++)ans=(ans+pp-C(i-1,c)*fac[c]%Mod*p%Mod)%Mod;
		ans=(ans+Mod)%Mod;
		printf("%lld\n",ans);
	}
	return 0;
}
