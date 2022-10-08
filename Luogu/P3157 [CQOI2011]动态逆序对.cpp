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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
struct value{
	int v,del;ll f;
	value(int v=0,int del=0,ll f=0):v(v),del(del),f(f){}
}a[N];
int tag=0;
inline bool cmp1(const value& A,const value& B){if(tag)return A.v>B.v;return A.v<B.v;}
inline bool cmp2(const value& A,const value& B){return A.del<B.del;}
int n,m,b[N];
ll ans[N];
struct treearray{
	int sum[N];
	inline void ub(int& x){x+=(x&(-x));return;}
	inline void db(int& x){x-=(x&(-x));return;}
	inline void add(int x,int t){for(;x<=n;ub(x))sum[x]+=t;}
	inline ll query(int x){ll res=0;for(;x>0;db(x))res+=sum[x];return res;}
}t;

void sol(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1,j=l;
	sol(l,mid),sol(mid+1,r);
	tag=1,sort(a+l,a+mid+1,cmp1),sort(a+mid+1,a+r+1,cmp1);
	for(int i=mid+1;i<=r;i++){
		while(j<=mid&&a[j].v>a[i].v)t.add(a[j].del,1),++j;
		a[i].f+=t.query(a[i].del);
	}
	for(int i=l;i<j;i++)t.add(a[i].del,-1);
	tag=0,sort(a+l,a+mid+1,cmp1),sort(a+mid+1,a+r+1,cmp1),j=mid+1;
	for(int i=l;i<=mid;i++){
		while(j<=r&&a[j].v<a[i].v)t.add(a[j].del,1),++j;
		a[i].f+=t.query(a[i].del);
	}
	for(int i=mid+1;i<j;i++)t.add(a[i].del,-1);
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i].v=read(),b[a[i].v]=i;
	for(int i=1,d;i<=m;i++)d=read(),a[b[d]].del=n-i+1;
	for(int i=1,j=0;i<=n;i++)if(!a[i].del)a[i].del=++j;
	sol(1,n);
	sort(a+1,a+n+1,cmp2);
	ll s=0;
	for(int i=1;i<=n;i++)s+=a[i].f,ans[i]=s;
	for(int i=n;i>=n-m+1;i--)printf("%lld\n",ans[i]);
	return 0;
}

