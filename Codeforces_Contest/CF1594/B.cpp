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

const int N=1e3+7,Mod=1e9+7,INF=1e9+7;
int T,n,k,a[N],ans;

signed main(){
	T=read();
	while(T--){
		n=read(),k=read();
		a[0]=1,ans=0;
		for(int i=1;i<=31;i++)a[i]=(a[i-1]*n)%Mod;
		for(int i=0;i<=31;i++)if(k&(1ll<<i))ans=(ans+a[i])%Mod;
		printf("%lld\n",ans);
	}
	return 0;
}

