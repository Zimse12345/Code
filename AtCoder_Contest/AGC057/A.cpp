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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,l,r;

signed main(){
	T=read();
	while(T--){
		l=read(),r=read();
		int w=1;
		while(w*10<=r)w*=10;
		if(r/w>1){
			printf("%d\n",r-max(w,l)+1);
			continue;
		}
		else{
			int ans=r-w+1;
			int b=r/10+1;
			l=max(l,r-w+1),r=w-1;
			w/=10;
			l=max(l,w);
			l=max(l,b);
			ans+=r-l+1;
			printf("%d\n",ans);
		}
	}
	return 0;
}

