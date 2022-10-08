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

const int N=4e5+7,Mod=1e9+7,INF=1e9+7;
int n,a[N],ans,fac[N],invfac[N];

inline int fpow(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2;
	}
	return res;
}

inline int inv(int x){
	return fpow(x,Mod-2);
}

inline int C(int x,int y){
	return fac[x]*invfac[y]%Mod*invfac[x-y]%Mod;
}

signed main(){
	fac[0]=invfac[0]=1;
	for(int i=1;i<N;i++)fac[i]=(fac[i-1]*i)%Mod,invfac[i]=inv(fac[i]);
	n=read();
	for(int i=1;i<=n+1;i++){
		a[i]=read();
		ans=(ans+C(a[i]+i-1,i))%Mod;
	}
	printf("%lld\n",ans);
	return 0;
}

