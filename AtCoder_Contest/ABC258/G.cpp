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
#include <bitset>

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4096,Mod=998244353,INF=1e9+7;
int n;
char s[N];
ll ans;
bitset<N> a[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++)a[i][j]=s[j]-'0';
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++)if(a[i][j]){
			ans+=(a[i]&a[j]).count();
		}
	}
	printf("%lld\n",ans/3);
	return 0;
}

