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

const int N=4e6+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N],b[N];
ll val[N],mi[N<<2],tag[N<<2],sum[N<<2];
struct s{
	int v,id;
	s(int v=0,int id=0):v(v),id(id){}
	bool operator < (const s& A)const{return v<A.v;}
}p[N];

void build(int L,int R,int id){
	mi[id]=0,tag[id]=0,sum[id]=0;
	if(L!=R){
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
	}
	return;
}

void pushdown(int id){
	if(tag[id]!=0){
		mi[id]+=tag[id];
		tag[id<<1]+=tag[id],tag[(id<<1)|1]+=tag[id];
		tag[id]=0;
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&r>=R)tag[id]=x,pushdown(id);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,id<<1,l,r,x);
		else pushdown(id<<1);
		if(r>M)update(M+1,R,(id<<1)|1,l,r,x);
		else pushdown((id<<1)|1);
		mi[id]=min(mi[id<<1],mi[(id<<1)|1]);
	}
	return;
}

void add(int L,int R,int id,int x){
	++sum[id];
	if(L!=R){
		int M=(L+R)>>1;
		if(x<=M)add(L,M,id<<1,x);
		else add(M+1,R,(id<<1)|1,x);
	}
	return;
}

ll Sum(int L,int R,int id,int l,int r){
	if(l<=L&&r>=R)return sum[id];
	int M=(L+R)>>1,res=0;
	if(l<=M)res+=Sum(L,M,id<<1,l,r);
	if(r>M)res+=Sum(M+1,R,(id<<1)|1,l,r);
	return res; 
}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		ll ans=0;
		for(int i=1;i<=n;i++)a[i]=read(),p[i]=s(a[i],i);
		sort(p+1,p+n+1);
		for(int i=1;i<=m;i++)b[i]=read();
		sort(b+1,b+m+1);
		build(0,n,1);
		for(int i=1;i<=n;i++)update(0,n,1,i,n,1);
		int L=1,R=1;
		for(int i=1;i<=m;i++){
			while(L<=n&&b[i]>p[L].v)update(0,n,1,0,p[L].id-1,1),++L;
			while(R<=n&&b[i]>=p[R].v)update(0,n,1,p[R].id,n,-1),++R;
			pushdown(1),ans+=mi[1];
		}
		int k=0;
		for(int i=1;i<=n;i++){
			if(p[i-1].v!=p[i].v)++k;
			a[p[i].id]=k;
		}
		build(1,n,1);
		for(int i=1;i<=n;i++){
			ans+=Sum(1,n,1,a[i]+1,n);
			add(1,n,1,a[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
