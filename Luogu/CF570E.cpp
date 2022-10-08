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

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=1e3+7,Mod=1e9+7,INF=1e9+7;
int n,m,k,f[N][N][2],v,ans;
char b[N][N],a[N][N];

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)scanf("%s",b[i]+1);
	if(m<n){
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[j][i]=b[i][j];
		int T=n;n=m,m=T;
	}
	else for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=b[i][j];
	
	if(a[1][1]!=a[n][m])return !printf("0\n");   //n<m
	f[1][n][v]=1;
	
	k=(m+n)>>1;
	for(int step=2;step<=k;++step){
		for(int x1=1;x1<=min(step,n);++x1)for(int x2=n;x2>=n-min(step,n)+1;--x2){
			int y1=step-x1+1,y2=m-(step-(n-x2+1)+1)+1;
			
			if(y2>=y1){
				if(a[x1][y1]==a[x2][y2])f[x1][x2][v^1]=(
				f[x1][x2][v]+f[x1-1][x2][v]+f[x1][x2+1][v]+f[x1-1][x2+1][v])%Mod;//printf("*");
				else f[x1][x2][v^1]=0;
			}
			else f[x1][x2][v^1]=0;
			
//			printf("[%d (%d,%d) (%d,%d) <%d> ]\n",step,x1,y1,x2,y2,f[x1][x2][v^1]);
		}
		v^=1;
	}
	
	int p=(n+m)&1;
	for(int i=1;i<=n;i++)ans=(ans+f[i][i][v]+f[i][i+1][v]*p)%Mod;
	printf("%lld\n",ans);
	return 0;
}
