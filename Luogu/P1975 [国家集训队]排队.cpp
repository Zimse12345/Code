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
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=2e6+7,Mod=998244353,INF=2147483647;
int n,m,a[N],cnt,Rt[N],ans;
struct node{int l,r,v,ky,sz;
node(int l=0,int r=0,int v=0,int ky=0,int sz=0):l(l),r(r),v(v),ky(ky),sz(sz){}}tree[N];
inline void update(int id){t.sz=tree[t.l].sz+tree[t.r].sz+1;return;}

void split(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(t.v<=x)l=id,split(t.r,x,t.r,r);
	else r=id,split(t.l,x,l,t.l);
	update(id);return;
}

int merge(int l,int r){
	if(!l||!r)return l^r;
	if(tl.ky>=tr.ky){tl.r=merge(tl.r,r),update(l);return l;}
	tr.l=merge(l,tr.l),update(r);return r;
}

int kth(int id,int k){
	if(k<=tree[t.l].sz)return kth(t.l,k);
	if(k>tree[t.l].sz+1)return kth(t.r,k-tree[t.l].sz-1);
	return id;
}

inline void Insert(int& rt,int x){
	int l,r;
	split(rt,x,l,r),tree[++cnt]=node(0,0,x,rand(),1),rt=merge(l,merge(cnt,r));
	return;
}

inline void Erase(int& rt,int x){
	int l,r,m;
	split(rt,x,l,r),split(l,x-1,l,m),rt=merge(merge(l,tree[m].l),merge(tree[m].r,r));
	return;
}

inline int Rank(int& rt,int x){
	int l,r,res;
	split(rt,x-1,l,r),res=tree[l].sz-1,rt=merge(l,r);
	return res;
}

void build(int L,int R,int id){
	Rt[id]=++cnt,tree[cnt]=node(0,0,a[L],rand(),1);
	for(int i=L+1;i<=R;i++)Insert(Rt[id],a[i]);
	if(L!=R){
		int M=(L+R)>>1;
		build(L,M,Lid),build(M+1,R,Rid);
	}
	return;
}

void change(int L,int R,int id,int p,int k){
	Erase(Rt[id],a[p]),Insert(Rt[id],k);
	if(L!=R){
		int M=(L+R)>>1;
		if(p<=M)change(L,M,Lid,p,k);
		else change(M+1,R,Rid,p,k);
	}
	return; 
}

inline int q1(int& rt,int x){
	int l,r,res;
	split(rt,x-1,l,r),res=tree[l].sz,rt=merge(l,r);
	return res;
}

inline int q2(int& rt,int x){
	int l,r,res;
	split(rt,x,l,r),res=tree[r].sz,rt=merge(l,r);
	return res;
}

int Query1(int L,int R,int id,int l,int r,int k){
	if(r<L||l>R)return 0;
	if(l<=L&&r>=R)return q1(Rt[id],k);
	return Query1(L,(L+R)/2,Lid,l,r,k)+Query1((L+R)/2+1,R,Rid,l,r,k);
}

int Query2(int L,int R,int id,int l,int r,int k){
	if(r<L||l>R)return 0;
	if(l<=L&&r>=R)return q2(Rt[id],k);
	return Query2(L,(L+R)/2,Lid,l,r,k)+Query2((L+R)/2+1,R,Rid,l,r,k);
}

int main(){
	srand(time(0));
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=read();
	build(1,n,1);
	for(int i=2;i<=n;i++)ans+=Query2(1,n,1,1,i-1,a[i]);
	printf("%d\n",ans);
	for(int i=1,l,r;i<=m;i++){
		l=read(),r=read();
		if(l>r)swap(l,r);
		if(l!=r-1){
			int s1=Query1(1,n,1,l+1,r-1,a[r]),s2=Query2(1,n,1,l+1,r-1,a[l]);
			int c1=Query2(1,n,1,l+1,r-1,a[r]),c2=Query1(1,n,1,l+1,r-1,a[l]);
			ans=ans+s1-c1+s2-c2;
		}
		change(1,n,1,l,a[r]),change(1,n,1,r,a[l]);
		if(a[l]<a[r])++ans;
		else if(a[l]>a[r])--ans;
		swap(a[l],a[r]);
		printf("%d\n",ans);
	}
	return 0;
}

