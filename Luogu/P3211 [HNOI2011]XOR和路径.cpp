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

const int N=1e2+7,INF=1e9;
const double EPS=1e-9;
int n,m,deg[N];
struct edge{
	int to,val;
	edge(int to=0,int val=0):to(to),val(val){}
};
vector<edge> g[N];
double ans,f[N][N];

double sol(int x){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)f[i][j]=0;
		if(i^n)for(unsigned j=0;j<g[i].size();j++){
			double p=1.0/deg[i];
			if(g[i][j].val&x)f[i][g[i][j].to]-=p,f[i][0]-=p;
			else f[i][g[i][j].to]+=p;
		}
		f[i][i]-=1.0;
	}
	for(int i=1,t;i<=n;i++){
		t=0;
		for(int j=i;j<=n;j++)if(abs(f[j][i])>EPS){t=j;break;}
		if(!t)return 0;
		for(int j=0;j<=n;j++)swap(f[i][j],f[t][j]);
		for(int j=1;j<=n;j++)if(i^j){
			double p=f[j][i]/f[i][i];
			for(int k=0;k<=n;k++)f[j][k]-=p*f[i][k];
		}
		for(int j=0;j<=n;j++)if(i^j)f[i][j]/=f[i][i];
		f[i][i]=1;
	}
	return f[1][0];
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		++deg[u],g[u].push_back(edge(v,w));
		if(u^v)++deg[v],g[v].push_back(edge(u,w));
	}
	for(int i=30;i>=0;i--){
		double p=sol(1<<i);
		ans+=p*(1<<i);
	}
	printf("%.3lf\n",ans);
	return 0;
}

