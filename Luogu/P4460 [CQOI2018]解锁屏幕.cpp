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

const int N=1e2+7,Mod=1e8+7,INF=1e9+7;
int n,x[N],y[N],f[2000000][30],mid[N][N],ans;

signed main(){
	n=read();
	for(int i=0;i<n;i++)x[i]=read(),y[i]=read();
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j){
		int m=0;
		for(int k=0;k<n;k++)if(i!=k&&j!=k){
			if(!((x[i]<=x[k]&&x[k]<=x[j])||(x[j]<=x[k]&&x[k]<=x[i])))continue;
			if(!((y[i]<=y[k]&&y[k]<=y[j])||(y[j]<=y[k]&&y[k]<=y[i])))continue;
			if((x[i]-x[k])*(y[k]-y[j])==(x[k]-x[j])*(y[i]-y[k]))m|=(1<<k);
		}
		mid[i][j]=m;
	}
	
	for(int i=0;i<n;i++)f[1<<i][i]=1;
	for(int t=1;t<(1<<n);t++){
		for(int u=0;u<n;u++)if(t&(1<<u)){
			for(int v=0;v<n;v++)if(!(t&(1<<v))){
				int m=mid[u][v];
				if((m&t)!=m)continue;
				f[t|(1<<v)][v]=(f[t|(1<<v)][v]+f[t][u])%Mod;
			}
		}
	}
	for(int t=1;t<(1<<n);t++){
		int tot=0;
		for(int i=0;i<n;i++)if(t&(1<<i))++tot;
		if(tot<4)continue;
		for(int u=0;u<n;u++)if(t&(1<<u))ans=(ans+f[t][u])%Mod;
	}
	printf("%d\n",ans);
	
	return 0;
}

