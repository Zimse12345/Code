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
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=2e6+7,Mod=998244353,INF=1e9+7;
struct node{
	int sum,lx,rx,mx,tag1,tag2;
	node(int sum=0,int lx=0,int rx=0,int mx=0,int tag1=0,int tag2=0):
	sum(sum),lx(lx),rx(rx),mx(mx),tag1(tag1),tag2(tag2){}
}tree[N];
int n,m,rt,tot,ch[N][2],fa[N],val[N],sz[N],rub[N],tr;
char op[N];
inline void clear(int id){Lid=Rid=fa[id]=val[id]=sz[id]=0,tree[id]=tree[0];return;}
inline int gety(int id){return id==ch[fa[id]][1];}
inline int newid(){if(tr)return rub[tr--];return ++tot;}

inline node pushup(node l,node r){
	node res=node(l.sum+r.sum,l.lx,r.rx,max(max(l.mx,r.mx),l.rx+r.lx));
	if(l.sum+r.lx>res.lx)res.lx=l.sum+r.lx;
	if(r.sum+l.rx>res.rx)res.rx=r.sum+l.rx;
	return res;
}

inline void pushdown(int id){
	if(tree[id].tag1&1){
		int x=tree[id].tag2*sz[id],y=x;
		if(y<0)y/=sz[id];
		tree[id]=node(x,y,y,y,tree[id].tag1,tree[id].tag2),val[id]=tree[id].tag2;
		if(Lid)tree[Lid].tag1=1,tree[Lid].tag2=tree[id].tag2;
		if(Rid)tree[Rid].tag1=1,tree[Rid].tag2=tree[id].tag2;
		tree[id].tag1=0;
	}
	if(tree[id].tag1&2){
		swap(Lid,Rid);
		swap(tree[id].lx,tree[id].rx);
		if(Lid)tree[Lid].tag1^=2;
		if(Rid)tree[Rid].tag1^=2;
		tree[id].tag1^=2;
	}
	return;
}

inline void maintain(int id){
	sz[id]=sz[Lid]+sz[Rid]+1;
	pushdown(Lid),pushdown(Rid);
	tree[id]=node(val[id],val[id],val[id],val[id],0,0);
	if(Lid)tree[id]=pushup(tree[Lid],tree[id]);
	if(Rid)tree[id]=pushup(tree[id],tree[Rid]);
	return;
}

void rotate(int x){
	int y=fa[x],z=fa[y];
	int ty=gety(x);
	ch[y][ty]=ch[x][ty^1];
	if(ch[x][ty^1])fa[ch[x][ty^1]]=y;
	ch[x][ty^1]=y,fa[y]=x,fa[x]=z;
	if(z)ch[z][y==ch[z][1]]=x;
	maintain(y),maintain(x);
	return;
}

void splay(int id,int goal){
	while(fa[id]!=goal){
		int f=fa[id],gf=fa[f];
		if(gf!=goal)rotate(gety(id)==gety(f)?f:id);
		rotate(id);
	}
	if(goal==0)rt=id;
	return;
}

void ins(int& id,int from,int k,int v){
	if(!id){
		id=newid(),fa[id]=from,val[id]=v;
		sz[id]=1,tree[id]=node(v,v,v,v,0,0),splay(id,0);
	}
	else{
		pushdown(id);
		if(sz[Lid]>=k-1)ins(Lid,id,k,v);
		else ins(Rid,id,k-1-sz[Lid],v);
	}
	return;
}

int kth(int k){
	int id=rt;
	while(1){
		pushdown(id);
		if(sz[Lid]>=k)id=Lid;
		else if(sz[Lid]+1<k)k-=sz[Lid]+1,id=Rid;
		else return id;
	}
}

int gettree(int l,int r){
	r=l+r-1;
	if(l==1){
		if(r==sz[rt])return rt;
		splay(kth(r+1),0);
		return ch[rt][0];
	}
	if(r==sz[rt]){
		splay(kth(l-1),0);
		return ch[rt][1];
	}
	int x=kth(l-1),y=kth(r+1);
	splay(x,0),splay(y,x);
	return ch[y][0];
}

void thrownode(int id){
	if(!id)return;
	thrownode(Lid),thrownode(Rid);
	clear(id),rub[++tr]=id;
	return;
}

void del(int id){
	ch[fa[id]][gety(id)]=0;
	if(fa[id])maintain(fa[id]);
	if(fa[fa[id]])maintain(fa[fa[id]]);
	thrownode(id);
	return;
}

void makesame(int id,int c){
	tree[id].tag1=1,tree[id].tag2=c;
	pushdown(id);
	if(fa[id])maintain(fa[id]);
	if(fa[fa[id]])maintain(fa[fa[id]]);
	return;
}

void reveres(int id){
	tree[id].tag1^=2;
	pushdown(id);
	if(fa[id])maintain(fa[id]);
	if(fa[fa[id]])maintain(fa[fa[id]]);
	return;
}

int build(int L,int R){
	if(L>R)return 0;
	sz[L]=1,tree[L]=node(val[L],val[L],val[L],val[L],0,0);
	if(L!=R){
		int M=(L+R)>>1;
		int lc=build(L,M-1);
		int rc=build(M+1,R);
		if(lc)tree[M]=pushup(tree[lc],tree[M]),fa[lc]=M;
		if(rc)tree[M]=pushup(tree[M],tree[rc]),fa[rc]=M;
		ch[M][0]=lc,ch[M][1]=rc;
		maintain(M);
		return M;
	}
	return L;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)val[i]=read();
	tot=n;
	rt=build(1,n);
	
	for(int i=1,p,t,c;i<=m;i++){
		scanf("%s",op+1);
		if(op[1]=='I'){
			p=read(),t=read();
			while(t--)ins(rt,0,++p,read());
		}
		if(op[1]=='D'){
			p=read(),t=read();
			del(gettree(p,t));
		}
		if(op[1]=='M'&&op[3]=='K'){
			p=read(),t=read(),c=read();
			makesame(gettree(p,t),c);
		}
		if(op[1]=='R'){
			p=read(),t=read();
			reveres(gettree(p,t));
		}
		if(op[1]=='G'){
			p=read(),t=read();
			write(tree[gettree(p,t)].sum),putchar(10);
		}
		if(op[1]=='M'&&op[3]=='X')write(tree[rt].mx),putchar(10);
	}
	return 0;
}

