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
#include <unordered_map>

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,M=50000000,INF=1e9+7;
int n,a[N],ans;
signed t[100000000];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int d=-400;d<=400;d++){
		for(int i=1;i<=n;i++)ans=max(signed(ans),++t[a[i]+d*i+M]);
		for(int i=1;i<=n;i++)--t[a[i]+d*i+M];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=min(n,i+400);j++){
			if((a[j]-a[i])%(j-i)==0){
				int x=(a[j]-a[i])/(j-i);
				ans=max(signed(ans),(++t[x+M])+1);
			}
		}
		for(int j=i+1;j<=min(n,i+400);j++){
			if((a[j]-a[i])%(j-i)==0){
				int x=(a[j]-a[i])/(j-i);
				--t[x+M];
			}
		}
	}
	printf("%lld\n",n-ans);
	return 0;
}

