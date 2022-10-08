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
#define t tree[id]
#define tl tree[l]
#define tr tree[r]
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],rt,cnt,Rt[N],Id[N];
struct node{int l,r,v,ky,sz,fa;node(int l=0,int r=0,int v=0,int ky=0,int sz=0,int fa=0):l(l),r(r),v(v),ky(ky),sz(sz),fa(fa){}}tree[N*2];
inline void update(int id){t.sz=tree[t.l].sz+tree[t.r].sz+1;if(t.l)tree[t.l].fa=id;if(t.r)tree[t.r].fa=id;return;}

void split_size(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(tree[t.l].sz<x)l=id,tree[t.r].fa=0,split_size(t.r,x-tree[t.l].sz-1,t.r,r);
	else r=id,tree[t.l].fa=0,split_size(t.l,x,l,t.l);
	update(id);return;
}

int merge(int l,int r){
	if(!l||!r)return l^r;
	if(tl.ky<tr.ky){tl.r=merge(tl.r,r),update(l);return l;}
	tr.l=merge(l,tr.l),update(r);return r;
}

int kth(int id,int k){
	if(k<=tree[t.l].sz)return kth(t.l,k);
	if(tree[t.l].sz+1<k)return kth(t.r,k-tree[t.l].sz-1);
	return id;
}

void ins(int& id,int v){
	tree[++cnt]=node(0,0,v,rand(),1,0),id=merge(id,cnt);
	return;
}

int pos(int id){
	int res=tree[t.l].sz+1,fa;
	while(tree[id].fa){
		fa=tree[id].fa;
		if(tree[fa].r==id)res+=tree[tree[fa].l].sz+1;
		id=fa;
	}
	return res;
}

signed main(){
	srand(time(0));
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),ins(rt,i),Id[i]=cnt,ins(Rt[a[i]],i);
	m=read();
	for(int i=1,op,l,r,x,ans=0;i<=m;i++){
		op=read(),l=(read()+ans-1)%n+1,r=(read()+ans-1)%n+1;
		if(r<l)swap(l,r);
		if(op==1){
			int p1,p2,p3,p4;
			split_size(rt,l-1,p1,p2),split_size(p2,r-l,p2,p3),split_size(p3,1,p3,p4);
			int c=a[tree[p3].v];
			rt=merge(merge(p1,p2),merge(p3,p4));
			int L=1,R=tree[Rt[c]].sz,u=0,v=0;
			while(L<=R){
				int p=pos(Id[tree[kth(Rt[c],M)].v]);
				if(p<r)L=M+1;
				else if(p>r)R=M-1;
				else{u=M;break;}
			}
			L=1,R=tree[Rt[c]].sz;
			while(L<=R){
				int p=pos(Id[tree[kth(Rt[c],M)].v]);
				if(p<l)v=M,L=M+1;
				else R=M-1;
			}
			split_size(Rt[c],v,p1,p2),split_size(p2,u-v-1,p2,p3),split_size(p3,1,p3,p4);
			Rt[c]=merge(merge(p1,p3),merge(p2,p4));
			split_size(rt,l-1,p1,p2),split_size(p2,r-l,p2,p3),split_size(p3,1,p3,p4);
			rt=merge(merge(p1,p3),merge(p2,p4));
		}
		else{
			x=(read()+ans-1)%n+1;
			int L=1,R=tree[Rt[x]].sz,u=0,v=-1;
			while(L<=R){
				int p=pos(Id[tree[kth(Rt[x],M)].v]);
				if(l<=p)u=M,R=M-1;
				else L=M+1;
			}
			L=1,R=tree[Rt[x]].sz;
			while(L<=R){
				int p=pos(Id[tree[kth(Rt[x],M)].v]);
				if(p<=r)v=M,L=M+1;
				else R=M-1;
			}
			ans=max(0,v-u+1);
			if(u==0||v==0)ans=0;
			printf("%d\n",ans);
		}
	}
	return 0;
}

