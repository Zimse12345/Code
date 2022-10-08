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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,k,ans,p;

signed main(){
	n=read(),k=read();
	ans=n*k;
	for(int l=1,r;l<=n;l=r+1){
		if(k/l!=0)r=min(k/(k/l),n);
		else r=n;
		ans-=(k/l)*(r-l+1)*(l+r)/2;
	}
	printf("%lld\n",ans);
	return 0;
}

