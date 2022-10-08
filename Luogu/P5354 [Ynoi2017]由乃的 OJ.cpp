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

#define int unsigned long long
#define Lid (id<<I)
#define Rid ((id<<1)|I)
#define M ((L+R)>>I)

using namespace std;

int read(){int qrx=0;char qrc=getchar();while(qrc<'0'||qrc>'9')qrc=getchar();
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int I=1,n,m,k,opt[N],val[N],K,ans,p0,p1;
unsigned hd[N],nxt[N*2],to[N*2],ec;
unsigned fa[N],dep[N],cnt[N],son[N],top[N],dfn[N],ct,pos[N];
struct node{int lx,ly,rx,ry;node(int lx=0,int ly=0,int rx=0,int ry=0):lx(lx),ly(ly),rx(rx),ry(ry){}}t[N*4],Lc[N],Rc[N];
inline void add(unsigned u,unsigned v){to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;return;}

inline node merge(node A,node B){
	return node(
	(A.lx&B.ly)|(~A.lx&B.lx),(A.ly&B.ly)|(~A.ly&B.lx),
	(B.rx&A.ry)|(~B.rx&A.rx),(B.ry&A.ry)|(~B.ry&A.rx));
}

inline void initnode(unsigned id,unsigned p){
	p=pos[p];
	if(opt[p]==1)t[id]=node(0,val[p],0,val[p]);
	if(opt[p]==2)t[id]=node(val[p],K,val[p],K);
	if(opt[p]==3)t[id]=node(val[p],K^val[p],val[p],K^val[p]);
	return;
}

void dfs1(unsigned u,unsigned from,unsigned D){
	fa[u]=from,dep[u]=D,cnt[u]=1;
	for(unsigned i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs1(v,u,D+1),cnt[u]+=cnt[v];
		if(cnt[son[u]]<cnt[v])son[u]=v;
	}
	return;
}

void dfs2(unsigned u,unsigned from,unsigned T){
	top[u]=T,dfn[u]=++ct;
	if(son[u])dfs2(son[u],u,T);
	for(unsigned i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

inline void build(unsigned L,unsigned R,unsigned id){
	if(L==R)initnode(id,L);
	else{
		build(L,M,Lid),build(M+1,R,Rid);
		t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

inline void update(unsigned L,unsigned R,unsigned id,unsigned x){
	if(L==R)initnode(id,L);
	else{
		if(x<=M)update(L,M,Lid,x);
		else update(M+1,R,Rid,x);
		t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

unsigned l,r;
inline node query(unsigned L,unsigned R,unsigned id){
	if(l<=L&&r>=R)return t[id];
	if(r<=M)return query(L,M,Lid);
	if(l>M)return query(M+1,R,Rid);
	return merge(query(L,M,Lid),query(M+1,R,Rid));
}

signed main(){
	n=read(),m=read();
	k=read(),K=(I<<k)-1;
	if(k==64)K=((I<<63)-1)*2+1;
	for(unsigned i=1;i<=n;i++)opt[i]=read(),val[i]=read();
	for(unsigned i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1,0,1),dfs2(1,0,1);
	for(unsigned i=1;i<=n;i++)pos[dfn[i]]=i;
	build(1,n,1);
	for(int i=1,op,x,y,z;i<=m;i++){
		op=read(),x=read(),y=read(),z=read();
		if(op==2)opt[x]=y,val[x]=z,update(1,n,1,dfn[x]);
		else{
			unsigned lt=0,rt=0;
			while(top[x]^top[y]){
				if(dep[top[x]]>dep[top[y]]){
					l=dfn[top[x]],r=dfn[x];
					Lc[++lt]=query(1,n,1);
					x=fa[top[x]];
				}
				else{
					l=dfn[top[y]],r=dfn[y];
					Rc[++rt]=query(1,n,1);
					y=fa[top[y]];
				}
			}
			if(dep[x]>dep[y])l=dfn[y],r=dfn[x],Lc[++lt]=query(1,n,1);
			else l=dfn[x],r=dfn[y],Rc[++rt]=query(1,n,1);
			for(unsigned j=1;j<=lt;j++)Lc[j]=node(Lc[j].rx,Lc[j].ry,0,0);
			while(rt)Lc[++lt]=Rc[rt--];
			for(unsigned j=2;j<=lt;j++)Lc[j]=merge(Lc[j-1],Lc[j]);
			ans=0,p0=Lc[lt].lx,p1=Lc[lt].ly;
			for(int j=k-1;j<=k;j--){
				if(p0&(I<<j))ans+=(I<<j);
				else if((p1&(I<<j))&&z>=(I<<j))z-=(I<<j),ans+=(I<<j);
			}
			printf("%llu\n",ans);
		}
	}
	return 0;
}

