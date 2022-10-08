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
int T,n,a[3][N],t[3][N],mx[N];

int solve(){
	int k=0;
	for(int i=2;i<=n;i++)t[1][i]=max(0,a[1][i]-k),++k;
	for(int i=n;i>=1;i--)t[2][i]=max(0,a[2][i]-k),++k;
	mx[n+1]=0;
	for(int i=n;i>=1;i--)mx[i]=max(mx[i+1],max(t[1][i],t[2][i]));
	int p=0,ans=INF;
	k=0;
	for(int i=1;i<=n;i+=2){
		ans=min(ans,max(p,mx[i]-k+(i-1)));
//		printf("(%d + %d)\n",-k,(i-1));
		p=max(p,a[2][i]-k),++k;
		p=max(p,a[2][i+1]-k),++k;
		p=max(p,a[1][i+1]-k),++k;
		p=max(p,a[1][i+2]-k),++k;
	}
	return ans+n*2-1;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=2;i++)for(int j=1;j<=n;j++)a[i][j]=read();
		int ans=solve();
		int k=max(a[2][1],a[2][2]-1)+2;
		for(int i=1;i<=2;i++)for(int j=1;j<=n;j++)a[i][j]=max(0,a[i][j]-k);
		for(int i=1;i<=n;i++)a[1][i]=a[1][i+1],a[2][i]=a[2][i+1],swap(a[1][i],a[2][i]);
		--n;
		ans=min(ans,k+solve());
		printf("%d\n",ans);
	}
	return 0;
}

