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

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,q,t[N];

void sol(){
	int ans=0;
	for(int i=1;i<=n;i++){
		int k=t[i]/i;
		if(t[i]%i)++k;
		ans=max(ans,k);
	}
	printf("%d\n",ans);
	return;
}

signed main(){
//	freopen("computer_sample.in","r",stdin);
//	freopen("B.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;i++)t[read()]++;
	for(int i=2;i<=n;i++)t[i]+=t[i-1];
	sol();
	while(q--){
		int x=read(),y=read();
		for(int i=y;i<=n;i++)t[i]+=x;
		sol();
	}
	return 0;
}

