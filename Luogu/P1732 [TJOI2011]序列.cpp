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
int T,n,a[N],rt,cnt,c[N];
ll ans;
struct node{int l,r,v,ky,siz;
node(int l=0,int r=0,int v=0,int ky=0,int siz=0):l(l),r(r),v(v),ky(ky),siz(siz){}}tree[N];
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

void Insert(int v){
	int l,r;
	split(rt,v,l,r),tree[++cnt]=node(0,0,v,rand(),1),rt=merge(l,merge(cnt,r));
	return;
}

int pre(int v){
	int l,r,res;
	split(rt,v-1,l,r),res=tree[kth(l,tl.siz)].v,rt=merge(l,r);
	return res;
}

int nxt(int v){
	int l,r,res;
	split(rt,v,l,r),res=tree[kth(r,1)].v,rt=merge(l,r);
	return res;
}

int main(){
	T=read();
	while(T--){
		n=read(),rt=cnt=0,ans=0;
		for(int i=0;i<=65536;i++)c[i]=0;
		Insert(-INF),Insert(INF);
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(i==1)ans+=a[1],Insert(a[1]),c[a[1]]=1; 
			else if(!c[a[i]]){
				int L=pre(a[i]),R=nxt(a[i]);
				ans+=min(a[i]-L,R-a[i]);
				Insert(a[i]),c[a[i]]=1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
