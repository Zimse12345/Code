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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,c[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		int t=0,pos=0;
		for(int i=1;i<=n;i++){
			c[i]=read();
			if(c[i]==1)++t,pos=i;
		}
		if(t==1){
			int tag=1;
			t=pos;
			for(int j=t+1;j<=n;j++){
				if(c[j]-c[j-1]>1)tag=0;
			}
			c[0]=c[n];
			for(int j=1;j<=t;j++){
				if(c[j]-c[j-1]>1)tag=0;
			}
			if(tag)printf("YES\n");
			else printf("NO\n");
		}
		else printf("NO\n");
	}
	return 0;
}

