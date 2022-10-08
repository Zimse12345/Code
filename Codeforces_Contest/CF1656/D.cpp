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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n;

signed main(){
	T=read();
	while(T--){
		n=read();
		int x=1,ans=-1;
		if(n&1ll)ans=2;
		else{
			while(!(n&1ll))n/=2,x*=2;
			if(n!=1){
				if(x*2>n)ans=n;
				else ans=x*2;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

