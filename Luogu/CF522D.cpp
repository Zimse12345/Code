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

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int n,m,c,a[N],t[N],b[N],ans[N],mi[N<<2];
struct p{
	int id,v;
	p(int id=0,int v=0):id(id),v(v){};
	bool operator < (const p& A)const{return v<A.v;}
}s[N];
struct q{
	int l,r,id;
	q(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator < (const q& A)const{return r<A.r;}
}Q[N];

void build(int L,int R,int id){
	mi[id]=INF;
	if(L!=R)build(L,(L+R)/2,id<<1),build((L+R)/2+1,R,(id<<1)|1);
	return;
}

void update(int L,int R,int id,int x,int p){
	if(L==R)mi[id]=p;
	else{
		int M=(L+R)>>1;
		if(x<=M)update(L,M,id<<1,x,p);
		else update(M+1,R,(id<<1)|1,x,p);
		mi[id]=min(mi[id<<1],mi[(id<<1)|1]);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	if(l<=L&&r>=R)return mi[id];
	int M=(L+R)>>1,res=INF;
	if(l<=M)res=min(res,query(L,M,id<<1,l,r));
	if(r>M)res=min(res,query(M+1,R,(id<<1)|1,l,r));
	return res;
}

int main(){
	n=read(),m=read();
	for(int i=1,v;i<=n;i++)v=read(),s[i]=p(i,v);
	for(int i=1,l,r;i<=m;i++)l=read(),r=read(),Q[i]=q(l,r,i);
	sort(s+1,s+n+1),sort(Q+1,Q+m+1);
	s[0].v=-1;
	for(int i=1;i<=n;i++){
		if(s[i].v!=s[i-1].v)++c;
		a[s[i].id]=c;
	}
	int L=1;
	for(int i=1;i<=n;i++)b[i]=INF;
	build(1,n,1);
	for(int i=1,l,r;i<=m;i++){
		l=Q[i].l,r=Q[i].r;
		for(int j=L;j<=r;j++){
			if(t[a[j]])update(1,n,1,t[a[j]],j-t[a[j]]);
			t[a[j]]=j;
		}
		L=max(L,r+1);
		ans[Q[i].id]=query(1,n,1,l,r);
	}
	for(int i=1;i<=n;i++){
		if(t[a[i]])b[t[a[i]]]=i-t[a[i]];
		t[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		if(ans[i]>=INF)ans[i]=-1;
		printf("%d\n",ans[i]);
	}
	return 0;
}
