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
int n,x,a[N],b[N],ans=2000000000000000000; 

signed main(){
	n=read(),x=read();
	int s=0,mn=2000000000000000000;
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read();
		--x,s+=a[i]+b[i],mn=min(mn,b[i]);
		ans=min(ans,s+mn*x);
		if(!x)break;
	}
	printf("%lld\n",ans);
	return 0;
}

