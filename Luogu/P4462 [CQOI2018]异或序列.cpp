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
int n,m,k,a[N],t[N],ans,Ans[N];

void add(int x){
	ans+=t[x^k],t[x]++;
	return;
}

void del(int x){
	--t[x],ans-=t[x^k];
	return;
}

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read()^a[i-1];
	for(int i=1,l,r;i<=m;i++)l=read(),r=read(),q[i]=query(l-1,r,i);
	sort(q+1,q+m+1);
	for(int i=1,l,r,L=0,R=-1;i<=m;i++){
		l=q[i].l,r=q[i].r;
		while(R<r)add(a[++R]);
		while(L>l)add(a[--L]);
		while(R>r)del(a[R--]);
		while(L<l)del(a[L++]);
		Ans[q[i].id]=ans;
	}
	for(int i=1;i<=m;i++)printf("%lld\n",Ans[i]);
	return 0;
}
