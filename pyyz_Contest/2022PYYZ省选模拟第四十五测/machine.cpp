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

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,q,s[N],_s[N];

signed main(){
//	freopen("ex_machine2.in","r",stdin);
//	freopen("my.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)s[i]=i;
	if(n>5000){
		int ans=0;
		for(int i=1;i<=n;i++){
			int d=ans/s[i];
			if(ans%s[i])++d;
			++d;
			ans=d*s[i];
		}
		while(q--)printf("%lld\n",ans);
		return 0;
	}
	while(q--){
		int op=read(),x=read(),y=read();
		if(op==1){
			for(int i=x;i<=y;i++)_s[i]=s[x+y-i];
			for(int i=x;i<=y;i++)s[i]=_s[i];
		}
		else{
			for(int i=x;i<=n;i++){
				int d=y/s[i];
				if(y%s[i])++d;
				++d;
				y=d*s[i];
			}
			printf("%lld\n",y);
		}
	}
	return 0;
}

