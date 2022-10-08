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

const int N=1e6+7,Mod=998244353,INF=1e18;
int n,C,a[N],f[N],ans;

signed main(){
//	freopen("array4.in","r",stdin);
//	freopen("array.out","w",stdout);
	
	n=read(),C=read();
	for(int i=1;i<=n;i++){
		f[i]=-INF;
		a[i]=read();
		for(int j=i-1,mx=0;j>=0;j--){
			if(max(a[j],a[i])>=mx){
				if(j)f[i]=max(f[i],f[j]+(a[i]-a[j])*(a[i]-a[j])+C);
				else f[i]=max(f[i],0ll);
			}
			mx=max(mx,a[j]);
		}
	}
	for(int i=n,mx=0;i>=1;i--){
		if(a[i]>=mx)ans=max(ans,f[i]);
		mx=max(mx,a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}

