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

const int N=1e6+7,Mod=1e9+7,INF=1e9+7;
int T,n,m,fac[N],_fac[N],pre[N];

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2;
	}
	return res;
}

int inv(int x){
	return qp(x,Mod-2);
}

int C(int x,int y){
	return fac[x]*_fac[y]%Mod*_fac[x-y]%Mod;
}

int sol(int x){
	int res=fac[x]*pre[x]%Mod;
	return (res+Mod)%Mod;
}

signed main(){
	T=read();
	fac[0]=_fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=(fac[i-1]*i)%Mod,_fac[i]=inv(fac[i]);
	pre[0]=1;
	for(int i=1,t=0;i<N;i++,t^=1){
		if(t)pre[i]=(pre[i-1]+_fac[i])%Mod;
		else pre[i]=(pre[i-1]-_fac[i])%Mod;
	}
	while(T--){
		n=read(),m=read();
		if(n<m){
			printf("0\n");
			continue;
		}
		printf("%lld\n",C(n,m)*sol(n-m)%Mod);
	}
	return 0;
}

