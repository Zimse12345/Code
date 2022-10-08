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

const int N=2e5+7,Mod=998244353,INF=1e12;
int T,n,a[N],b[N],ans;

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		int min1=INF,min2=INF,min3=INF,min4=INF;
		for(int i=1;i<=n;i++){
			min1=min(min1,abs(a[1]-b[i])),min2=min(min2,abs(a[n]-b[i]));
			min3=min(min3,abs(b[1]-a[i])),min4=min(min4,abs(b[n]-a[i]));
		}
		ans=min1+min2+min3+min4;
		ans=min(ans,min(abs(a[1]-b[1])+min2+min4,abs(a[n]-b[n])+min1+min3));
		ans=min(ans,min(abs(a[1]-b[n])+min2+min3,abs(a[n]-b[1])+min1+min4));
		ans=min(ans,min(abs(a[1]-b[1])+abs(a[n]-b[n]),abs(a[1]-b[n])+abs(a[n]-b[1])));
		printf("%lld\n",ans);
	}
	return 0;
}

