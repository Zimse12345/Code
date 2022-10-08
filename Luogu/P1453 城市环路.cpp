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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e12+7;
int n,a[N],ir[N],inq[N],qu[N],qt,r,hl[N],hr[N],f[N][2],k[N][2],ans;
double h;
vector<int> g[N];

void dfs1(int u,int pr){
	inq[u]=1,qu[++qt]=u;
	
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==pr)continue;
		if(inq[v]){
			int p=qt,z=v;
			ir[v]=1,r=v;
			while(qu[p]!=v){
				ir[qu[p]]=1;
				hr[z]=qu[p],hl[qu[p]]=z;
				z=qu[p],--p;
			}
			hr[z]=v,hl[v]=z;
		}
		else dfs1(v,u);
	}
	
	inq[u]=0,--qt;
	return;
}

void dfs2(int u,int pr){
	int f0=0,f1=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==pr||v==hl[u]||v==hr[u])continue;
		dfs2(v,u);
		f0+=max(f[v][0],f[v][1]),f1+=f[v][0];
	}
	f[u][0]=f0,f[u][1]=f1+a[u];
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,u,v;i<=n;i++){
		u=read()+1,v=read()+1;
		g[u].push_back(v),g[v].push_back(u);
	}
	cin>>h;
	dfs1(1,0),qt=0;
	int p=r;
	while(1){
		dfs2(p,0);
		qu[++qt]=p,p=hr[p];
		if(p==r)break;
	}
	
	k[1][1]=f[qu[1]][1],k[1][0]=-INF;
	for(int i=2;i<=qt;i++){
		int p=qu[i];
		k[i][1]=f[p][1]+k[i-1][0];
		k[i][0]=f[p][0]+max(k[i-1][0],k[i-1][1]);
	}
	ans=k[qt][0];
	k[1][1]=-INF,k[1][0]=f[qu[1]][0];
	for(int i=2;i<=qt;i++){
		int p=qu[i];
		k[i][1]=f[p][1]+k[i-1][0];
		k[i][0]=f[p][0]+max(k[i-1][0],k[i-1][1]);
	}
	ans=max(ans,max(k[qt][0],k[qt][1]));
	printf("%.1f\n",h*double(ans));
	return 0;
}
