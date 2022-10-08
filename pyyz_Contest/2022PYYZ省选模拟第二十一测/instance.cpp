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

const int N=2e2+7,Mod=998244353,INF=1e9+7;
int n,m,d[N][N],ans;
int k,pos[N],lt[N],rt[N],t[N],c[N],f[300000][20];

signed main(){
	n=read(),m=read();
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i^j)d[i][j]=INF;
	for(int i=0,x,y,z;i<m;i++){
		x=read()-1,y=read()-1,z=min(read(),d[x][y]);
		d[x][y]=d[y][x]=z;
	}
	for(int mid=0;mid<n;mid++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)d[i][j]=min(d[i][j],d[i][mid]+d[mid][j]);
	k=read();
	for(int i=0;i<k;i++)pos[i]=read()-1,lt[i]=read(),rt[i]=read(),t[i]=read(),c[i]=read();
	for(int i=0;i<(1<<k);i++)for(int j=0;j<k;j++)f[i][j]=INF;
	for(int i=0;i<k;i++){
		int b=max(lt[i],d[0][pos[i]]);
		if(b>rt[i])continue;
		f[1<<i][i]=b+t[i];
	}
	for(int i=0;i<(1<<k);i++){
		for(int u=0;u<k;u++)if(f[i][u]<INF){
			for(int v=0;v<k;v++)if(!(i&(1<<v))){
				int b=max(lt[v],f[i][u]+d[pos[u]][pos[v]]);
				if(b>rt[v])continue;
				f[i|(1<<v)][v]=min(f[i|(1<<v)][v],b+t[v]);
			}
		}
	}
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<k;j++)if(f[i][j]<INF){
			int s=0;
			for(int w=0;w<k;w++)if(i&(1<<w))s+=c[w];
			ans=max(ans,s);
		}
	}
	printf("%d\n",ans);
	return 0;
}

