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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,hd[N],nxt[N],to[N],ec,m,vis[N];
double x[N],s[N][5],c[N],dis[N];
inline double f(double a,double b){return sqrt(a*a+b*b);}
inline void add(int u,int v,double w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,c[ec]=w;return;}
struct node{
	int x;double y;
	node(int x=0,double y=0):x(x),y(y){}
	bool operator < (const node& A)const{return y>A.y;}
};
priority_queue<node> Q;

bool check(int l,int r,double L,double R){
	for(int i=l+1;i<r;i++){
		double m=L+(x[i]-x[l])/(x[r]-x[l])*(R-L);
		if(!((s[i][1]-1e-9<=m&&m-1e-9<=s[i][2])||(s[i][3]-1e-9<=m&&m-1e-9<=s[i][4])))return false;
	}
	return true;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%lf",&x[i]);
		for(int j=1;j<=4;j++)scanf("%lf",&s[i][j]);
	}
	x[0]=0,x[n+1]=10;
	for(int l=1;l<n;l++)for(int r=l+1;r<=n;r++){
		for(int a=1;a<=4;a++)for(int b=1;b<=4;b++){
			if(check(l,r,s[l][a],s[r][b]))add((l-1)*4+a,(r-1)*4+b,f(x[r]-x[l],s[r][b]-s[l][a]));
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=4;j++){
		if(check(0,i,5,s[i][j]))add(4*n+1,(i-1)*4+j,f(x[i],5-s[i][j]));
		if(check(i,n+1,s[i][j],5))add((i-1)*4+j,4*n+2,f(10-x[i],5-s[i][j]));
	}
	if(check(0,n+1,5,5)){
		printf("10.00\n");
		return 0;
	}
	m=n*4+2;
	for(int i=1;i<=m;i++)dis[i]=INF;
	dis[n*4+1]=0,Q.push(node(n*4+1,0));
	while(!Q.empty()){
		int u=Q.top().x;
		Q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(dis[u]+c[i]<dis[v]){
				dis[v]=dis[u]+c[i];
				Q.push(node(v,dis[v]));
			}
		}
	}
	printf("%.2lf\n",dis[n*4+2]);
	return 0;
}

