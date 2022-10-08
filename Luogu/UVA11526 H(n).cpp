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
int T,n,ans,p;

signed main(){
	T=read();
	while(T--){
		n=read(),ans=0,p=0;
		if(n==0){
			printf("0\n");
			continue;
		}
		for(int i=1;i*i<=n;i++)ans+=n/i,p=i;
		while(p<=n&&n/(p+1)==n/p)ans+=n/p,++p;
		p=n/(p+1);
		for(int i=p;i>=1;i--){
			int r=n/i,l=n/(i+1)+1;
			ans+=i*(r-l+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

