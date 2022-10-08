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
int T,n,a[N],s[N],p[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		int ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		if(n&1ll){
			for(int i=2;i<n;i+=2)if(a[i]<=max(a[i-1],a[i+1]))ans+=max(a[i-1],a[i+1])-a[i]+1;
		}
		else{
			for(int i=2;i<n;i+=2){
				int t=0;
				if(a[i]<=max(a[i-1],a[i+1]))t=max(a[i-1],a[i+1])-a[i]+1;
				s[i]=s[i-2]+t;
			}
			ans=s[n-2];
			p[n]=p[n+1]=0;
			for(int i=n-1;i>1;i-=2){
				int t=0;
				if(a[i]<=max(a[i-1],a[i+1]))t=max(a[i-1],a[i+1])-a[i]+1;
				p[i]=p[i+2]+t;
				ans=min(ans,p[i]+s[i-3]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

