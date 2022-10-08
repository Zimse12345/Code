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

const int N=5e3+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],dp[N],cnt[N],mx,tag[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		tag[0]=1;
		for(int i=1;i<=n+1;i++){
			tag[i]=0;
			if(i!=n+1)a[i]=read();
			for(int j=0;j<=n;j++)cnt[j]=0;
			mx=0;
			dp[i]=0;
			for(int j=i-1;j>=0;j--){
				if(i==n+1||j==0||a[j]==a[i])if(tag[j]){
					int l=j+1,r=i-1,len=r-l+1;
					if(len<=0||(len%2==0&&mx<=len/2))dp[i]=max(dp[i],dp[j]+1),tag[i]=1;//printf("dp[%d](%d)+1*\n",j,dp[j]);
				}
				++cnt[a[j]];
				mx=max(mx,cnt[a[j]]);
			}
//			printf("dp[%d] = %d tag=%d\n",i,dp[i],tag[i]);
		}
		printf("%d\n",dp[n+1]-1);
	}
	return 0;
}

