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
#define M (L+R)/2

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n;

int check(int x){
	int z=x/3;
	int res=(6+(12*z-6))*z/2;
	int k=z*4;
	x%=3;
	if(x>0)res+=k;
	--x,k+=2;
	if(x>0)res+=k;
	return res;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		int L=1,R=1e8,ans=R;
		while(L<=R){
			if(check(M)>=n)ans=M,R=M-1;
			else L=M+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

