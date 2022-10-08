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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,fac[N],ans;

int C(int x,int y){
	return fac[x]/fac[y]/fac[x-y];
}

signed main(){
	n=read();
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i;
	ans=fac[n];
	for(int i=1;i<=n;i++){
		int res=C(n,i)*fac[n-i];
		
		if(i%2==1)ans-=res;
		else ans+=res;
	}
	printf("%lld\n",ans);
	return 0;
}
