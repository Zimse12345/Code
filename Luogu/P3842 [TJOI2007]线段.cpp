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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e4+7,Mod=998244353,INF=1e9+7;
int n,f[N][2];
inline int sol(int s,int l,int r,int t){
	return min(abs(s-l)+abs(l-r)+abs(r-t),abs(s-r)+abs(r-l)+abs(l-t));
}

signed main(){
	n=read();
	int pl=1,pr=1;
	for(int i=1,l,r;i<=n;i++){
		l=read(),r=read();
		f[i][0]=min(f[i-1][0]+1+sol(pl,l,r,l),f[i-1][1]+1+sol(pr,l,r,l));
		f[i][1]=min(f[i-1][0]+1+sol(pl,l,r,r),f[i-1][1]+1+sol(pr,l,r,r));
		pl=l,pr=r;
	}
	printf("%d\n",min(f[n][0]+abs(pl-n),f[n][1]+abs(pr-n))-1);
	return 0;
}
