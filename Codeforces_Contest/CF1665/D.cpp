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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int _2[N];
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}

int q(int x,int y){
	printf("? %lld %lld\n",x,y);
	fflush(stdout);
	return read();
}

signed main(){
	int T=read();
	while(T--){
		int b=0,x=0;
		_2[0]=1;
		for(int i=1;i<=32;i++)_2[i]=_2[i-1]*2;
		for(int i=0;i<30;i++){
			int v=q(b+_2[i],b+_2[i]+_2[i+1]);
			if(v==_2[i+1]){
				x|=(1ll<<i);
				b-=_2[i];
			}
		}
		printf("! %lld\n",x);
		fflush(stdout);
	}
	return 0;
}
