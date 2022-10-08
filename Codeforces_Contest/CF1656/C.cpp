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
inline void cf(int x){if(x)printf("YES\n");else printf("NO\n");}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		int t=0,tt=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i]==1)++t;
			if(a[i]==0)++tt;
		}
		if(t==0||t==n)printf("YES\n");
		else{
			if(tt)printf("NO\n");
			else{
				sort(a+1,a+n+1);
				int p=1;
				for(int i=2;i<=n;i++)if(a[i]==a[i-1]+1)p=0;
				cf(p);
			}
		}
	}
	return 0;
}

