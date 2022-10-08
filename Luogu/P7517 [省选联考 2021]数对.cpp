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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,a[N],ans;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[read()]++;
	for(int i=1;i<N;i++)if(a[i]){
		ans+=a[i]*(a[i]-1);
		for(int j=2;i*j<N;j++)ans+=a[i]*a[i*j];
	}
	printf("%lld\n",ans);
	return 0;
}

