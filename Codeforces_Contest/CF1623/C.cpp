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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,h[N],a[N];

bool check(int x){
	for(int i=1;i<=n;i++)a[i]=0;
	for(int i=n;i>=3;i--){
		if(h[i]+a[i]<x)return false;
		int b=min(h[i],h[i]+a[i]-x)/3;
		a[i-1]+=b,a[i-2]+=b*2;
	}
	if(h[1]+a[1]<x||h[2]+a[2]<x)return false;
	return true;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)h[i]=read();
		int L=1,R=1e9,ans=0;
		while(L<=R){
			int M=(L+R)>>1;
			if(check(M))ans=M,L=M+1;
			else R=M-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

