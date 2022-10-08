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
int n,t,a[N],b[N],d[N],_d[N],pC[N][2],pc[N][2],f[100][100];
char s[N];

signed main(){
	n=read(),t=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
		if(a[i])d[i]=d[i-1]+1;
		else d[i]=d[i-1]-1;
		pC[i][0]=pC[i-1][0];
		pC[i][1]=pC[i-1][1];
		++pC[i][a[i]];
	}
	int w=n+t*2,ans=0;
	for(int i=0;i<(1<<w);i++){
		for(int j=0;j<w;j++){
			if(i&(1<<j))b[j+1]=1,_d[j+1]=_d[j]+1;
			else b[j+1]=0,_d[j+1]=_d[j]-1;
			pc[j+1][0]=pc[j][0],pc[j+1][1]=pc[j][1];
			++pc[j+1][b[j+1]];
		}
		if(pC[n][0]-pC[n][1]!=pc[w][0]-pc[w][1])continue;
		for(int x=0;x<=n;x++){
			for(int y=0;y<=w;y++)f[x][y]=0;
		}
		f[0][0]=1;
		for(int x=0;x<=n;x++){
			for(int y=0;y<=w;y++)if(f[x][y]){
				int u0=pc[y][0]-pC[x][0];
				int u1=pc[y][1]-pC[x][1];
				if(y<w&&b[y+1]==1&&u1+1<=u0)f[x][y+1]=1;
				if(y<w&&b[y+1]==0&&u0+1<=t)f[x][y+1]=1;
				if(x<n&&y<w&&a[x+1]==b[y+1])f[x+1][y+1]=1;
			}
		}
		ans+=f[n][w];
	}
	printf("%d\n",ans);
	return 0;
}

