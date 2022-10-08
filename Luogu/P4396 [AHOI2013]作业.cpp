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
int K;
struct query{
	int l,r,a,b,id;
	query(int l=0,int r=0,int a=0,int b=0,int id=0):l(l),r(r),a(a),b(b),id(id){}
	bool operator < (const query& A){
		if(r/K==A.r/K){if((r/K)&1)return l>A.l;return l<A.l;}
		return r<A.r;
	}
}q[N];
int n,m,v[N],ans1[N],ans2[N],t[N],tt[N],dt[N];

inline void add(int x){
	++t[x],++tt[x/K];
	if(t[x]==1)++dt[x/K];
	return;
}

inline void del(int x){
	--t[x],--tt[x/K];
	if(t[x]==0)--dt[x/K];
	return;
}

int main(){
	n=read(),m=read();
	K=max(double(n)/sqrt(double(m)),2.0);
	for(int i=1;i<=n;i++)v[i]=read();
	for(int i=1,l,r,a,b;i<=m;i++)l=read(),r=read(),a=read(),b=read(),q[i]=query(l,r,a,b,i);
	sort(q+1,q+m+1);
	for(int i=1,L=1,R=0;i<=m;i++){
		int l=q[i].l,r=q[i].r,a=q[i].a,b=q[i].b,p1=0,p2=0;
		while(R<r)add(v[++R]);
		while(L>l)add(v[--L]);
		while(R>r)del(v[R--]);
		while(L<l)del(v[L++]);
		if(a/K==b/K)for(int i=a;i<=b;i++)p1+=t[i],p2+=(t[i]?1:0);
		else{
			for(int i=a/K+1;i<=b/K-1;i++)p1+=tt[i],p2+=dt[i];
			for(int i=a;i<=(a/K+1)*K-1;i++)p1+=t[i],p2+=(t[i]?1:0);
			for(int i=(b/K)*K;i<=b;i++)p1+=t[i],p2+=(t[i]?1:0);
		}
		ans1[q[i].id]=p1,ans2[q[i].id]=p2;
	}
	for(int i=1;i<=m;i++)write(ans1[i]),putchar(' '),write(ans2[i]),putchar('\n');
	return 0;
}

