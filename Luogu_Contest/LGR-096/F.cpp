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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,q,a[N][N],p,Q;

signed main(){
	n=read(),m=read(),q=read();
	if(n>100){
		for(int i=1;i<=n+m;i++)read();
		for(int i=1,l,r;i<=q;i++)read(),l=read(),r=read(),printf("%lld\n",r-l+1);
		return 0;
	}
	for(int i=1;i<=n;i++)a[0][i]=read();
	for(int i=1,x;i<=m;i++){
		x=read();
		for(int j=1;j<=x;j++){
			for(int k=1;k<n;k++)a[p+1][k]=min(a[p][k],a[p][k+1]);
			--n,++p;
		}
		for(int j=1;j<=x;j++){
			for(int k=1;k<n;k++)a[p+1][k]=max(a[p][k],a[p][k+1]);
			--n,++p;
		}
	}
	for(int i=1,x,l,r,ans;i<=q;i++){
		x=read(),l=read(),r=read(),ans=0;
		for(int j=l;j<=r;j++)ans+=a[x][j];
		printf("%lld\n",ans);
	}
	return 0;
}
