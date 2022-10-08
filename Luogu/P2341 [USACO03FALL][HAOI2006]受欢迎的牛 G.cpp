#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std; 

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();
return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=0x3f3f3f3f;
int n,m,dfn[N],low[N],vis[N],tot,st[N],cnt,cl[N],cn,ans;
int vvis[N],pre[N],sz[N];
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
		--cnt,sz[cn]=siz;
//		if(siz>1)++ans;
	}
	
//	vis[u]=0;
	return;
}

int dfs(int u){
	if(vvis[u])return 0;
	vvis[u]=1;
	for(int i=0;i<int(G[u].size());i++){
		int v=G[u][i];
		dfs(v);
	}
	return 0;
}

int main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),g[v].push_back(u);
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	
	for(int i=1;i<=cn;i++){
		for(int j=0;j<int(p[i].size());j++){
			int u=p[i][j];
			for(int k=0;k<int(g[u].size());k++){
				int v=g[u][k];
				if(cl[v]!=i)G[i].push_back(cl[v]),++pre[cl[v]];
			}
		}
	}
	
	int y=0; 
	for(int i=1;i<=cn;i++)if(!pre[i]){
		dfs(i);
		for(int j=1;j<=cn;j++)ans+=vvis[j];
		if(ans==cn)y=i;
		break;
	}
	
	printf("%d\n",sz[y]);
	return 0;
}
