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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,a[N],x,y,ans;

signed main(){
	n=read(),x=read(),y=read();
	if(x==y){
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i]==x)a[i]=1;
			else a[i]=0;
		}
		int p0=0,p1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)p0=i;
			else p1=i;
			if(p0<p1)ans+=i-p0;
		}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==x)a[i]=1;
		else if(a[i]==y)a[i]=2;
		else if(a[i]>x||a[i]<y)a[i]=0;
		else a[i]=-1;
	}
	int p0=0,p1=0,p2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0)p0=i;
		if(a[i]==1)p1=i;
		if(a[i]==2)p2=i;
		ans+=max(0ll,min(p1,p2)-p0);
	}
	printf("%lld\n",ans);
	return 0;
}

