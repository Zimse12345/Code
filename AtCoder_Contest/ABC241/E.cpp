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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,k,a[N],v[N];

signed main(){
	n=read(),k=read();
	for(int i=0;i<n;i++)a[i]=read();
	int t=0,tt=0,c=0;
	for(int i=1;i<=k;i++){
		t+=a[t%n];
		tt+=a[tt%n],tt+=a[tt%n];
		v[++c]=t;
		if(t%n==tt%n)break;
	}
	if(c<k){
		int ans=t;
		k-=c;
		ans+=k/c*(tt-t);
		k%=c;
		while(k--)ans+=a[ans%n];
		printf("%lld\n",ans);
	}
	else printf("%lld\n",t);
	return 0;
}

