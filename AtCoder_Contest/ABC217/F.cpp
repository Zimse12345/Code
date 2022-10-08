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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,p[N][N],f[N][N],vis[N][N];
int fac[N],_fac[N];

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		k/=2ll,x=(x*x)%Mod;
	}
	return res;
}

int C(int a,int b){
	return fac[a]*_fac[b]%Mod*_fac[a-b]%Mod;
}

int inv(int x){
	return qp(x,Mod-2);
}

int dp(int l,int r){
	if(l==r)return 0;
	if(l>r)return 1;
	if(vis[l][r])return f[l][r];
	int res=0;
	for(int i=l+1;i<=r;i++)if(p[l][i]){
		int w=(dp(l+1,i-1)*dp(i+1,r))%Mod; //[l,i],[i+1,r]
		int L=(i-l+1)/2,R=(r-i)/2;
		if(w>0){
			res=(res+C(L+R,L)*w)%Mod;
		}
	}
	vis[l][r]=1,f[l][r]=res;
	return res;
}

signed main(){
	n=read()*2,m=read();
	fac[0]=_fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=(fac[i-1]*i)%Mod;
		_fac[i]=inv(fac[i]);
	}
	
	for(int i=1,a,b;i<=m;i++){
		a=read(),b=read();
		p[a][b]=p[b][a]=1;
	}
	printf("%lld\n",dp(1,n));
	return 0;
}
