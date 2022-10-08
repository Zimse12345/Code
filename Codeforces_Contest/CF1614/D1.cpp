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

const int N=5e6+7,INF=1e9,Mod=1e9+7;
int n,m,a[N],t[N],cnt[N],dp[N],ans;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),++t[a[i]],m=max(m,a[i]);
	for(int i=1;i<=m;i++)for(int j=i;j<=m;j+=i)cnt[i]+=t[j];
//	for(int i=1;i<=m;i++)printf("cnt[%lld]=%lld\n",i,cnt[i]);
	for(int i=m;i>=1;i--){
		dp[i]=cnt[i]*i;
		for(int j=i;j<=m;j+=i)dp[i]=max(dp[i],dp[j]+(cnt[i]-cnt[j])*i);
	}
	for(int i=1;i<=m;i++)ans=max(ans,dp[i]);//printf("dp[%lld]=%lld\n",i,dp[i]);
	printf("%lld\n",ans);
	return 0;
}
