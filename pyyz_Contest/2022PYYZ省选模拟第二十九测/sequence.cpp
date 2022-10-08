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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],ans;

bool check(int x){
	int L=a[1]-x,R=a[1]+x;
	for(int i=2;i<=n;i++){
		++L,++R;
		if(a[i]+x<L)return false;
		L=max(L,a[i]-x),R=a[i]+x;
	}
	return L<=R;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int L=0,R=1e9;
	while(L<=R){
		int M=(L+R)>>1;
		if(check(M))ans=M,R=M-1;
		else L=M+1;
	}
	printf("%lld\n",ans);
	return 0;
}

