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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N],b[N];

bool check(int t){
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		if(b[i]<t)y+=(t-b[i])/2;
		else x+=b[i]-t;
	}
	if(x<=y)return true;
	return false;
}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++)b[i]=0;
		for(int i=1;i<=m;i++)a[i]=read(),b[a[i]]++;
		int L=1,R=m,ans=m;
		while(L<=R){
			int M=(L+R)/2;
			if(check(M))ans=M,R=M-1;
			else L=M+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

