#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N=2e5+7,Mod=1e9+7,INF=1e9+7;
int w,x,y,p[N],a[N],ans,sig[N];
struct mix{int v[2][2];}E,fib[200000],_fib[200000],pr[N];

inline mix mul(mix X,mix Y){
	mix res;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)res.v[i][j]=(X.v[i][0]*Y.v[0][j]+X.v[i][1]*Y.v[1][j])%Mod;
	return res;
}

inline mix qp(mix X,int k){
	mix res=E;
	while(k){
		if(k&1ll)res=mul(res,X);
		X=mul(X,X),k/=2;
	}
	return res;
}

signed main(){
	w=read(),x=read(),y=read();
	mix M;M.v[0][0]=x,M.v[0][1]=y,M.v[1][0]=1,M.v[1][1]=0;
	mix _M;_M.v[0][0]=1,_M.v[0][1]=1,_M.v[1][0]=1,_M.v[1][1]=0;
	E.v[0][0]=E.v[1][1]=1,E.v[0][1]=E.v[1][0]=0;
	for(int i=0;i<w;i++)p[i]=read(),a[i]=read(),pr[i]=qp(M,p[i]-1);
	fib[0]=_M,_fib[0]=E;
	sig[0]=1;
	for(int i=1;i<(1<<w);i++){
		int k=0;
		for(int j=0;j<w;j++)if(i&(1<<j)){k=j;break;}
		_fib[i]=mul(qp(_fib[i^(1<<k)],p[k]),pr[k]),fib[i]=mul(_fib[i],_M);
		sig[i]=-sig[i^(1<<k)];
	}
	for(int i=0;i<(1<<w);i++){
		int T=1,sum=0;
		for(int j=0;j<w;j++){
			if(i&(1<<j))T=(-T*a[j])%Mod;
			else T=(T*(a[j]+1))%Mod;
		}
		for(int j=i;;j=(j-1)&i){
			sum=(sum+sig[j]*fib[j].v[0][0])%Mod;
			if(!j)break;
		}
		ans=(ans+T*sum)%Mod;
	}
	printf("%lld\n",(ans+Mod)%Mod);
	return 0;
}
