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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N];

struct node{
	int l,r,v;
	node(int l=0,int r=0,int v=0):l(l),r(r),v(v){}
	bool operator < (const node& A)const{if(v==A.v)return l<A.l;return v>A.v;}
};
struct query{
	int l,r,k,id;
	query(int l=0,int r=0,int k=0,int id=0):l(l),r(r),k(k),id(id){}
	bool operator < (const query& A)const{
		if(l==A.l){
			if(r==A.r)return id<A.id;
			return r<A.r;
		}
		return l<A.l;
	}
}q[N];
int fa[N],L[N],R[N],V[N],f[N],ans[N],cnt;
int F(int x){if(fa[x]^x)fa[x]=F(fa[x]);return fa[x];}
set<node> s;

void sol(int l,int r){
	s.clear();
	for(int i=l;i<=r;i++){
		s.insert(node(i,i,a[i])),fa[i]=i;
		L[i]=i,R[i]=i,V[i]=a[i];
	}
	int res=0;cnt=0;
	while(!s.empty()){
		node p=*s.begin();
		s.erase(s.begin());
		res+=p.v;
		f[++cnt]=res;
		if(p.l==l){
			if(p.r<r){
				int _r=F(p.r+1);
				s.erase(s.find(node(L[_r],R[_r],V[_r])));
				l=R[_r]+1;
			}
			continue;
		}
		if(p.r==r){
			if(p.l>l){
				int _l=F(p.l-1);
				s.erase(s.find(node(L[_l],R[_l],V[_l])));
				r=L[_l]-1;
			}
			continue;
		}
		int _l=F(p.l-1),_r=F(p.r+1),_m=F(p.l);
		s.erase(s.find(node(L[_l],R[_l],V[_l])));
		s.erase(s.find(node(L[_r],R[_r],V[_r])));
		fa[_l]=_m,fa[_r]=_m;
		L[_m]=L[_l],R[_m]=R[_r];
		V[_m]=-V[_m]+V[_l]+V[_r];
		s.insert(node(L[_m],R[_m],V[_m]));
	}
//	printf("  %d\n",cnt);
//	if(cnt!=(r-l+1)/2)while(1);
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();for(int l=1;l<=10;l++)for(int r=l;r<=10;r++)sol(l,r);
	for(int i=1,l,r,k;i<=m;i++){
		l=read(),r=read(),k=read();
		q[i]=query(l,r,k,i);
	}
	sort(q+1,q+m+1);
	for(int i=1;i<=m;i++){
		if(q[i].l!=q[i-1].l||q[i].r!=q[i-1].r)sol(q[i].l,q[i].r);
		ans[q[i].id]=f[q[i].k];
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}

