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

const int N=500,Mod=998244353,INF=1e9+7;

int n,m,d[N][N],ans;

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=INF;
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),d[u][v]=min(d[u][v],w);
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(d[i][j]<INF)ans+=d[i][j];
	}
	printf("%lld\n",ans);
	return 0;
}

