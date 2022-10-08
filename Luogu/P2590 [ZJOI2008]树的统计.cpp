#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define ll long long
#define ull uisngned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=0;
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-')qry=-1;}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();
return qrx*qry;}

const int N=3e4+7,Mod=998244353,INF=0x3f3f3f3f;
int n,q,a[N],val[N],fa[N],dep[N],cnt[N];
int son[N],tp[N],dn,dfn[N];
int sum[N*4],maxv[N*4];
char op[100];
vector<int> g[N],ch[N];

int build(int L,int R,int o){
	int M=(L+R)>>1;
	if(L==R)sum[o]=val[L],maxv[o]=val[L];
	else{
		sum[o]=build(L,M,o<<1)+build(M+1,R,(o<<1)|1);
		maxv[o]=max(maxv[o<<1],maxv[(o<<1)|1]);
	}
	return sum[o];
}

int query_sum(int L,int R,int l,int r,int o){
	if(l<=L&&r>=R)return sum[o];
	int M=(L+R)>>1,res=0;
	if(l<=M)res+=query_sum(L,M,l,r,o<<1);
	if(r>M)res+=query_sum(M+1,R,l,r,(o<<1)|1);
	return res;
}

int query_max(int L,int R,int l,int r,int o){
	if(l<=L&&r>=R)return maxv[o];
	int M=(L+R)>>1,res=-INF;
	if(l<=M)res=max(res,query_max(L,M,l,r,o<<1));
	if(r>M)res=max(res,query_max(M+1,R,l,r,(o<<1)|1));
//	printf("(%d %d %d %d %d)\n",L,R,l,r,res);
	return res;
}

void up_val(int L,int R,int x,int v,int o){
	if(L==R)sum[o]=maxv[o]=val[L];
	else{
		int M=(L+R)>>1;
		if(x<=M)up_val(L,M,x,v,o<<1);
		else up_val(M+1,R,x,v,(o<<1)|1);
		sum[o]=sum[o<<1]+sum[(o<<1)|1];
		maxv[o]=max(maxv[o<<1],maxv[(o<<1)|1]);
	}
	return;
}

void init_tree(int rt,int d){
	dep[rt]=d,cnt[rt]=1;
	for(int i=0;i<int(g[rt].size());i++){
		int to=g[rt][i];
		if(!cnt[to]){
			ch[rt].push_back(to);
			fa[to]=rt,init_tree(to,d+1),cnt[rt]+=cnt[to];
			if(cnt[to]>cnt[son[rt]])son[rt]=to;
		}
	}
	return;
}

void dfs(int rt,int p){
	tp[rt]=p,dfn[rt]=++dn;
	if(ch[rt].size())dfs(son[rt],p);
	for(int i=0;i<int(ch[rt].size());i++){
		int to=ch[rt][i];
		if(son[rt]!=to)dfs(to,to);
	}
	return;
}

int main(){
	n=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),g[u].push_back(v),g[v].push_back(u);
	for(int i=1;i<=n;i++)a[i]=read();
	init_tree(1,1);
	dfs(1,1);
	for(int i=1;i<=n;i++)val[dfn[i]]=a[i];
	build(1,n,1);
	
	q=read();
	while(q--){
		scanf("%s",op+1);
		int u=read(),v=read();
		if(op[2]=='H'){
			val[dfn[u]]=v;
			up_val(1,n,dfn[u],v,1);
		}
		if(op[2]=='M'){
			int ans=-INF;
			while(tp[u]!=tp[v]){
//				printf("(%d %d)",u,v);
				if(dep[tp[v]]<=dep[tp[u]])ans=max(ans,query_max(1,n,dfn[tp[u]],dfn[u],1)),u=fa[tp[u]];
				else ans=max(ans,query_max(1,n,dfn[tp[v]],dfn[v],1)),v=fa[tp[v]];
//				printf("->(%d %d) [%d]\n",u,v,ans);
			}
//			printf("<%d %d %d>",min(dfn[u],dfn[v]),max(dfn[u],dfn[v]),query_max(1,n,min(dfn[u],dfn[v]),max(dfn[u],dfn[v]),1));
			ans=max(ans,query_max(1,n,min(dfn[u],dfn[v]),max(dfn[u],dfn[v]),1));
			printf("%d\n",ans);
		}
		if(op[2]=='S'){
			int ans=0;
			while(tp[u]!=tp[v]){
				if(dep[tp[v]]<=dep[tp[u]])ans+=query_sum(1,n,dfn[tp[u]],dfn[u],1),u=fa[tp[u]];
				else ans+=query_sum(1,n,dfn[tp[v]],dfn[v],1),v=fa[tp[v]];
			}
			ans+=query_sum(1,n,min(dfn[u],dfn[v]),max(dfn[u],dfn[v]),1);
			printf("%d\n",ans);
		}
	}
	
	return 0;
}
