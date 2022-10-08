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

const int N=2e6+7,Mod=998244353,INF=1e9+7;
struct qu{
	int l,r,id;
	qu(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator < (const qu& A)const{if(r==A.r)return id<A.id;return r<A.r;}
}q[N];
int n,c,m,a[N],Ans[N],pr[N],ppr[N]; 
int sum[N];
inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x,int t){for(;x<=n;ub(x))sum[x]+=t;}
inline int query(int x){int res=0;for(;x;db(x))res+=sum[x];return res;}

signed main(){
	n=read(),c=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,l,r;i<=m;i++)l=read(),r=read(),q[i]=qu(l,r,i);
	sort(q+1,q+m+1);
	for(int i=1,p=1,l,r;i<=m;i++){
		l=q[i].l,r=q[i].r;
		while(p<=r){
			if(pr[a[p]])add(pr[a[p]],1);
			if(ppr[a[p]])add(ppr[a[p]],-1);
			ppr[a[p]]=pr[a[p]],pr[a[p]]=p,++p;
		}
		Ans[q[i].id]=query(r)-query(l-1);
	}
	for(int i=1;i<=m;i++)printf("%d\n",Ans[i]);
	return 0;
}

