#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int to,w;
    edge(int to=0,int w=0):to(to),w(w){}
};

const int N=1e6+7;
int n,m,h[N];
int vis[N],fa[N][22],d[N];
vector<edge> to[N],ch[N];

void init_tree(int root,int dep){
    vis[root]=1,d[root]=dep;
    for(int i=0;i<to[root].size();i++){
        int j=to[root][i].to;
        if(!vis[j])ch[root].push_back(edge(j,to[root][i].w)),fa[j][0]=root,init_tree(j,dep+1);
    }
}

int LCA(int a,int b){
    int w=20;
    if(d[b]<d[a]){int t=a;a=b,b=t;}
    while(w>=0&&d[a]<d[b]){
        if(d[a]<=d[fa[b][w]])b=fa[b][w];
        --w;
    }
	if(a==b)return a;
	
    w=20;
    while(w>=0){
        if(fa[a][w]!=fa[b][w])a=fa[a][w],b=fa[b][w];
        --w;
    }
    return fa[a][0];
}

int main(){
	
	int r=1;
    scanf("%d%d",&n,&m);
    for(int i=1,u,v,w=0;i<n;i++)scanf("%d%d",&u,&v),to[u].push_back(edge(v,w)),to[v].push_back(edge(u,w));
    init_tree(r,1),fa[r][0]=r;
    for(int i=1;i<=20;i++)for(int j=1;j<=n;j++)fa[j][i]=fa[fa[j][i-1]][i-1];

    while(m--){
    	int a,b;
        scanf("%d%d",&a,&b);
        int lca=LCA(a,b),dis=d[a]+d[b]-d[lca]*2;
        if(dis%2)printf("Road\n");
        else printf("Town\n");
    }

    return 0;
}
