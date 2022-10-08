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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N],val[N];
int cnt[N],dep[N],fa[N],hv[N],top[N],dfn[N],tot;
int lc[N<<2],rc[N<<2],w[N<<2],tag[N<<2];
char op;
vector<int> g[N],ch[N];

void dfs1(int u,int pr,int dp){
	cnt[u]=1,dep[u]=dp,fa[u]=pr;
	for(int i=0;i<int(g[u].size());i++){
		int v=g[u][i];
		if(v==pr)continue;
		dfs1(v,u,dp+1),cnt[u]+=cnt[v],ch[u].push_back(v);
	}
	return;
}

void dfs2(int u,int pr){
	top[u]=pr,dfn[u]=++tot;
	for(int i=0;i<int(ch[u].size());i++)if(cnt[ch[u][i]]>cnt[hv[u]])hv[u]=ch[u][i];
	if(hv[u])dfs2(hv[u],pr);
	for(int i=0;i<int(ch[u].size());i++)if(ch[u][i]!=hv[u])dfs2(ch[u][i],ch[u][i]);
	return;
}

void pushup(int id){
	int Lid=id<<1,Rid=Lid|1;
	w[id]=w[Lid]+w[Rid];
	lc[id]=lc[Lid],rc[id]=rc[Rid];
	if(rc[Lid]==lc[Rid])--w[id];
	return;
}

void pushdown(int id){
	if(tag[id]){
		lc[id]=rc[id]=tag[id],w[id]=1;
		tag[id<<1]=tag[(id<<1)|1]=tag[id],tag[id]=0;
	}
	return;
}

void build(int L,int R,int id){
	if(L==R)lc[id]=rc[id]=val[L],w[id]=1;
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
		pushup(id);
	}
	return;
}

void update(int L,int R,int id,int l,int r,int c){
	pushdown(id);
	if(l<=L&&r>=R)tag[id]=c,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,id<<1,l,r,c);
		else pushdown(id<<1);
		if(r>M)update(M+1,R,(id<<1)|1,l,r,c);
		else pushdown((id<<1)|1);
		pushup(id);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return w[id];
	int res=0,M=(L+R)>>1;
	if(l<=M)res+=query(L,M,id<<1,l,r);
	if(r>M)res+=query(M+1,R,(id<<1)|1,l,r);
	if(l<=M&&r>M&&rc[id<<1]==lc[(id<<1)|1])--res;
	return res;
}

int cl(int L,int R,int id,int p){
	pushdown(id);
	if(L==R)return lc[id];
	int M=(L+R)>>1;
	if(p<=M)return cl(L,M,id<<1,p);
	else return cl(M+1,R,(id<<1)|1,p);
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),g[u].push_back(v),g[v].push_back(u);
	dfs1(1,0,0),dfs2(1,1);
	for(int i=1;i<=n;i++)val[dfn[i]]=a[i];
	build(1,n,1);
	for(int i=1,u,v,c,ans;i<=m;i++){
		op=getchar();
		while((op!='Q')&&(op!='C'))op=getchar();
		u=read(),v=read();
		if(op=='C'){
			c=read();
			while(top[u]!=top[v]){
				if(dep[top[u]]<dep[top[v]])T=u,u=v,v=T;
				int up=top[u];
				update(1,n,1,dfn[up],dfn[u],c);
				u=fa[up];
			}
			if(dep[u]>dep[v])T=u,u=v,v=T;
			update(1,n,1,dfn[u],dfn[v],c);
		}
		else{
			ans=0;
			while(top[u]!=top[v]){
				if(dep[top[u]]<dep[top[v]])T=u,u=v,v=T;
				int up=top[u];
				ans+=query(1,n,1,dfn[up],dfn[u]);
				if(cl(1,n,1,dfn[up])==cl(1,n,1,dfn[fa[up]]))--ans;
				u=fa[up];
			}
			if(dep[u]>dep[v])T=u,u=v,v=T;
			ans+=query(1,n,1,dfn[u],dfn[v]);
			printf("%d\n",ans);
		}
	}
	return 0;
}
