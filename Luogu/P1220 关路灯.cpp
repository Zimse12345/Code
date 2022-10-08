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

const int N=1e2+7,Mod=998244353,INF=1e15+7;
int n,st,x[N],c[N],s[N],f[N][N][2],vis[N][N][2];

int dp(int l,int r,int p){
	if(l==r)return 0;
	if(r<st||l>st)return INF; 
	if(vis[l][r][p]++)return f[l][r][p];
	if(p==0)f[l][r][p]=min(dp(l+1,r,0)+(x[l+1]-x[l])*(s[n]-s[r]+s[l]),
						dp(l+1,r,1)+(x[r]-x[l])*((s[n]-s[r]+s[l])));
	else f[l][r][p]=min(dp(l,r-1,1)+(x[r]-x[r-1])*(s[n]-s[r-1]+s[l-1]),
						dp(l,r-1,0)+(x[r]-x[l])*(s[n]-s[r-1]+s[l-1]));
	return f[l][r][p];
}

signed main(){
	n=read(),st=read();
	for(int i=1;i<=n;i++)x[i]=read(),c[i]=read(),s[i]=c[i]+s[i-1];
	for(int i=1;i<st;i++)f[i][st][1]=INF,vis[i][st][1]=1;
	for(int i=st+1;i<=n;i++)f[st][i][0]=INF,vis[st][i][0]=1;
	printf("%lld\n",min(dp(1,n,0),dp(1,n,1)));
	return 0;
}
