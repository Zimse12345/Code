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
int T,n,a[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		int c=0,ans=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			while(a[i]%2==0)a[i]/=2,++c;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++)ans+=a[i];
		for(int i=1;i<=c;i++)a[n]*=2;
		ans+=a[n];
		printf("%lld\n",ans);
	}
	return 0;
}

