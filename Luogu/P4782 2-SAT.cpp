#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std; 

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();
return qrx*qry;}

const int N=2e6+7,Mod=998244353,INF=0x3f3f3f3f;
int n,m,ve[N],dfn[N],low[N],vis[N],tot,st[N],cnt,cl[N],cn;
int vl[N],f[N];
vector<int> g[N],p[N],G[N];

void tarjan(int u){
	dfn[u]=low[u]=++tot,st[++cnt]=u,vis[u]=1;
	for(int i=0;i<int(g[u].size());i++){
		int v=g[u][i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v])low[u]=min(low[u],dfn[v]);
	}
	
	if(dfn[u]==low[u]){
		int siz=1;
		cl[u]=++cn,vis[u]=0,p[cn].push_back(u);
		while(st[cnt]!=u)cl[st[cnt]]=cn,p[cn].push_back(st[cnt]),++siz,vis[st[cnt--]]=0;
		--cnt;
//		if(siz>1)++ans;
	}
	
//	vis[u]=0;
	return;
}

int dfs(int u){
	if(f[u])return f[u];
	f[u]=vl[u];int res=0;
	for(int i=0;i<int(G[u].size());i++){
		int v=G[u][i];
		res=max(res,dfs(v));
	}
	f[u]+=res;
	return f[u];
}

int cho[N],ans[N];

int main(){
	n=read(),m=read();
	for(int i=1,u,uu,v,vv;i<=m;i++){
		u=read(),uu=read(),v=read(),vv=read();
		g[u+n*(uu^1)].push_back(v+n*vv);
		g[v+n*(vv^1)].push_back(u+n*uu);
	}
	n*=2;
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	n/=2;
	for(int i=1;i<=n;i++)if(cl[i]==cl[i+n])return !printf("IMPOSSIBLE\n");
	printf("POSSIBLE\n");
	
	for(int i=1;i<=n;i++){
		if(cho[i+n]){
			ans[i]=1;
			continue;
		}
		if(!cho[i])cho[i]=1;
	}
	
	for(int i=1;i<=n;i++)printf("%d ",(cl[i]>cl[i+n]?1:0));
	printf("\n");
	return 0;
}
