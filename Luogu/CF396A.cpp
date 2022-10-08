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

const int N=1e6+7,Mod=1e9+7,INF=1e9+7;
int n,b[N],t,p[N],fac[N],_fac[N];

inline int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2;
	}
	return res;
}

inline int inv(int x){
	return qp(x,Mod-2);
}

inline int C(int x,int y){
	if(y==0)return 1;
	return fac[x]*_fac[y]%Mod*_fac[x-y]%Mod;
}

signed main(){
	n=read();
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=(fac[i-1]*i)%Mod;
	_fac[N-1]=inv(fac[N-1]);
	for(int i=N-2;i>=0;i--)_fac[i]=(_fac[i+1]*(i+1))%Mod;
	
	for(int i=1,v;i<=n;i++){
		v=read();
		for(int j=2;j*j<=v;j++)while(v%j==0)++p[j],v/=j;
		if(v>1){
			if(v<N)++p[v];
			else b[++t]=v;
		}
	}
	int ans=1,s=0;
	for(int i=1;i<N;i++)if(p[i])ans=(ans*C(n+p[i]-1,n-1))%Mod;
	
	sort(b+1,b+t+1);
	for(int i=1;i<=t;i++){
		if(b[i]!=b[i-1]){
			if(s>0)ans=(ans*C(n+s-1,n-1))%Mod;
			s=1;
		}
		else ++s;
	}
	ans=(ans*C(n+s-1,n-1))%Mod;
	printf("%lld\n",ans);
	return 0;
}
