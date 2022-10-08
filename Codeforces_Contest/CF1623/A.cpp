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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,m,sx,sy,tx,ty; 

signed main(){
	T=read();
	while(T--){
		n=read(),m=read(),sx=read(),sy=read(),tx=read(),ty=read();
		int ans1,ans2;
		if(tx>=sx)ans1=tx-sx;
		else ans1=n-sx+n-tx;
		if(ty>=sy)ans2=ty-sy;
		else ans2=m-sy+m-ty;
		printf("%d\n",min(ans1,ans2));
	}
	return 0;
}

