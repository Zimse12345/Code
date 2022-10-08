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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x>=10)write(x/10);putchar(x%10+'0');return;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n;

signed main(){
	T=read();
	while(T--){
		n=read();
		if(n<3)putchar('0'),putchar('\n');
		else{
			int ans=n*(n-1)/2%Mod*(n-2)%Mod;
			if(n>=4)ans=(ans+n*(n-1)/2%Mod*(n-2)%Mod*(n-3)%Mod)%Mod;
			write(ans),putchar('\n');
		}
	}
	return 0;
}

