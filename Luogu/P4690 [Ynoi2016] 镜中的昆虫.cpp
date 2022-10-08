/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-08
*Description:
*Other:
********************************/

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

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define ll long long
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

const int Mod=998244353;//1000000007;
namespace Zimse{
inline int read(){int x=0,y=1;char c=gc();while(c<48||c>57){if(c==45)y=-1;c=gc();}while(c>=48&&c<=57)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;

const int N=1e5+7;
const int INF=1000114514;

int n,m,a[N],ql[N],qr[N],qx[N*2],Val[N*2],vt,Vt;
int Lpos[N],Rpos[N],Nxt[N],Pre[N];
int ans[N],cnt;

struct block{
	int l,r,val,t;
	block(int l=0,int r=0,int val=0,int t=0):l(l),r(r),val(val),t(t){}
	bool operator < (const block& _)const{return l<_.l;}
};
set<block> s;
set<int> pos[N*2];
map<int,int> mp;

struct point{
	int x,_x,y,v,id;
	point(int x=0,int _x=0,int y=0,int v=0,int id=0):x(x),_x(_x),y(y),v(v),id(id){}
}P[N*10];

inline bool cmp_y(const point& A,const point& B){return A.y<B.y;}

inline void add(int l,int r,int pre,int t,int v){
	P[++cnt]=point(l,r,pre,v,0);
	return;
}

inline void Add(int l,int r,int val,int t){
	Rpos[l]=r,Lpos[r]=l;
	set<int>::iterator it=pos[val].lower_bound(l);
	int q=Lpos[*it];
	--it;
	int p=*it;
	pos[val].insert(r);
	add(l,r,p,t,1);
	if(q){
		add(q,Rpos[q],Pre[q],t,-1);
		Nxt[r]=q,Pre[q]=r;
		add(q,Rpos[q],Pre[q],t,1);
	}
	else Nxt[r]=0;
	if(p)Nxt[p]=l;
	Pre[l]=p;
	return;
}

inline void Del(int l,int r,int val,int t){
	set<int>::iterator it=pos[val].upper_bound(r);
	int q=Lpos[*it];
	--it,--it;
	int p=*it;
	pos[val].erase(r);
	add(l,r,p,t,-1);
	if(q){
		add(q,Rpos[q],Pre[q],t,-1);
		Pre[q]=p;
		add(q,Rpos[q],Pre[q],t,1);
	}
	if(p)Nxt[p]=q;
	return;
}

struct treearray{
	int sum[N];
	inline void ub(int& x){x+=(x&(-x));return;}
	inline void db(int& x){x-=(x&(-x));return;}
	inline void ad(int x,int v){++x;for(;x<N;ub(x))sum[x]+=v;return;}
	inline int qsum(int x){++x;int res=0;for(;x;db(x))res+=sum[x];return res;}
}t1,t2;

void sol(int L,int R){
	if(R<=L)return;
	int M=(L+R)/2;
	sol(L,M),sol(M+1,R);
	int t=L;
	for(int i=M+1;i<=R;i++)if(P[i].id){
		while(t<=M&&(P[t].id||P[t].y<=P[i].y)){
			if(!P[t].id)t1.ad(P[t].x,P[t].v),t2.ad(P[t]._x,P[t].v);
			++t;
		}
		if(P[i].v==1)ans[P[i].id]+=t1.qsum(P[i].x);
		else ans[P[i].id]-=t2.qsum(P[i].x);
	}
	for(int i=L;i<t;i++)if(!P[i].id)t1.ad(P[i].x,-P[i].v),t2.ad(P[i]._x,-P[i].v);
	sort(P+L,P+R+1,cmp_y);
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),Val[++vt]=a[i];
	for(int i=1,op;i<=m;i++){
		op=read(),ql[i]=read(),qr[i]=read();
		if(op==1)qx[i]=read(),Val[++vt]=qx[i];
	}
	sort(Val+1,Val+vt+1);
	for(int i=1;i<=vt;i++)if(Val[i]!=Val[i-1])Val[++Vt]=Val[i],mp[Val[i]]=Vt;
	for(int i=1;i<=n;i++)a[i]=mp[a[i]];
	for(int i=1;i<=m;i++)if(qx[i])qx[i]=mp[qx[i]];
	for(int i=1;i<=Vt;i++)pos[i].insert(0),pos[i].insert(n+1);
	for(int l=1,r;l<=n;){
		r=l;
		while(a[r+1]==a[l])++r;
		s.emplace(l,r,a[l],0);
		Add(l,r,a[l],0);
		l=r+1;
	}
	s.emplace(n+1,n+1,0,0);
	
	for(int i=1,l,r,x;i<=m;i++){
		l=ql[i],r=qr[i],x=qx[i];
		if(x){
			set<block>::iterator L=s.upper_bound(block(l,0,0,0));
			set<block>::iterator R=s.upper_bound(block(r,0,0,0));
			--L,--R;
			block lb=*L,rb=*R;
			++R;
			for(set<block>::iterator it=L;it!=R;it++)Del(it->l,it->r,it->val,i);
			s.erase(L,R);
			lb.r=l-1,rb.l=r+1,lb.t=rb.t=i;
			if(lb.l<=lb.r)s.insert(lb),Add(lb.l,lb.r,lb.val,i);
			if(rb.l<=rb.r)s.insert(rb),Add(rb.l,rb.r,rb.val,i);
			s.emplace(l,r,x,i);
			Add(l,r,x,i);
		}
		else{
			P[++cnt]=point(qr[i],0,ql[i]-1,1,i);
			P[++cnt]=point(ql[i]-1,0,ql[i]-1,-1,i);
		}
	}
	sol(1,cnt);
	for(int i=1;i<=m;i++)if(!qx[i])_write(ans[i]);
	return 0;
}

