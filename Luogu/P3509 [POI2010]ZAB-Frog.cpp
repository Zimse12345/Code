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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,k,m,a[N],nxt[N][22];

signed main(){
	n=read(),k=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,L=1,R=k+1;i<=n;i++){
		if(a[i]-a[L]<a[R]-a[i])nxt[i][0]=R;
		else nxt[i][0]=L;
		while(R<n&&a[R+1]-a[i+1]<a[i+1]-a[L])++L,++R;
	}
	for(int i=1;i<=20;i++)for(int j=1;j<=n;j++)nxt[j][i]=nxt[nxt[j][i-1]][i-1];
	for(int i=1,x;i<=n;i++){
		x=i;
		for(int j=0;j<=20;j++)if(m&(1<<j))x=nxt[x][j];
		printf("%lld ",x);
	}
	printf("\n");
	return 0;
}

