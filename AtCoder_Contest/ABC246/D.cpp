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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,ans=1e18;

signed main(){
	n=read();
	for(int i=0;i<=1000000;i++){
		int L=0,R=1000000,p=1000000;
		while(L<=R){
			int M=(L+R)>>1ll;
			if(i*i*i+i*i*M+i*M*M+M*M*M>=n)p=M,R=M-1;
			else L=M+1;
		}
		ans=min(ans,i*i*i+i*i*p+i*p*p+p*p*p);
	}
	printf("%lld\n",ans);
	return 0;
}

