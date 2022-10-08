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
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=5e5+7,INF=1e9+7;
int K;
struct v{int a,id;v(int a=0,int id=0):a(a),id(id){}
bool operator < (const v& A)const{return a<A.a;}}b[N];
struct query{
	int l,r,id,ex;
	query(int l=0,int r=0,int id=0,int ex=0):l(l),r(r),id(id),ex(ex){}
	bool operator < (const query& A)const{if(l/K==A.l/K){if((l/K)&1)return r>A.r;return r<A.r;}return l<A.l;}
}qu[N];
int n,m,c[N],Ans[N];
int hd[N],to[N],nxt[N],ec,p[N],q[N],a[N],ct;
int fa[N],cnt[N],dep[N],son[N],top[N];
int tot[N],vis[N],ans;
inline void add(int u,int v){to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;return;}

void dfs(int u,int from,int d){
	a[++ct]=u,p[u]=ct;
	fa[u]=from,cnt[u]=1,dep[u]=d;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u,d+1),cnt[u]+=cnt[v];
		if(cnt[v]>cnt[son[u]])son[u]=v;
	}
	a[++ct]=u,q[u]=ct;
	return;
}

void dfs2(int u,int from,int tp){
	top[u]=tp;
	if(son[u])dfs2(son[u],u,tp);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v); 
	}
	return;
}

int LCA(int a,int b){
	while(top[a]!=top[b]){
		if(dep[top[a]]<dep[top[b]])swap(a,b);
		a=fa[top[a]];
	}
	if(dep[a]<dep[b])return a;
	else return b;
}

inline void ad(int x){
	x=a[x],vis[x]^=1,x=c[x];
	if(!tot[x]++)++ans;
	return;
}

inline void de(int x){
	x=a[x],vis[x]^=1,x=c[x];
	if(!--tot[x])--ans;
	return;
}

signed main(){
	n=read(),m=read(),K=n*2/sqrt(m*2/3),K=max(1,K);
	for(int i=1,x;i<=n;i++)x=read(),b[i]=v(x,i);
	sort(b+1,b+n+1),b[0].a=INF;
	for(int i=1,j=0;i<=n;i++){
		if(b[i].a!=b[i-1].a)++j;
		c[b[i].id]=j; 
	}
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs(1,0,0),dfs2(1,0,1);
	for(int i=1,u,v,l,r;i<=m;i++){
		u=read(),v=read();
		if(p[u]>p[v])swap(u,v);
		int lca=LCA(u,v);
		if(lca==u)l=p[u],r=p[v];
		else l=q[u],r=p[v],qu[i].ex=lca;
		if(l>r)swap(l,r);
		qu[i]=query(l,r,i,qu[i].ex);
	}
	sort(qu+1,qu+m+1),tot[0]=1;
	int x=0;
	for(int i=1,l,r,L=1,R=0;i<=m;i++){
		l=qu[i].l,r=qu[i].r;x+=abs(l-L)+abs(r-R);
		while(R<r){
			++R;
			if(vis[a[R]])de(R);
			else ad(R);
		}
		while(L>l){
			--L;
			if(vis[a[L]])de(L);
			else ad(L);
		}
		while(R>r){
			if(vis[a[R]])de(R);
			else ad(R);
			--R;
		}
		while(L<l){
			if(vis[a[L]])de(L);
			else ad(L);
			++L;
		}
		Ans[qu[i].id]=ans+((!tot[c[qu[i].ex]])?1:0);
	}
	for(int i=1;i<=m;i++)write(Ans[i]),putchar(10);
	return 0;
}

