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

const int N=1e5+7,Mod=998244353,INF=1e12+7;
int n,k,a[N],f[N][32],t[N],ans,nl=1,nr,tr[N];

inline void db(int& x){x-=(x&(-x));return;}
inline void ub(int& x){x+=(x&(-x));return;}
inline void add(int x,int t){for(;x<N;ub(x))tr[x]+=t;return;}
inline int sum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}

void calc(int l,int r){
	while(nr<r){
		++nr;
		ans+=sum(n)-sum(a[nr]);
		add(a[nr],1);
	}
	while(nl>l){
		--nl;
		ans+=sum(a[nl]);
		add(a[nl],1);
	}
	while(nr>r){
		add(a[nr],-1);
		ans-=sum(n)-sum(a[nr]);
		--nr;
	}
	while(nl<l){
		add(a[nl],-1);
		ans-=sum(a[nl]);
		++nl;
	}
	return;
}

void sol(int L,int R,int l,int r,int t){
	if(R<L)return;
	int v=INF,pos=0,M=(L+R)>>1;
	for(int j=min(M,r);j>=l;j--){
		calc(j,M);
		if(ans+f[j-1][t-1]<v)v=ans+f[j-1][t-1],pos=j;
	}
	f[M][t]=v;
	sol(L,M-1,l,pos,t),sol(M+1,R,pos,r,t);
	return;
}

signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=n-read()+1,f[i][0]=INF;
	for(int i=1;i<=k;i++)sol(1,n,1,n,i);
	printf("%lld\n",f[n][k]);
	return 0;
}

