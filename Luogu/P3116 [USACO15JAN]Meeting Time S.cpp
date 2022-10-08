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

const int N=120,Mod=998244353,INF=1e9+7;
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
int n,m,a[N][N*N],b[N][N*N];
vector<edge> g1[N],g2[N];

int main(){
	n=read(),m=read();
	for(int i=1,u,v,w1,w2;i<=m;i++){
		u=read(),v=read(),w1=read(),w2=read();
		if(u>v)swap(u,v);
		g1[u].push_back(edge(v,w1)),g2[u].push_back(edge(v,w2));
	}
	a[1][0]=b[1][0]=1;
	for(int u=1;u<=n;u++){
		 for(int k=0;k<=n*100;k++){
		 	if(a[u][k]==1){
		 		for(unsigned i=0;i<g1[u].size();i++)a[g1[u][i].to][g1[u][i].w+k]=1;
			}
			if(b[u][k]){
				for(unsigned i=0;i<g2[u].size();i++)b[g2[u][i].to][g2[u][i].w+k]=1;
			}
		 }
	}
	for(int k=0;k<=n*100;k++)if(a[n][k]&&b[n][k]){
		printf("%d\n",k);
		return 0;
	}
	printf("IMPOSSIBLE\n");
	return 0;
}
