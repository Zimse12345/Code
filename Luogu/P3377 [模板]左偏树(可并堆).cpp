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
#define tl tree[l]
#define tr tree[r]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,INF=1e9+7;
struct vl{int v,id;
vl(int v=0,int id=0):v(v),id(id){}bool operator < (const vl& A)const{
if(v==A.v)return id<A.id;return v<A.v;}};
struct node{int l,r,dist;vl v;
node(int l=0,int r=0,vl v=vl(0,0),int dist=0):l(l),r(r),v(v),dist(dist){}}tree[N];
int n,m,a[N],fa[N],cnt[N],Rt[N],vis[N];

int F(int x){
	if(fa[x]!=x)fa[x]=F(fa[x]);
	return fa[x];
}

int merge(int l,int r){
	if(!l||!r)return l^r;
	if(tr.v<tl.v)swap(l,r);
	tl.r=merge(tl.r,r);
	if(tree[tl.l].dist<tree[tl.r].dist)swap(tl.l,tl.r);
	tl.dist=tree[tl.r].dist+1;
	return l;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),fa[i]=Rt[i]=i,cnt[i]=1,tree[i]=node(0,0,vl(a[i],i),1);
	for(int i=1,op,x,y;i<=m;i++){
		op=read(),x=read();
		if(op==1){
			y=read();
			if(vis[x]||vis[y])continue;
			int A=F(x),B=F(y);
			if(A!=B){
				if(cnt[B]>cnt[A])swap(A,B);
				Rt[A]=merge(Rt[A],Rt[B]);
				fa[B]=A,cnt[A]+=cnt[B];
			}
		}
		else{
			if(vis[x])printf("-1\n");
			else{
				x=F(x);
				vl A=tree[Rt[x]].v;
				vis[A.id]=1,printf("%d\n",A.v);
				Rt[x]=merge(tree[Rt[x]].l,tree[Rt[x]].r);
			}
		}
	}
	return 0;
}
