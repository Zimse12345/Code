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

const int N=4e3+7,Mod=998244353,INF=1e8+7;
int n,m,t,a[N],b[N],f[N][N],ans=INF,p;

signed main(){
	n=read(),m=read(),t=read();
	for(int i=1,x,y;i<=n;i++){
		x=read(),y=read();
		if(x>=t)continue;
		if(y>t)y=t;
		a[++p]=x,b[p]=y;
	}
	for(int i=0;i<=t*2;i++)for(int j=0;j<=t*2;j++)f[i][j]=INF;
	f[0][m]=0;
	for(int i=0;i<=t*2;i++){
		for(int j=i;j<=t*2;j++)f[i][j]=min(f[i][j-i]+1,f[i][j]);
		for(int j=0;j<=t;j++)if(f[i][j]<INF){
			for(int k=1;k<=p;k++)if(j>=a[k]){
				f[i+b[k]][j-a[k]]=min(f[i+b[k]][j-a[k]],f[i][j]);
			}
		}
		for(int j=i;j<=t*2;j++)f[i][j]=min(f[i][j-i]+1,f[i][j]);
	}
	for(int i=0;i<=t*2;i++)for(int j=t;j<=t*2;j++)ans=min(ans,f[i][j]);
	printf("%lld\n",ans);
	return 0;
}

