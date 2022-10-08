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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x>10)write(x/10);putchar(x%10+'0');return;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,fib[N],f[N];

signed main(){
	T=read();
	fib[1]=fib[2]=1;
	for(int i=3;i<N;i++){
		fib[i]=(fib[i-1]+fib[i-2]);
		if(fib[i]>=9)fib[i]-=9;
	}
	for(int i=1;i<N;i++){
		if(fib[i]==0)fib[i]=8;
		else fib[i]--;
	}
	while(T--){
		write(fib[read()+2]),putchar('\n');
	}
	return 0;
}

