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
int n,k,a[N],ans,fac[N],pre[N],suf[N];

inline int fpow(int x,int y){
	int z=1;
	while(y){
		if(y&1ll)z=z*x%Mod;
		x=x*x%Mod,y/=2;
	}
	return z;
}

inline int inv(int x){
	return fpow(x,Mod-2);
}

inline int calc(int l,int r){
	if(r<l)return 1;
	if(l>0)return fac[r]*inv(fac[l-1])%Mod;
	if(r<0)return fac[-l]*inv(fac[-r-1])*(((r-l+1)&1)?-1:1)%Mod;
	return 0;
}

signed main(){
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod;
	n=read(),k=read();
	for(int i=1;i<=k+2;i++)a[i]=(fpow(i,k)+a[i-1])%Mod;
	pre[0]=suf[k+3]=1;
	for(int i=1;i<=k+2;i++)pre[i]=pre[i-1]*(n-i)%Mod;
	for(int i=k+2;i>=1;i--)suf[i]=suf[i+1]*(n-i)%Mod;
	for(int i=1;i<=k+2;i++){
		int p=pre[i-1]*suf[i+1]%Mod;
		int q=calc(i-(i-1),i-1)*calc(i-(k+2),i-(i+1))%Mod;
		(ans+=a[i]*p%Mod*inv(q)%Mod)%=Mod;
	}
	ans=(ans+Mod)%Mod;
	printf("%lld\n",ans);
	return 0;
}

