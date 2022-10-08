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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e5+7,Mod=998244353,INF=1e9+7;
int n,q,sta[N],ans[N],pt,tr[N];
bool trr[N],cnt[N];
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}bool operator < (const node& A)const{return x<A.x;}};
struct nd{int x,y,z,w;nd(int x=0,int y=0,int z=0,int w=0):x(x),y(y),z(z),w(w){}}p[N*16];
char s[N];
set<node> seg;

inline bool cmp_x(const nd& A,const nd& B){if(A.x==B.x){if(A.y==B.y){int az=A.z,bz=B.z;if(az==-1)az=A.w;if(bz==-1)bz=B.w;return az<bz;}return A.y<B.y;}return A.x<B.x;}
inline bool cmp_y(const nd& A,const nd& B){return A.y<B.y;}
inline void db(int& x){x-=(x&(-x));return;}
inline void ub(int& x){x+=(x&(-x));return;}
inline void add(int x,int t){++x;for(;x<N;ub(x))tr[x]+=t;return;}
inline int sum(int x){++x;int res=0;for(;x;db(x))res+=tr[x];return res;}
inline void addd(int x){++x;for(;x<N;ub(x))trr[x]^=1;return;}
inline bool summ(int x){++x;bool res=0;for(;x;db(x))res^=trr[x];return res;}

inline void calc(node l,node r,int z,int w){
	p[++pt]=nd(l.x,r.x,z,w),p[++pt]=nd(l.y+1,r.x,z,-w),p[++pt]=nd(l.x,r.y+1,z,-w),p[++pt]=nd(l.y+1,r.y+1,z,w);
	return;
}

inline void link(int x,int t){
	set<node>::iterator l=seg.upper_bound(node(x,x)),r;
	r=l,--l;node m=node((*l).x,(*r).y);
	calc(*l,*r,t,q-t),seg.erase(l),seg.erase(r),seg.insert(m);
	return;
}

inline void cut(int x,int t){
	set<node>::iterator m=seg.upper_bound(node(x,x));
	--m;node l=node((*m).x,x),r=node(x+1,(*m).y);
	calc(l,r,t,t-q),seg.erase(m),seg.insert(l),seg.insert(r);
	return;
}

inline void cdq(int L,int R){
	if(L==R)return;
	int M=(L+R)>>1;
	cdq(L,M),cdq(M+1,R);
	sort(p+L,p+M+1,cmp_y),sort(p+M+1,p+R+1,cmp_y);
	int j=L;
	for(int i=M+1;i<=R;i++){
		while(j<=M&&p[j].y<=p[i].y){
			if(p[j].z!=-1)add(p[j].z,p[j].w),addd(p[j].z);
			++j;
		}
		if(p[i].z==-1)ans[p[i].w]+=sum(p[i].w),cnt[p[i].w]^=summ(p[i].w);
	}
	for(int i=L;i<j;i++)if(p[i].z!=-1)add(p[i].z,-p[i].w),addd(p[i].z);
	return;
}

signed main(){
	n=read(),q=read();
	scanf("%s",s+1);
	for(int i=1;i<=n+1;i++)seg.insert(node(i,i)),calc(node(i,i),node(i,i),0,q);
	for(int i=1;i<=n;i++){
		sta[i]=s[i]-'0';
		if(sta[i])link(i,0);
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%s",s+1),ans[i]=-1;
		if(s[1]=='t'){
			x=read();
			if(sta[x])cut(x,i);
			else link(x,i);
			sta[x]^=1;
		}
		else{
			x=read(),y=read();if(y<x)swap(x,y);
			p[++pt]=nd(x,y,-1,i),ans[i]=0;
		}
	}
	sort(p+1,p+pt+1,cmp_x);
	cdq(1,pt);
	for(int i=1;i<=q;i++)if(ans[i]>=0){
		if(cnt[i])ans[i]-=q-i;
		printf("%d\n",ans[i]);
	}
	return 0;
}
 
