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

const int N=3e2+7,Mod=998244353,INF=1e9+7;
int n,m,g[N][N][N],f[N][N],vis[N][N],ans;

int dp(int l,int r){
	if(vis[l][r]++)return f[l][r];
	for(int k=l;k<=r;k++)f[l][r]=max(f[l][r],dp(l,k-1)+dp(k+1,r)+g[l][r][k]);
	return f[l][r];
}

signed main(){
	n=read(),m=read();
	for(int i=1,w,l,r;i<=m;i++){
		w=read(),l=read(),r=read(),f[l][r]=max(f[l][r],w);
		for(int j=l;j<=r;j++)g[l][r][j]=max(g[l][r][j],w);
	}
	for(int k=1;k<=n;k++){
		for(int l=k;l>=1;l--)for(int r=k;r<=n;r++){
			g[l][r][k]=max(g[l][r][k],max(g[l+1][r][k],g[l][r-1][k]));
		}
	}
	dp(1,n);
	for(int l=1;l<=n;l++)for(int r=l;r<=n;r++)ans=max(ans,f[l][r]);
	printf("%d\n",ans);
	return 0;
}
