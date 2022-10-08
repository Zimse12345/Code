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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,q,a[N],ans1,ans2,ans3=-INF,ans4=INF;

signed main(){
	T=read(),n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1,p=1,x;i<=q;i++){
		x=read();
		while(p<n&&a[p]<=x)++p;
		int y=(x-a[p-1])*(a[p]-x)%Mod;
		ans1^=y;
		if(y&1ll)++ans2;
		ans3=max(ans3,y);
		ans4=min(ans4,y);
	}
	printf("%lld\n%lld\n%lld\n%lld\n",ans1,ans2,ans3,ans4);
	return 0;
}
