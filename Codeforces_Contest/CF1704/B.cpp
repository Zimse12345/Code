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
int T,n,x,a[N];

signed main(){
	T=read();
	while(T--){
		n=read(),x=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int L=a[1],R=a[1],ans=0;
		for(int i=2;i<=n;i++){
			int _L=min(L,a[i]),_R=max(R,a[i]);
			if(_R-_L>2*x)L=R=a[i],++ans;
			else L=_L,R=_R;
		}
		printf("%lld\n",ans);
	} 
	return 0;
}

