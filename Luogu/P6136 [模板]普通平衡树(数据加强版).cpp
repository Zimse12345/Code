/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define yes printf("Yes\n")
#define no printf("No\n")
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
#define t tree[id]
#define tl tree[l]
#define tr tree[r]

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=2000007;

int n,m,rt,cnt,ans;
struct fhq{int l,r,v,ky,siz;
fhq(int l=0,int r=0,int v=0,int ky=0,int siz=0):l(l),r(r),v(v),ky(ky),siz(siz){}}tree[N];
void update(int id){t.siz=tree[t.l].siz+tree[t.r].siz+1;return;}

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

int kth(int id,int k){
	if(k<=tree[t.l].siz)return kth(t.l,k);
	if(k>tree[t.l].siz+1)return kth(t.r,k-tree[t.l].siz-1);
	return id;
}

int main(){
	srand(time(0));
	n=read(),m=read();
	while(n--){
	    int x=read(),l,r;
	    split(rt,x,l,r),tree[++cnt]=fhq(0,0,x,rand(),1),rt=merge(merge(l,cnt),r);
	}
	for(int i=1,p,op,x,lst=0;i<=m;i++){
		op=read(),x=read()^lst;
		int l,r;
		if(op==1)split(rt,x,l,r),tree[++cnt]=fhq(0,0,x,rand(),1),rt=merge(merge(l,cnt),r);
		if(op==2)split(rt,x,l,r),split(l,x-1,l,p),rt=merge(merge(l,tree[p].l),merge(tree[p].r,r));
		if(op==3)split(rt,x-1,l,r),lst=tl.siz+1,rt=merge(l,r);
		if(op==4)lst=tree[kth(rt,x)].v;
		if(op==5)split(rt,x-1,l,r),lst=tree[kth(l,tl.siz)].v,rt=merge(l,r);
		if(op==6)split(rt,x,l,r),lst=tree[kth(r,1)].v,rt=merge(l,r);
		if(op>2)ans^=lst;
	}
	printf("%d\n",ans);
	return 0;
}
