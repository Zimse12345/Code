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

#define t tree[id]
#define tl tree[l]
#define tr tree[r]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,m,rt,cnt;
struct fhq{int l,r,v,ky,siz,tag;
fhq(int l=0,int r=0,int v=0,int ky=0,int siz=0,int tag=0):l(l),r(r),v(v),ky(ky),siz(siz),tag(tag){}}tree[N];
void update(int id){t.siz=tree[t.l].siz+tree[t.r].siz+1;return;}
void pushdown(int id){if(t.tag){T=t.l,t.l=t.r,t.r=T,tree[t.l].tag^=1,tree[t.r].tag^=1,t.tag=0;}return;}

void split(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	pushdown(id);
	if(tree[t.l].siz+1<=x)l=id,split(t.r,x-tree[t.l].siz-1,t.r,r);
	else r=id,split(t.l,x,l,t.l);
	update(id);return;
}

int merge(int l,int r){
	if(!l||!r)return l+r;
	pushdown(l),pushdown(r);
	if(tl.ky<tr.ky){tl.r=merge(tl.r,r),update(l);return l;}
	tr.l=merge(l,tr.l),update(r);return r;
}

void print(int id){
	if(!id)return;
	pushdown(id);
	print(t.l),printf("%d ",tree[id].v),print(t.r);
	return;
}

int main(){
	srand(time(0));
	n=read(),m=read();
	for(int i=1;i<=n;i++)tree[++cnt]=fhq(0,0,i,rand(),1,0),rt=merge(rt,cnt);
	for(int i=1,x,y,l,r,p;i<=m;i++){
		x=read(),y=read();
		split(rt,y,l,r);
		split(l,x-1,l,p);
		tree[p].tag^=1;
		rt=merge(l,merge(p,r));
	}
	print(rt);
	printf("\n");
	return 0;
}
