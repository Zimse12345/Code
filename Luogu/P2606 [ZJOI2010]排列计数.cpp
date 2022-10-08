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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,INF=1e9+7;
int n,m,cnt[N],fac[N],_fac[N],f[N];

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%m;
		x=(x*x)%m,k/=2;
	}
	return res;
}

int inv(int x){
	return qp(x,m-2);
}

int C(int x,int y){
	if(x==y||y==0)return 1;
	if(y>x)return 0;
	return fac[x]*_fac[y]%m*_fac[x-y]%m;
}

int Lucas(int a,int b){
	if(!b)return 1;
	return C(a%m,b%m)*Lucas(a/m,b/m)%m;
}

signed main(){
	n=read(),m=read();
	fac[0]=1;
	int sz=min(m-1,n); 
	for(int i=1;i<=sz;i++)fac[i]=(fac[i-1]*i)%m;
	_fac[sz]=inv(fac[sz]);
	for(int i=sz-1;i>=0;i--)_fac[i]=(_fac[i+1]*(i+1))%m;
	for(int i=n;i>=1;i--){
		if(i*2>n)f[i]=1,cnt[i]=1;
		else if(i*2==n)f[i]=f[i*2],cnt[i]=cnt[i*2]+1;
		else cnt[i]=cnt[i*2]+cnt[i*2+1]+1,f[i]=f[i*2]*f[i*2+1]%m*Lucas(cnt[i]-1,cnt[i*2])%m;
	} 
	printf("%lld\n",f[1]);
	return 0;
}
