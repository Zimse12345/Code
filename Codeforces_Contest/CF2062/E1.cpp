#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,INF=1e9+7;

int read(){
    int x=0,y=1;
    char c=getchar();
    while(c<48||57<c){
        if(c==45)y=-1;
        c=getchar();
    }
    while(47<c&&c<58)x=x*10+c-48,c=getchar();
    return x*y;
}

int n,w[N];
int fa[N],cnt[N],dfn[N],dep[N],top[N],hv[N],ct;
vector<int> g[N],ch[N];
vector<int> id[N];

void dfs1(int u,int pr,int d){
	dep[u]=d,dfn[u]=++ct,fa[u]=pr,cnt[u]=1;
	for(int i=0;i<int(g[u].size());i++){
		int v=g[u][i];
		if(v==pr)continue;
		dfs1(v,u,d+1);
		cnt[u]+=cnt[v];
		ch[u].push_back(v);
		if(cnt[hv[u]]<cnt[v])hv[u]=v;
	}
	return;
}

void dfs2(int u,int pr){
	top[u]=pr;
	if(hv[u])dfs2(hv[u],pr);
	for(int i=0;i<int(ch[u].size());i++){
		int v=ch[u][i];
		if(v==hv[u])continue;
		dfs2(v,v);
	}
	return;
}

int LCA(int u,int v){
    while(top[u]!=top[v]){
		if(dep[top[u]]<=dep[top[v]])v=fa[top[v]];
		else u=fa[top[u]];
	}
	if(dep[u]>dep[v]){int T=u;u=v,v=T;}
	return u;
}

int main(){
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++){
            fa[i]=cnt[i]=dfn[i]=dep[i]=top[i]=hv[i]=0;
            g[i].resize(0);
            ch[i].resize(0);
            id[i].resize(0);
        }
        for(int i=1;i<=n;i++){
            cin>>w[i];
            id[w[i]].push_back(i);
        }
        ct=0;
        for(int i=1;i<n;i++){
    		int u=read(),v=read();
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
    	dfs1(1,1,0),dfs2(1,1);
    	int ans=0,p=n;
    	while(!id[p].size())--p;
    	int lca=id[p][0];
    	for(unsigned i=1;i<id[p].size();i++)lca=LCA(lca,id[p][i]);
    	for(int i=p-1;i>=1;i--)if(id[i].size()){
    	    for(unsigned j=0;j<id[i].size();j++){
    	        if(dep[id[i][j]]>dep[lca]||LCA(id[i][j],lca)!=id[i][j]){
    	            ans=id[i][j];
    	            break;
                }
            }
            if(ans)break;
            for(unsigned j=0;j<id[i].size();j++)lca=LCA(id[i][j],lca);
        }
        printf("%d\n",ans);
    }
	return 0;
}
