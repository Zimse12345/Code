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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e3+7,Mod=998244353,INF=1e9+7;
int n,f[N][N],ans;
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){};
	bool operator < (const node& A)const{return y>A.y;}
}p[N];

signed main(){
	n=read();
	for(int i=1,x,y;i<=n;i++)x=read(),y=read(),p[i]=node(x,y);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=max(f[i-1][j],f[i-1][j-1]+p[i].x-p[i].y*(j-1));
	}
	for(int i=1;i<=n;i++)ans=max(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}
