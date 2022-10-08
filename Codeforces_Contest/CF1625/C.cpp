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

const int N=1e3+7,Mod=1e9+7,INF=1e9+7;
int n,d[N],a[N],k;
int f[N][N];

signed main(){
	n=read(),d[n+1]=read(),k=read();
	for(int i=1;i<=n;i++)d[i]=read();
	for(int i=1;i<=n;i++)a[i]=read();
	f[1][0]=0;
	for(int i=2;i<=n+1;i++){
		for(int x=0;x<=k;x++)f[i][x]=INF;
		for(int j=1;j<i;j++){
			int p=i-j-1;
			for(int x=p;x<=k;x++)f[i][x]=min(f[i][x],f[j][x-p]+a[j]*(d[i]-d[j]));
		}
	}
	int ans=INF;
	for(int i=0;i<=k;i++)ans=min(ans,f[n+1][i]);
	printf("%d\n",ans);
	return 0;
}

