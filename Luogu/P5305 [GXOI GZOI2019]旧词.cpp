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
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,ans[N],k,f[N];
int fa[N],dep[N],cnt[N],hv[N],dfn[N],top[N],ct;
int sum[N*4],tag[N*4],len[N*4],tagl[N*4],tagr[N*4];
vector<int> g[N];
struct qu{
	int p,z,id;
	qu(int p=0,int z=0,int id=0):p(p),z(z),id(id){}
	bool operator < (const qu& A)const{return p<A.p;} 
}q[N];

void dfs1(int u,int pr,int dp){
	fa[u]=pr,dep[u]=dp,cnt[u]=1;
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v==pr)continue;
		dfs1(v,u,dp+1),cnt[u]+=cnt[v];
		if(cnt[hv[u]]<cnt[v])hv[u]=v;
	}
	return;
}

void dfs2(int u,int pr){
	dfn[u]=++ct,top[u]=pr;
	if(hv[u])dfs2(hv[u],pr);
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i];
		if(v==hv[u]||v==fa[u])continue;
		dfs2(v,v);
	}
	return;
}

void build(int L,int R,int id){
	len[id]=R-L+1;
	if(L!=R)build(L,(L+R)/2,Lid),build((L+R)/2+1,R,Rid);
	return;
}

void pushdown(int id){
	if(tag[id]){
		sum[id]=(sum[id]+tag[id]*(f[tagr[id]]-f[tagl[id]-1]))%Mod;
		if(len[id]>1){
			tag[Lid]+=tag[id],tag[Rid]+=tag[id];
			tagl[Lid]=tagl[id],tagr[Lid]=tagl[id]+len[Lid]-1;
			tagr[Rid]=tagr[id],tagl[Rid]=tagr[id]-len[Rid]+1;
			//printf("[%d %d]->[%d,%d]U[%d,%d]\n",tagl[id],tagr[id],tagl[Lid],tagr[Lid],tagl[Rid],tagr[Rid]);
		}
		tag[id]=0;
	}
	return;
}

void update(int L,int R,int id,int l,int r,int ls,int rs){
	pushdown(id);
	if(l<=L&&r>=R){
		//printf("(%d %d %d %d)\n",l,r,ls+(L-l),rs-(r-R));
		tagl[id]=ls+(L-l),tagr[id]=rs-(r-R),tag[id]=1,pushdown(id);
	}
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,Lid,l,r,ls,rs);
		else pushdown(Lid);
		if(r>M)update(M+1,R,Rid,l,r,ls,rs);
		else pushdown(Rid);
		sum[id]=(sum[Lid]+sum[Rid])%Mod;
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	int M=(L+R)>>1,res=0;
	if(l<=L&&r>=R)res+=sum[id];
	else{
		if(l<=M)res+=query(L,M,Lid,l,r);
		if(r>M)res+=query(M+1,R,Rid,l,r);
	}
	//printf("[%d %d %d %d %d]\n",L,R,l,r,res);
	return res%Mod;
}

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2;
	}
	return res;
}

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)f[i]=qp(i,k);//printf("(%d %d)\n",i,f[i]);
	for(int i=2,fa;i<=n;i++){
		fa=read();
		g[fa].push_back(i),g[i].push_back(fa);
	}
	dfs1(1,0,1),dfs2(1,1);
	build(1,n,1);
	for(int i=1,r,z;i<=m;i++){
		r=read(),z=read();
		q[i]=qu(r,z,i);
	}
	sort(q+1,q+m+1);
	for(int i=1,j=1,u,res;i<=m;i++){
		while(j<=q[i].p){
			u=j++;
			while(u){
				update(1,n,1,dfn[top[u]],dfn[u],dep[top[u]],dep[u]);
				//printf("update(%d,%d,%d,%d)\n",dfn[top[u]],dfn[u],dep[top[u]],dep[u]);
				u=fa[top[u]];
			}
		}
		u=q[i].z,res=0;
		while(u){
			res=(res+query(1,n,1,dfn[top[u]],dfn[u]))%Mod;
			//printf("query(%d,%d)=%d\n",dfn[top[u]],dfn[u],query(1,n,1,dfn[top[u]],dfn[u]));
			u=fa[top[u]];
		}
		ans[q[i].id]=res;
	}
	for(int i=1;i<=m;i++)printf("%lld\n",(ans[i]%Mod+Mod)%Mod);
}
