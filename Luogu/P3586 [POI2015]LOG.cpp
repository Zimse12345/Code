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

const int N=1e6+7,Mod=1e9+7,INF=1e12+7;
struct node{int l,r,v,ky,sz,sum;node(int l=0,int r=0,int v=0,int ky=0,int sz=0,int sum=0):l(l),r(r),v(v),ky(ky),sz(sz),sum(sum){};}tree[N];
void update(int id){t.sz=tree[t.l].sz+tree[t.r].sz+1,t.sum=tree[t.l].sum+tree[t.r].sum+t.v;return;}
int n,m,a[N],vis[N],rt,tot;
char op;

void split(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(t.v<=x)l=id,split(t.r,x,t.r,r);
	else r=id,split(t.l,x,l,t.l);
	update(id);return;
}

int merge(int l,int r){
	if(!l||!r)return l^r;
	if(tl.ky>tr.ky){tl.r=merge(tl.r,r),update(l);return l;} 
	tr.l=merge(l,tr.l),update(r);return r;
}

signed main(){
	srand(time(0));
	n=read(),m=read();
	int x,y,l,r,p;
	while(m--){
		do{op=getchar();}while(op!='U'&&op!='Z');
		x=read(),y=read();
		if(op=='U'){
			if(vis[x]++)split(rt,a[x],l,r),split(l,a[x]-1,l,p),rt=merge(merge(l,tree[p].l),merge(tree[p].r,r));
			split(rt,y,l,r),tree[++tot]=node(0,0,y,rand(),1,y),rt=merge(merge(l,tot),r),a[x]=y;
		}
		else{
			split(rt,y,l,r);
			if(tl.sum+tr.sz*y>=x*y)putchar('T'),putchar('A'),putchar('K'),putchar('\n');
			else putchar('N'),putchar('I'),putchar('E'),putchar('\n');
			rt=merge(l,r);
		}
	}
	return 0;
}

