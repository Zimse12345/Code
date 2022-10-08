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

const int N=3e3+7,Mod=998244353,INF=1e9+7;
int n,a,d,len;
char m[N];

struct mix{int v[107][107];}E,A,ans;

inline mix add(mix A,mix B,int sz){
	mix res;
	for(int i=1;i<=sz;i++)for(int j=1;j<=sz;j++)res.v[i][j]=(A.v[i][j]+B.v[i][j])%Mod;
	return res;
}

inline mix mul(mix A,mix B,int sz){
	mix res;
	for(int i=1;i<=sz;i++)for(int j=1;j<=sz;j++)res.v[i][j]=0;
	for(int i=1;i<=sz;i++)for(int j=1;j<=sz;j++)for(int k=1;k<=sz;k++)res.v[i][j]=(res.v[i][j]+A.v[i][k]*B.v[k][j])%Mod;
	return res;
}

inline mix _mul(mix A,int k,int sz){
	mix res;
	for(int i=1;i<=sz;i++)for(int j=1;j<=sz;j++)res.v[i][j]=(A.v[i][j]*k)%Mod;
	return res;
}

inline mix mqp(mix A,int k,int sz){
	mix res=E;
	while(k){
		if(k&1ll)res=mul(res,A,sz);
		A=mul(A,A,sz),k/=2;
	}
	return res;
}

inline void see(mix A,int sz){
	for(int i=1;i<=sz;i++){
		for(int j=1;j<=sz;j++)printf("%lld ",A.v[i][j]);
		printf("\n");
	}
	printf("\n");
	return;
}

signed main(){
	n=read(),a=read(),d=read(),scanf("%s",m+1),len=strlen(m+1);
	for(int i=1;i<=max(n,2ll);i++)E.v[i][i]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)A.v[i][j]=read();
	mix fib;fib.v[1][1]=fib.v[1][2]=fib.v[2][1]=1,fib.v[2][2]=0;
	int M=0;
	for(int i=1;i<=len;i++)M=(M*2+m[i]-'0');
	mix AA=E,BB=mqp(fib,a,2ll),CC=mqp(fib,d,2ll);
	for(int i=0;i<=M;i++)ans=add(ans,_mul(AA,BB.v[2][1],n),n),AA=mul(AA,A,n),BB=mul(BB,CC,2ll);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)printf("%lld ",ans.v[i][j]);
		printf("\n");
	}
	return 0;
}

