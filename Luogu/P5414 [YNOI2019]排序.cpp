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
int T,n,a[N],f[N],s,t;

signed main(){
	T=read(),a[0]=-INF;
	while(T--){
		n=read(),s=0,t=0;
		for(int i=1;i<=n;i++){
			a[i]=f[i]=read(),s+=a[i];
			for(int j=0;j<i;j++)if(a[j]<=a[i])f[i]=max(f[i],f[j]+a[i]);
			t=max(t,f[i]);
		}
		printf("%lld\n",s-t);
	}
	return 0;
}

