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

using namespace std;

inline int read(){ll qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=2e5,INF=1e9+7;
struct val{
	int v,l,r,f,id;
	val(int v=0,int l=0,int r=0,int f=0,int id=0):v(v),l(l),r(r),f(f),id(id){}
}v[N];
int n,m,tr[N],ans;

inline bool cmp0(const val& A,const val& B){return A.id<B.id;}
inline bool cmp1(const val& A,const val& B){return A.v<B.v;}
inline bool cmp2(const val& A,const val& B){return A.l<B.l;}
inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x,int k){for(;x<=n;ub(x))tr[x]=max(tr[x],k);return;}
inline int query(int x){int res=0;for(;x;db(x))res=max(res,tr[x]);return res;}
inline void del(int x){for(;x<=n;ub(x))tr[x]=0;return;}

void sol(int l,int r){
	if(l>=r)return;
	int mid=(l+r)>>1,p=l;
	sol(l,mid),
	sort(v+l,v+mid+1,cmp1),sort(v+mid+1,v+r+1,cmp2);
	
	for(int i=mid+1;i<=r;i++){
		while(p<=mid&&v[p].v<=v[i].l)add(v[p].r,v[p].f),++p;
		v[i].f=max(v[i].f,query(v[i].v)+1);
	}
	for(int i=l;i<p;i++)del(v[i].r);
	
	sort(v+l,v+r+1,cmp0);
	sol(mid+1,r);
	return;
}

int main(){
	n=read(),m=read();
	for(int i=1,x;i<=n;i++)x=read(),v[i]=val(x,x,x,1,i);
	for(int i=1,x,y;i<=m;i++)x=read(),y=read(),v[x].l=min(v[x].l,y),v[x].r=max(v[x].r,y);
	sol(1,n);
	for(int i=1;i<=n;i++)ans=max(ans,v[i].f);
	printf("%d\n",ans);
	return 0;
}

