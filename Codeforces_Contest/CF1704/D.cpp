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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,m,pre[N],sum[N];
vector<int> a[N];

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++){
			sum[i]=0;
			a[i].resize(0);
			a[i].push_back(0);
			for(int j=1;j<=m;j++)a[i].push_back(read()),pre[j]=a[i][j];
			for(int j=1;j<=m;j++)pre[j]+=pre[j-1],sum[i]+=pre[j];
		}
		int s=sum[1],p=1;
		for(int i=2;i<=n;i++)if(sum[i]<s)s=sum[i],p=i;
		sort(sum+1,sum+n+1);
		printf("%lld %lld\n",p,sum[2]-sum[1]);
	}
	return 0;
}

