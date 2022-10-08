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

#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,f[N],ans[N];
int fa[N],dep[N],cnt[N],dfn[N],son[N],top[N],ct,fe[N],p[N];
int sum[N*4],ls[N*4],rs[N*4],len[N*4];
int t1,t2;
struct edge{
	int to,id;
	edge(int to=0,int id=0):to(to),id(id){}
};
struct eg{
	int w,id;
	eg(int w=0,int id=0):w(w),id(id){}
	bool operator < (const eg& A)const{return w<A.w;}
}e[N];
struct qy{
	int l,r,w,id;
	qy(int l=0,int r=0,int w=0,int id=0):l(l),r(r),w(w),id(id){}
	bool operator < (const qy& A)const{return w<A.w;} 
}qu[N];
struct node{
	int ls,rs,len,sum;
	node(int ls=0,int rs=0,int len=0,int sum=0):ls(ls),rs(rs),len(len),sum(sum){}
}pL[N],pR[N];;
vector<edge> g[N];

void dfs1(int u,int pr,int dp){
	fa[u]=pr,dep[u]=dp,cnt[u]=1;
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i].to;
		if(v==pr)continue;
		dfs1(v,u,dp+1),cnt[u]+=cnt[v],fe[v]=g[u][i].id;
		if(cnt[v]>cnt[son[u]])son[u]=v;
	}
	return;
}

void dfs2(int u,int pr){
	dfn[u]=p[fe[u]]=++ct,top[u]=pr;//printf("(%d %d %d)\n",u,dfn[u],fe[u]);
	if(son[u])dfs2(son[u],pr);
	for(int i=0,v;i<signed(g[u].size());i++){
		v=g[u][i].to;
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
	return;
}

void build(int L,int R,int id){
	len[id]=R-L+1;
	if(L!=R)build(L,(L+R)/2,Lid),build((L+R)/2+1,R,Rid);
	return;
}

node pushup(node l,node r){
	int Sum=l.sum+r.sum+f[l.rs+r.ls]-f[l.rs]-f[r.ls];
	int Ls=l.ls==l.len?l.ls+r.ls:l.ls;
	int Rs=r.rs==r.len?r.rs+l.rs:r.rs;
	return node(Ls,Rs,l.len+r.len,Sum);
}

node rev(node x){
	return node(x.rs,x.ls,x.len,x.sum);
}

void update(int L,int R,int id,int x){
	if(L==R)sum[id]=f[1],ls[id]=rs[id]=1;
	else{
		int M=(L+R)>>1;
		if(x<=M)update(L,M,Lid,x);
		else update(M+1,R,Rid,x);
		sum[id]=sum[Lid]+sum[Rid]+f[rs[Lid]+ls[Rid]]-f[rs[Lid]]-f[ls[Rid]];
		ls[id]=ls[Lid]==len[Lid]?ls[Lid]+ls[Rid]:ls[Lid];
		rs[id]=rs[Rid]==len[Rid]?rs[Rid]+rs[Lid]:rs[Rid];
	}
	return;
}

node query(int L,int R,int id,int l,int r){
	if(l<=L&&r>=R)return node(ls[id],rs[id],len[id],sum[id]);
	int M=(L+R)>>1;
	if(r<=M)return query(L,M,Lid,l,r);
	if(l>M)return query(M+1,R,Rid,l,r);
	node lp=query(L,M,Lid,l,r),rp=query(M+1,R,Rid,l,r);
	return pushup(lp,rp);
}

int main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<n;i++)f[i]=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		g[u].push_back(edge(v,i)),g[v].push_back(edge(u,i));
		e[i]=eg(w,i);
	}
	sort(e+1,e+n);
	for(int i=1,l,r,w;i<=q;i++){
		l=read(),r=read(),w=read();
		qu[i]=qy(l,r,w,i);
	}
	sort(qu+1,qu+q+1);
	dfs1(1,0,0),dfs2(1,1),build(1,n,1);
	for(int i=q,u,v,w,res,R=n-1;i>=1;i--){
		//printf(">-- %d --<\n",qu[i].id);
		u=qu[i].l,v=qu[i].r,w=qu[i].w,res=0,t1=t2=0;
		while(R>=1&&e[R].w>=w){
			//printf("add(%d)\n",p[e[R].id])
			update(1,n,1,p[e[R].id]),--R;
		}
		while(top[u]!=top[v]){
			if(dep[top[u]]>dep[top[v]]){
				pL[++t1]=query(1,n,1,dfn[top[u]],dfn[u]);
				//printf("L[%d %d]\n",dfn[top[u]],dfn[u]);
				u=fa[top[u]];
			}
			else{
				pR[++t2]=query(1,n,1,dfn[top[v]],dfn[v]);
				//printf("R[%d %d]\n",dfn[top[v]],dfn[v]);
				v=fa[top[v]];
			}
		}
		if(dep[u]>dep[v])pL[++t1]=query(1,n,1,dfn[v]+1,dfn[u]);//printf("L[%d %d]\n",dfn[v]+1,dfn[u]);
		if(dep[v]>dep[u])pR[++t2]=query(1,n,1,dfn[u]+1,dfn[v]);//printf("R[%d %d]\n",dfn[u]+1,dfn[v]);
		node k;
		for(int i=1;i<=t1;i++)pL[i]=rev(pL[i]),k=pushup(k,pL[i]);
		for(int i=t2;i>=1;i--)k=pushup(k,pR[i]);
//		if(qu[i].id==1){
//			for(int i=1;i<=t1;i++)printf("> L(%d %d %d %d)\n",pL[i].ls,pL[i].rs,pL[i].len,pL[i].sum);
//			for(int i=t2;i>=1;i--)printf("> R(%d %d %d %d)\n",pR[i].rs,pR[i].ls,pR[i].len,pR[i].sum);
//			printf("< (%d %d %d %d)\n",k.ls,k.rs,k.len,k.sum);
//		}
		res=k.sum;
		ans[qu[i].id]=res;
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}
