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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,ans1,ans2;

struct mix{
	int v[3][3];
}w[N],W[N];

void mul(mix& res,const mix A,const mix B){
	for(int i=0;i<3;i++)for(int j=0;j<3;j++){
		res.v[i][j]=0;
		for(int k=0;k<3;k++)res.v[i][j]=(res.v[i][j]+A.v[i][k]*B.v[k][j])%Mod;
	}
	return;
}

signed main(){
	mix A,I;
	A.v[0][0]=0;
	A.v[0][1]=2;
	A.v[0][2]=1;
	A.v[1][0]=1;
	A.v[1][1]=2;
	A.v[1][2]=2;
	A.v[2][0]=0;
	A.v[2][1]=0;
	A.v[2][2]=1;
	
	I.v[0][0]=1;
	I.v[0][1]=0;
	I.v[0][2]=0;
	I.v[1][0]=0;
	I.v[1][1]=1;
	I.v[1][2]=0;
	I.v[2][0]=0;
	I.v[2][1]=0;
	I.v[2][2]=1;
	
	w[0]=W[0]=I;
	for(int i=1;i<N;i++)mul(w[i],A,w[i-1]);
	for(int i=1;i<N;i++)mul(W[i],w[1000000],W[i-1]);
	
	T=read();
	while(T--){
		n=read();
		mix res;
		mul(res,w[n%1000000],W[n/1000000]);
		ans1^=res.v[0][2];
		ans2^=res.v[1][2];
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}

