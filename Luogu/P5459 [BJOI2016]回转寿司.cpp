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
#define t tree[id]
#define tl tree[l]
#define tr tree[r]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,L,R,a[N],sum[N],rt,cnt,ans;
struct node{int l,r,v,ky,sz;
node(int l=0,int r=0,int v=0,int ky=0,int sz=0):l(l),r(r),v(v),ky(ky),sz(sz){}}tree[N];
inline void update(int id){t.sz=tree[t.l].sz+tree[t.r].sz+1;return;}

void split(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(t.v<=x){l=id,split(t.r,x,t.r,r);}
	else r=id,split(t.l,x,l,t.l);
	update(id);return;
}

int merge(int l,int r){
	if(!l||!r)return l^r;
	if(tl.ky>=tr.ky){tl.r=merge(tl.r,r),update(l);return l;}
	tr.l=merge(l,tr.l),update(r);return r;
}

int kth(int id,int k){
	if(tree[t.l].sz<=k)return kth(t.l,k);
	if(tree[t.l].sz>k+1)return kth(t.r,k-tree[t.l].sz-1);
	return id;
}

signed main(){
	srand(time(0));
	n=read(),L=read(),R=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=n;i>=1;i--)sum[i]=sum[i+1]+a[i];
	for(int i=1,l,r,m;i<=n+1;i++){
		split(rt,L+sum[i]-1,l,r),split(r,R+sum[i],m,r);
		ans+=tree[m].sz;
		rt=merge(merge(l,m),r);
		split(rt,sum[i],l,r),tree[++cnt]=node(0,0,sum[i],rand(),1);
		rt=merge(merge(l,cnt),r);
	}
	printf("%lld\n",ans);
	return 0;
}
