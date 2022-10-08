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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,hd[N],nxt[N],to[N],ec,In[N],Out[N],vis[N],cnt,indeg[N],outdeg[N],ans,t;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}}s[N];

void dfs(int u){
	if(vis[u]++)return;
	if(Out[u]<In[u])indeg[cnt]+=In[u]-Out[u];
	else outdeg[cnt]+=Out[u]-In[u];
	for(int i=hd[u];i;i=nxt[i])dfs(to[i]);
	return; 
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),++Out[u],++In[v],add(u,v),add(v,u);
	for(int i=1;i<=n;i++){
		if(!vis[i]&&(In[i]||Out[i]))++cnt,dfs(i);
		ans+=abs(In[i]-Out[i]);
	}
	ans/=2;
	for(int i=1;i<=cnt;i++)if(indeg[i]==0&&outdeg[i]==0)++ans;
	printf("%d\n",ans);
	return 0;
}

