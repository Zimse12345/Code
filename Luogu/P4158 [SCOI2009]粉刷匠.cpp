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

const int N=3e3+7,Mod=998244353,INF=1e9+7;
int n,m,t,f[N][N],g[N][N],c0[N],c1[N],ans;
char s[N];

int main(){
	n=read(),m=read(),t=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++){
			c0[j]=c0[j-1]+(s[j]=='0'?1:0);
			c1[j]=c1[j-1]+(s[j]=='1'?1:0);
		}
		for(int r=1;r<=m;r++){
			for(int j=0;j<=r;j++)g[r][j]=g[r][j-1];
			for(int l=1;l<=r;l++){
				for(int j=1;j<=r;j++)g[r][j]=max(g[r][j],g[l-1][j-1]+max(c0[r]-c0[l-1],c1[r]-c1[l-1]));
			}
		}
		for(int j=0;j<=m;j++){
			for(int k=j;k<=min(t,m*i);k++)f[i][k]=max(f[i][k],f[i-1][k-j]+g[m][j]);
		}
	}
	for(int i=0;i<=t;i++)ans=max(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}
