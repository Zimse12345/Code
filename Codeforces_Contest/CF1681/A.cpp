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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,ma,mb; 

signed main(){
	T=read();
	while(T--){
		ma=mb=-INF;
		n=read();while(n--)ma=max(ma,read());
		n=read();while(n--)mb=max(mb,read());
		if(ma>mb)printf("Alice\nAlice\n");
		else if(mb>ma)printf("Bob\nBob\n");
		else printf("Alice\nBob\n"); 
	}
	return 0;
}

