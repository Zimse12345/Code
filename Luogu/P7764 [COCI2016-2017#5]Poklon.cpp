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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=1e6+7,B=1200,INF=1e9+7;
int n,m,a[N],ans[N],t[N],s=0;
struct node{
	int v,id;
	node(int v=0,int id=0):v(v),id(id){}
	bool operator < (const node& A)const{return v<A.v;}
}b[N];
struct query{
	int l,r,id;
	query(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator < (const query& A){
		if(l/B==A.l/B)return ((l/B)&1)?r<A.r:r>A.r;
		return l<A.l;
	}
}q[N];
inline void add(int x){if(t[x]==1)++s;if(t[x]==2)--s;++t[x];return;}
inline void del(int x){if(t[x]==3)++s;if(t[x]==2)--s;--t[x];return;}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=node(a[i],i);
	sort(b+1,b+n+1),b[0].v=INF;
	for(int i=1,j=0;i<=n;i++){
		if(b[i].v!=b[i-1].v)++j;
		a[b[i].id]=j;
	}
	for(int i=1,l,r;i<=m;i++)l=read(),r=read(),q[i]=query(l,r,i);
	sort(q+1,q+m+1);
	for(int i=1,L=1,R=0,l,r;i<=m;i++){
		l=q[i].l,r=q[i].r;
		while(R<r)add(a[++R]);
		while(L>l)add(a[--L]);
		while(R>r)del(a[R--]);
		while(L<l)del(a[L++]);
		ans[q[i].id]=s;
	}
	for(int i=1;i<=m;i++)write(ans[i]),putchar(10);
	return 0;
}
