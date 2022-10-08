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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],dp1[N],dp2[N],ans,dp[N][2];

void calc(){
	int pos=0;
	for(int i=1;i<=n;i++)if(a[i]>a[pos])pos=i;
	dp1[1]=0;
	for(int i=2;i<=n;i++){
		dp1[i]=INF;
		if(a[i]>a[i-1])dp1[i]=min(dp1[i],dp1[i-1]);
		if(a[i]>dp1[i-1])dp1[i]=min(dp1[i],a[i-1]);
	}
	dp2[n]=0;
	for(int i=n-1;i>=1;i--){
		dp2[i]=INF;
		if(a[i]>a[i+1])dp2[i]=min(dp2[i],dp2[i+1]);
		if(a[i]>dp2[i+1])dp2[i]=min(dp2[i],a[i+1]);
	}
	dp[pos][0]=dp1[pos],dp[pos][1]=a[pos];
	for(int i=pos+1;i<=n;i++){
		dp[i][0]=INF,dp[i][1]=-INF;
		if(a[i]<a[i-1])dp[i][0]=min(dp[i][0],dp[i-1][0]);
		if(a[i]>a[i-1])dp[i][1]=max(dp[i][1],dp[i-1][1]);
		if(a[i]>dp[i-1][0])dp[i][1]=max(dp[i][1],a[i-1]);
		if(a[i]<dp[i-1][1])dp[i][0]=min(dp[i][0],a[i-1]);
		if(dp[i][1]>=dp2[i])++ans;
	}
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	calc();
	reverse(a+1,a+n+1);
	calc();
	printf("%d\n",ans); 
	return 0;
}

