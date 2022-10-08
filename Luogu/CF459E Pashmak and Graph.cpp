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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e5+7,Mod=998244353,INF=1e9+7;
int n,m,f[N],g[N],ans;
struct edge{int u,v,w;edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
bool operator < (const edge& A)const{return w<A.w;}}e[N];

signed main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),e[i]=edge(u,v,read());
	sort(e+1,e+m+1);
	for(int i=1,j;i<=m;){
		j=i;
		while(j<m&&e[j+1].w==e[i].w)++j;
		for(int k=i,u,v;k<=j;k++){
			u=e[k].u,v=e[k].v;
			g[v]=max(g[v],f[u]+1);
		}
		for(int k=i;k<=j;k++)f[e[k].v]=max(f[e[k].v],g[e[k].v]);
		i=j+1;
	}
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}

