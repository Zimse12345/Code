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

const int N=1e6+7,Mod=998244353;
const long long INF=1e12+7;
int n,vis[N],ir[N],inq[N],qu[N],qt,r,hl[N],hr[N];
ll a[N],f[N][2],k[N][2],ans;
vector<int> g[N];

void dfs1(int u,int pr){
	//printf("[%d<-%d]",u,pr);
	vis[u]=1,inq[u]=1,qu[++qt]=u;
	
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==pr)continue;//printf("[%d->%d]",u,v);
		if(inq[v]){
			int p=qt,z=v;
			ir[v]=1,r=v,vis[v]=1;//printf("<%d>",v);
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
	ll f0=0,f1=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==pr||v==hl[u]||v==hr[u]||f[v][1]>0)continue;
		dfs2(v,u);
		f0+=max(f[v][0],f[v][1]),f1+=f[v][0];
	}
	f[u][0]=f0,f[u][1]=f1+a[u];
	//printf("[%d %d %d]\n",u,f[u][0],f[u][1]);
	return;
}

signed main(){
	n=read();
	for(int i=1,h;i<=n;i++){
		a[i]=read(),h=read();
		g[i].push_back(h),g[h].push_back(i);
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		qt=0,r=i;
		dfs1(i,0),qt=0;
		int p=r;
		ll res=0;
		//printf("[%d %d]\n",i,r);
		if(!ir[p]){
			dfs2(p,0);
			//printf("*(%d %d)\n",p,max(f[p][0],f[p][1]));
			ans+=max(f[p][0],f[p][1]);
			continue;
		}
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
		res=k[qt][0];
		k[1][1]=-INF,k[1][0]=f[qu[1]][0];
		for(int i=2;i<=qt;i++){
			int p=qu[i];
			k[i][1]=f[p][1]+k[i-1][0];
			k[i][0]=f[p][0]+max(k[i-1][0],k[i-1][1]);
		}
		res=max(res,max(k[qt][0],k[qt][1]));
//		printf("(%d %d)",res,qt);
//		for(int i=1;i<=qt;i++)printf("%d ",qu[i]);
//		printf("\n");
		ans+=res;
	}
	printf("%lld\n",ans);
	return 0;
}
