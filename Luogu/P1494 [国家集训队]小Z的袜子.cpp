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

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,K=777,INF=1e9+7;
struct query{
	int l,r,id;
	query(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator < (const query& A)const{
		if(l/K==A.l/K)return r<A.r;
		return l<A.l;
	}
}q[N];
inline int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int n,m,a[N],p[N],z[N],t[N],ans;

void add(int x){
	ans+=t[x],t[x]++;
	return;
}

void del(int x){
	--t[x],ans-=t[x];
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,l,r;i<=m;i++)l=read(),r=read(),q[i]=query(l,r,i);
	sort(q+1,q+m+1);
	for(int i=1,l,r,L=1,R=0;i<=m;i++){
		l=q[i].l,r=q[i].r;
		while(R<r)add(a[++R]);
		while(L>l)add(a[--L]);
		while(R>r)del(a[R--]);
		while(L<l)del(a[L++]);
		if(l==r)p[q[i].id]=0,z[q[i].id]=1;
		else p[q[i].id]=ans,z[q[i].id]=(r-l+1)*(r-l)/2;
	}
	for(int i=1;i<=m;i++){
		int x=p[i],y=z[i],g=__gcd(x,y);
		x/=g,y/=g;
		printf("%lld/%lld\n",x,y);
	}
	return 0;
}
