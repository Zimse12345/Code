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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,rt,cnt;
struct node{
	int l,r,v,ky,siz;
	node(int l=0,int r=0,int v=0,int ky=0,int siz=0):l(l),r(r),v(v),ky(ky),siz(siz){}
}tree[N];
void update(int id){tree[id].siz=tree[tree[id].l].siz+tree[tree[id].r].siz+1;}

void split(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(tree[id].v<=x)l=id,split(tree[id].r,x,tree[id].r,r);
	if(tree[id].v>x)r=id,split(tree[id].l,x,l,tree[id].l);
	update(id);return;
}

int merge(int l,int r){
	if(l==0||r==0)return l+r;
	if(tree[l].ky<=tree[r].ky){tree[l].r=merge(tree[l].r,r),update(l);return l;};
	tree[r].l=merge(l,tree[r].l),update(r);return r;
}

int kth(int id,int k){
	if(k<=tree[tree[id].l].siz)return kth(tree[id].l,k);
	if(k>tree[tree[id].l].siz+1)return kth(tree[id].r,k-tree[tree[id].l].siz-1);
	return id;
}

int main(){
	srand(time(0));
	n=read();
	for(int i=1,l,r,p,op,x;i<=n;i++){
		op=read(),x=read();
		if(op==1)split(rt,x,l,r),tree[++cnt]=node(0,0,x,rand(),1),rt=merge(l,merge(cnt,r));
		if(op==2)split(rt,x,l,r),split(l,x-1,l,p),p=merge(tree[p].l,tree[p].r),rt=merge(l,merge(p,r));
		if(op==3)split(rt,x-1,l,r),printf("%d\n",tree[l].siz+1),rt=merge(l,r);
		if(op==4)printf("%d\n",tree[kth(rt,x)].v);
		if(op==5)split(rt,x-1,l,r),printf("%d\n",tree[kth(l,tree[l].siz)].v),rt=merge(l,r);
		if(op==6)split(rt,x,l,r),printf("%d\n",tree[kth(r,1)].v),rt=merge(l,r);
	}
	return 0;
}
