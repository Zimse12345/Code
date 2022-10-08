#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
#include <cctype>

#define int unsigned long long
#define t tr[id]
#define _t tr[_id]
//#define M ((L+R)>>1)
//#define (id<<1) (id<<1)
//#define ((id<<1)|1) ((id<<1)|1)

using namespace std;

const int MB=1<<20;
struct FastIO{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	char read_char(){
		if(p==q){
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename T>
	void read_int(T& x){
		char c=read_char(),l=0;
		for(x=0;!isdigit(c);c=read_char())l=c;
		for(;isdigit(c);c=read_char())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void write_char(char c){
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename T>
	void write_int(T x){
		if(x<0)write_char('-'),x=-x;
		do stk[++tp]=x%10+'0';
		while(x/=10);
		while(tp)write_char(stk[tp--]);
	}
}IO;

const unsigned N=1e5+7;
unsigned n,q;
int a[N];

struct segmenttree{
struct node{int his,sum;signed lt,tagL,tagR;int tagh,tagv;bool tag;}tr[N*4];

inline void mergetag(unsigned id,unsigned _id){
	if(!_t.tag){
		_t.tag=1,_t.tagL=t.tagL,_t.tagR=t.tagR,_t.tagh=t.tagh,_t.tagv=t.tagv;
		return;
	}
	_t.tagh+=(t.tagL-_t.tagR)*_t.tagv+t.tagh;
	_t.tagR=t.tagR,_t.tagv=t.tagv;
	return;
}

inline void pushdown(unsigned id,signed T,signed len){
	if(!t.tag){
		t.his+=t.sum*(T-t.lt),t.lt=T;
		return;
	}
	if(len!=1)mergetag(id,(id<<1)),mergetag(id,((id<<1)|1));
	t.his=t.his+t.sum*(t.tagL-t.lt-1)+t.tagh*len+t.tagv*(T-t.tagR+1)*len;
	t.sum=t.tagv*len,t.lt=T,t.tag=0;
	return;
}

inline void update(unsigned L,unsigned R,unsigned id,unsigned l,unsigned r,signed x,signed T){
	pushdown(id,T-1,R-L+1);
	if(l<=L&&r>=R){
		t.tag=1,t.tagv=x,t.tagh=0,t.tagL=t.tagR=T;
		pushdown(id,T-1,R-L+1);
	}
	else{
		if(l<=((L+R)>>1))update(L,((L+R)>>1),(id<<1),l,r,x,T);
		else pushdown(id<<1,T-1,((L+R)>>1)-L+1);
		if(r>((L+R)>>1))update(((L+R)>>1)+1,R,((id<<1)|1),l,r,x,T);
		else pushdown((id<<1)|1,T-1,R-((L+R)>>1));
		t.his=tr[(id<<1)].his+tr[((id<<1)|1)].his,t.sum=tr[(id<<1)].sum+tr[((id<<1)|1)].sum;
	}
	return;
}

inline int query(unsigned L,unsigned R,unsigned id,unsigned l,unsigned r,signed T){
	pushdown(id,T,R-L+1);
	if(l<=L&&r>=R)return t.his;
	if(r<=((L+R)>>1))return query(L,((L+R)>>1),(id<<1),l,r,T);
	if(l>((L+R)>>1))return query(((L+R)>>1)+1,R,((id<<1)|1),l,r,T);
	return query(L,((L+R)>>1),(id<<1),l,r,T)+query(((L+R)>>1)+1,R,((id<<1)|1),l,r,T);
}
}tree[5];
/*
struct duanTree{
signed ch[N*4][2],mx[N*4];

inline void build(signed L,signed R,signed id){
	if(L==R)mx[id]=a[L];
	else{
		build(L,M,(id<<1)),build(M+1,R,((id<<1)|1));
		mx[id]=max(mx[(id<<1)],mx[((id<<1)|1)]);
	}
	return;
}

inline signed qmaxL(signed L,signed R,signed id,signed l,signed r,signed x){
	if(r<L||R<l||mx[id]<x)return 0;
	if(L==R)return L;
	int ql=qmaxL(L,M,(id<<1),l,r,x);
	return ql?ql:qmaxL(M+1,R,((id<<1)|1),l,r,x);
}

inline signed qmaxR(signed L,signed R,signed id,signed l,signed r,signed x){
	if(r<L||R<l||mx[id]<x)return 0;
	if(L==R)return L;
	int qr=qmaxR(M+1,R,((id<<1)|1),l,r,x);
	return qr?qr:qmaxR(L,M,(id<<1),l,r,x);
}
};
*/
unsigned maxL[18][N],maxR[18][N];

inline unsigned qL(signed pos,unsigned x){
	if(maxL[17][pos]<x)return 0;
	if(maxL[16][pos]<x)pos-=65536;
    if(maxL[15][pos]<x)pos-=32768;
    if(maxL[14][pos]<x)pos-=16384;
    if(maxL[13][pos]<x)pos-=8192;
    if(maxL[12][pos]<x)pos-=4096;
    if(maxL[11][pos]<x)pos-=2048;
    if(maxL[10][pos]<x)pos-=1024;
    if(maxL[9][pos]<x)pos-=512;
    if(maxL[8][pos]<x)pos-=256;
    if(maxL[7][pos]<x)pos-=128;
    if(maxL[6][pos]<x)pos-=64;
    if(maxL[5][pos]<x)pos-=32;
    if(maxL[4][pos]<x)pos-=16;
    if(maxL[3][pos]<x)pos-=8;
    if(maxL[2][pos]<x)pos-=4;
    if(maxL[1][pos]<x)pos-=2;
    if(maxL[0][pos]<x)pos-=1;
	return pos;
}

inline unsigned qR(signed pos,unsigned x){
	if(maxR[17][pos]<x)return 0;
	if(maxR[16][pos]<x)pos+=65536;
    if(maxR[15][pos]<x)pos+=32768;
    if(maxR[14][pos]<x)pos+=16384;
    if(maxR[13][pos]<x)pos+=8192;
    if(maxR[12][pos]<x)pos+=4096;
    if(maxR[11][pos]<x)pos+=2048;
    if(maxR[10][pos]<x)pos+=1024;
    if(maxR[9][pos]<x)pos+=512;
    if(maxR[8][pos]<x)pos+=256;
    if(maxR[7][pos]<x)pos+=128;
    if(maxR[6][pos]<x)pos+=64;
    if(maxR[5][pos]<x)pos+=32;
    if(maxR[4][pos]<x)pos+=16;
    if(maxR[3][pos]<x)pos+=8;
    if(maxR[2][pos]<x)pos+=4;
    if(maxR[1][pos]<x)pos+=2;
    if(maxR[0][pos]<x)pos+=1;
	return pos;
}

struct line{
	unsigned l,r;signed v;unsigned k;
	line(unsigned l=0,unsigned r=0,signed v=0,unsigned k=0):l(l),r(r),v(v),k(k){}
};
vector<line> p[N][5];
vector<line> Q[N];
int ans[N];
unsigned lm[7],rm[7],ls,rs;

signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.ans","w",stdout);
	IO.read_int(n),IO.read_int(q);
	for(unsigned i=1;i<=n;i++)IO.read_int(a[i]),maxL[0][i]=maxR[0][i]=a[i];
	for(unsigned i=1;i<18;i++){
		for(signed j=1;j<=signed(n);j++){
			maxL[i][j]=maxL[i-1][j],maxR[i][j]=maxR[i-1][j];
			if(j-(1<<(i-1))>0)maxL[i][j]=max(maxL[i][j],maxL[i-1][j-(1<<(i-1))]);
			if(j+(1<<(i-1))<=signed(n))maxR[i][j]=max(maxR[i][j],maxR[i-1][j+(1<<(i-1))]);
		}
	}
//	printf("1");
//	dt.build(1,n,1);
	for(unsigned i=1,L,R;i<=n;i++){
		ls=rs=1,lm[0]=rm[0]=i,L=qL(i-1,a[i]),R=qR(i+1,a[i]);
//		printf("(%d %d)\n",i,L);
//		dt.qmaxR(1,n,1,1,i-1,a[i])
		while(L&&ls<6)lm[ls++]=L,L=qL(L-1,a[i]);
		while(R&&rs<6)rm[rs++]=R,R=qR(R+1,a[i]);
		lm[ls]=0;
		for(unsigned k=0;k<5;k++){
			for(unsigned l=0,r;l<=k;l++){
				r=k-l;
				if(l>=ls||r>=rs)continue;
				p[rm[r]][k].push_back(line(lm[l+1]+1,lm[l],a[i],0));
			}
		}
	}
//	printf("2");
	for(unsigned i=1,l,r,k;i<=q;i++){
		IO.read_int(l),IO.read_int(r),IO.read_int(k);
		Q[l-1].push_back(line(l,r,-i,k-1)),Q[r].push_back(line(l,r,i,k-1));
	}
	for(unsigned i=1,sz;i<=n;i++){
		for(unsigned k=0;k<5;k++){
			sz=p[i][k].size();
			for(unsigned j=0;j<sz;j++)tree[k].update(1,n,1,p[i][k][j].l,p[i][k][j].r,p[i][k][j].v,i);
		}
		sz=Q[i].size();
		for(unsigned j=0;j<sz;j++){
			signed id=Q[i][j].v;
			if(id>0)ans[id]+=tree[Q[i][j].k].query(1,n,1,Q[i][j].l,Q[i][j].r,i);
			else ans[-id]-=tree[Q[i][j].k].query(1,n,1,Q[i][j].l,Q[i][j].r,i);
		}
	}
//	printf("3\n");
	for(unsigned i=1;i<=q;i++)IO.write_int(ans[i]),IO.write_char('\n');
	return 0;
}

