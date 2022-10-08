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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,rt,cnt;
ll ans;
struct fhq{int l,r,v,ky,siz;
fhq(int l=0,int r=0,int v=0,int ky=0,int siz=0):l(l),r(r),v(v),ky(ky),siz(siz){}}tree[N];
void update(int id){t.siz=tree[t.l].siz+tree[t.r].siz+1;return;}

void split(int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(t.v<=x)l=id,split(t.r,x,t.r,r);
	if(t.v>x)r=id,split(t.l,x,l,t.l);
	update(id);return;
}

int merge(int l,int r){
	if(!l||!r)return l+r;
	if(tl.ky>=tr.ky){tl.r=merge(tl.r,r),update(l);return l;}
	tr.l=merge(l,tr.l),update(r);return r;
}

int kth(int id,int k){
	if(k<=tree[t.l].siz)return kth(t.l,k);
	if(k>tree[t.l].siz+1)return kth(t.r,k-tree[t.l].siz-1);
	return id;
}

void Insert(int x){
	int l,r;
	split(rt,x,l,r),tree[++cnt]=fhq(0,0,x,rand(),1),rt=merge(l,merge(cnt,r));
	return;
}

int main(){
	srand(time(0));
	n=read(),m=read();
	Insert(0);
	for(int i=1,v,s=0,l,r;i<=n;i++){
		v=read()-m,s+=v;
		split(rt,s,l,r),ans+=tree[l].siz,rt=merge(l,r);
		Insert(s);
	}
	printf("%lld\n",ans);
	return 0;
}
