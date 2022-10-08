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
int T,n,a[N],b[N],ta[N],tb[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)ta[i]=tb[i]=0;
		for(int i=1;i<=n;i++)a[i]=read(),b[i]=read(),++ta[a[i]],++tb[b[i]];
		int ans=n*(n-1)*(n-2)/6ll;
		for(int i=1;i<=n;i++)ans-=(ta[a[i]]-1)*(tb[b[i]]-1);
//		int ans=n*(n-1)*(n-2)/6ll;printf("%lld\n",ans);
//		for(int i=1;i<=n;i++)if(ta[i]>1){
//			ans/=(ta[i]*(ta[i]-1)/2ll*(n-ta[i]));
//			if(ta[i]==2)continue;
//			ans/=(ta[i]*(ta[i]-1)*(ta[i]-2)/6ll);
//		}printf("%lld\n",ans);
//		for(int i=1;i<=n;i++)if(tb[i]>1){
//			ans/=(tb[i]*(tb[i]-1)/2ll*(n-tb[i]));
//			if(tb[i]==2)continue;
//			ans/=(tb[i]*(tb[i]-1)*(tb[i]-2)/6ll);
//		}
		printf("%lld\n",ans);
	}
	return 0;
}

