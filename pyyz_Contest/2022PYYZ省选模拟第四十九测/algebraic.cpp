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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	m=read();
	while(m--){
		int x=read();
		if(x==0){
			int ans=0;
			for(int i=1;i<=n;i++)ans+=a[i]*a[i];
			printf("%lld\n",ans);
		}
		else{
			int ans=0;
			int p=gcd(x,n);
			int l=1;
			for(int i=1;i<=p;i++){
				int lv=a[l],rv=a[l++],tag=1;
				for(int j=2;j<=n/p;j++){
					if(tag)ans+=rv*a[l],rv=a[l++];
					else ans+=lv*a[l],lv=a[l++];
					tag^=1;
				}
				ans+=lv*rv;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}

