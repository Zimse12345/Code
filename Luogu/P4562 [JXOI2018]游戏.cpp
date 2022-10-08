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

const int N=2e7+7,Mod=1e9+7,INF=1e9+7;
int l,r,p[N],s[N],t,fac[N],_fac[N],ans;

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
	if(y>x)return 0;
	if(x==y)return 1;
	return fac[x]*_fac[y]%Mod*_fac[x-y]%Mod;
}

signed main(){
	l=read(),r=read();
	for(int i=l;i<=r;i++)if(!p[i]){
		s[++t]=i;
		for(int j=2;i*j<=r;j++)p[i*j]=1;
	}
	r=r-l+1-t,l=t;
	fac[0]=1;
	for(int i=1;i<=l+r;i++)fac[i]=(fac[i-1]*i)%Mod;
	_fac[l+r]=inv(fac[l+r]);
	for(int i=l+r-1;i>=0;i--)_fac[i]=(_fac[i+1]*(i+1))%Mod;
	int p=1;
	for(int i=0;i<=r;i++){
		int k=_fac[i]%Mod*p%Mod*(l+i)%Mod;
		ans=(ans+k)%Mod,p=(p*(l+i))%Mod;
	}
	ans=ans*fac[l]%Mod*fac[r]%Mod;
	printf("%lld\n",ans);
	return 0;
}

