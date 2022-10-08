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
int T,n,k,a[N];

signed main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;i++)a[i]=-read();
//		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;i++)a[i]=-a[i],ans+=a[i]-k;
		for(int i=1,s=0;i<=n;i++){
			int sum=s;
			int t=1;
			for(int j=i;j<=n&&j<=i+32;j++){
				t*=2;
				sum+=a[j]/t;
			}
			s+=a[i]-k;
			ans=max(ans,sum); //printf("(%lld %lld)\n",i,s);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

