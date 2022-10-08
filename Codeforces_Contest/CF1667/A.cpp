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

const int N=1e6+7,Mod=998244353,INF=1e16+7;
int n,a[N],ans=INF;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i-1,t=0;j>=1;j--){
			int b=a[j+1]*t;
			t=b/a[j]+1;
			sum+=t;
		}
		for(int j=i+1,t=0;j<=n;j++){
			int b=a[j-1]*t;
			t=b/a[j]+1;
			sum+=t;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}

