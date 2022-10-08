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

const int N=2e5+7,Mod=998244353,INF=1e18;
int T,n,k,a[N],s[N],ans;

signed main(){
	T=read();
	while(T--){
		n=read(),k=read(),ans=0;
		for(int i=1;i<=n;i++)a[i]=read(),s[i]=s[i-1]+a[i];
		if(k>=n){
			int t=k-n;
			ans+=t+a[1];
			for(int i=2;i<=n;i++)ans+=a[i]+t+i-1;
		}
		else{
			int mx=-INF;
			for(int i=k;i<=n;i++){
				int p=s[i]-s[i-k];
				if(p>mx)mx=p;
			}
			ans=mx+k*(k-1)/2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

