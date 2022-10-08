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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=1e9+7,INF=1e9+7;
int n,win[N],ans,f[N],_2[N],S[N],suf[N];

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

signed main(){
	_2[0]=1;
	for(int i=1;i<N;i++)_2[i]=(_2[i-1]*2)%Mod;
	for(int j=0;j<N-1;j++){
		int c=_2[j];
		if(j==0)c*=2;
		S[j+1]=(S[j]+c)%Mod;
	}
	n=read();
	f[n+1]=suf[n+1]=1;
	for(int i=n;i>=3;i--){
		int B=min(n,(i-1)*2-1);
		f[i]=suf[i+1]-suf[B+2];
		suf[i]=(f[i]+suf[i+1])%Mod;
	}
	for(int i=2;i<=n;i++){
		int w=f[i+1];
		win[i]=w*S[i/2]%Mod*2;
		ans=(ans+win[i]*i)%Mod;
	}
	ans=(ans+Mod)%Mod;
	if(n==1)ans=2;
	printf("%lld\n",ans);
	return 0;
}

