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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n;

signed main(){
	T=read();
	while(T--){
		n=read();
		int Lx=0,Rx=0,Ly=0,Ry=0;
		for(int i=1;i<=n;i++){
			int x=read(),y=read();
			if(!x)Ly=min(Ly,y),Ry=max(Ry,y);
			else Lx=min(Lx,x),Rx=max(Rx,x);
		}
		printf("%d\n",(Rx-Lx+Ry-Ly)*2);
	}
	return 0;
}

