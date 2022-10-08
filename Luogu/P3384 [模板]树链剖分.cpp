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
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,root,P,a[N],val[N];
int fa[N],cnt[N],dep[N],hv[N],dfn[N],dffn[N],top[N],tot;
int sum[N<<2],add[N<<2],len[N<<2];
vector<int> g[N],ch[N];

void dfs1(int u,int pr,int dp){
	cnt[u]=1,dep[u]=dp;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==pr)continue;
		dfs1(v,u,dp+1),fa[v]=u,cnt[u]+=cnt[v];
		ch[u].push_back(v);
	}
	return;
}

void dfs2(int u,int pr){
	top[u]=pr,dfn[u]=++tot;
	for(int i=0;i<ch[u].size();i++)if(cnt[ch[u][i]]>cnt[hv[u]])hv[u]=ch[u][i];
	if(hv[u])dfs2(hv[u],pr);
	for(int i=0;i<ch[u].size();i++)if(ch[u][i]!=hv[u])dfs2(ch[u][i],ch[u][i]);
	dffn[u]=tot;
	return;
}

void pushdown(int id){
	if(add[id]){
		sum[id]=(sum[id]+add[id]%P*len[id])%P;
		add[id<<1]=(add[id<<1]+add[id])%P,add[(id<<1)|1]=(add[(id<<1)|1]+add[id])%P;
		add[id]=0;
	}
	return;
}

void build(int L,int R,int id){
	len[id]=R-L+1;
	if(L==R)sum[id]=val[L]%P;
	else{
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
		sum[id]=(sum[id<<1]+sum[(id<<1)|1])%P;
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&r>=R)add[id]+=x,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,id<<1,l,r,x);
		if(r>M)update(M+1,R,(id<<1)|1,l,r,x);
		pushdown(id<<1),pushdown((id<<1)|1);
		sum[id]=(sum[id<<1]+sum[(id<<1)|1])%P;
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&r>=R)return sum[id]%P;
	int res=0,M=(L+R)>>1;
	if(l<=M)res+=query(L,M,id<<1,l,r);
	if(r>M)res+=query(M+1,R,(id<<1)|1,l,r);
	return res%P;
}

signed main(){
	n=read(),m=read(),root=read(),P=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs1(root,0,0);
	dfs2(root,root);
	for(int i=1;i<=n;i++)val[dfn[i]]=a[i];
	build(1,n,1);
	for(int i=1,op,x,y,z;i<=m;i++){
		op=read();
		if(op==1){
			x=read(),y=read(),z=read();
			while(top[x]!=top[y]){
				if(dep[top[x]]>dep[top[y]]){
					int A=top[x];
					update(1,n,1,dfn[A],dfn[x],z);
					x=fa[A];
				}
				else{
					int A=top[y];
					update(1,n,1,dfn[A],dfn[y],z);
					y=fa[A];
				}
			}
			if(dep[y]<dep[x]){int T=x;x=y,y=T;}
			update(1,n,1,dfn[x],dfn[y],z);
		}
		if(op==2){
			x=read(),y=read();
			int ans=0;
			while(top[x]!=top[y]){
				if(dep[top[x]]>dep[top[y]]){
					int A=top[x];
					ans=(ans+query(1,n,1,dfn[A],dfn[x]))%P;
					x=fa[A];
				}
				else{
					int A=top[y];
					ans=(ans+query(1,n,1,dfn[A],dfn[y]))%P;
					y=fa[A];
				}
				
			}
			if(dep[y]<dep[x]){int T=x;x=y,y=T;}
			ans=(ans+query(1,n,1,dfn[x],dfn[y]))%P;
			printf("%lld\n",ans);
		}
		if(op==3){
			x=read(),z=read();
			update(1,n,1,dfn[x],dffn[x],z);
		}
		if(op==4){
			x=read();
			printf("%lld\n",query(1,n,1,dfn[x],dffn[x]));
		}
	}
	return 0;
}
