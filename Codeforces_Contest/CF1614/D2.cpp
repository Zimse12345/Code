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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e7+7,M=2e5+7,INF=1e9,Mod=1e9+7;
int n,m,a[M],t[N],cnt[N],dp[N],ans;
int tot,prime[N],pr[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),++cnt[a[i]],m=max(m,a[i]);
	for(int i=2;i<=m;i++){
		if(!pr[i])prime[++tot]=i,pr[i]=i;
		for(int j=1;j<=tot&&prime[j]*i<=m;j++){
			pr[prime[j]*i]=prime[j];
			if(pr[i]==prime[j])break;
		}
	}
	for(int i=tot;i>=1;i--)for(int j=1.0*m/prime[i]+1e-9;j>=1;j--)cnt[j]+=cnt[j*prime[i]];
	for(int i=m;i>=1;i--){
		dp[i]=cnt[i]*i;
		for(int j=1;j<=tot&&prime[j]*i<=m;j++)dp[i]=max(dp[i],dp[prime[j]*i]+(cnt[i]-cnt[prime[j]*i])*i);
	}
	for(int i=1;i<=m;i++)ans=max(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}
