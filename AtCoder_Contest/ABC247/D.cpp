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
int n,val[N],cnt[N],s=1,t;

signed main(){
	n=read();
	for(int i=1,op,x,y;i<=n;i++){
		op=read();
		if(op==1){
			x=read(),y=read();
			val[++t]=x,cnt[t]=y;
		}
		else{
			x=read(),y=0;
			while(x>cnt[s])y+=val[s]*cnt[s],x-=cnt[s++];
			cnt[s]-=x,y+=val[s]*x;
			printf("%lld\n",y);
		}
	}
	return 0;
}

