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

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(n<=2){
			printf("0\n");
			continue;
		}
		int ans=n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)if(i^j){
				int c=0;
				for(int k=1;k<=n;k++)if((k^i)&&(k^j)){
					if((a[i]-a[j])*(i-k)!=(a[i]-a[k])*(i-j))++c;
				}
				ans=min(ans,c);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

