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
int T,n;

signed main(){
	T=read();
	while(T--){
		n=read();
		int ans=0;
		for(int i=1;i*i<=n;i++)++ans;
		for(int i=1;i*i*i<=n;i++)++ans;
		for(int i=1;i*i*i*i*i*i<=n;i++)--ans;
		printf("%lld\n",ans);
	}
	return 0;
}

