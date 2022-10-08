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
int n,v[N],a[N],t,ans1,ans2;
vector<int> g[N];

signed main(){
	n=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),g[u].push_back(v),g[v].push_back(u);
	for(int i=1;i<=n;i++)v[i]=read();
	for(int i=1;i<=n;i++){
		t=0;
		int sum=0;
		for(int j=0;j<g[i].size();j++)a[++t]=v[g[i][j]],sum+=a[t];
		sum=sum*sum;
		for(int i=1;i<=t;i++)sum-=a[i]*a[i];
		sort(a+1,a+t+1);
		ans1=max(ans1,a[t]*a[t-1]);
		ans2=(ans2+sum)%10007;
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}
