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

const int N=4e5+7,K=1000,INF=1e9+7;
struct val{
	int v,id;
	val(int v=0,int id=0):v(v),id(id){}
	bool operator < (const val& A)const{return v<A.v;}
}b[N];
struct query{
	int l,r,id;
	query(int l=0,int r=0,int id=0):l(l),r(r),id(id){};
	bool operator < (const query& A)const{if(l/K==A.l/K)return r<A.r;return l<A.l;}
}Q[N];
int n,q,a[N],tot,Ans[N],t[N];

signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++)b[i]=val(read(),i);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(b[i].v!=b[i-1].v)++tot;
		a[b[i].id]=tot;
	}
	for(int i=1,l,r;i<=q;i++)l=read(),r=read(),Q[i]=query(l,r,i);
	sort(Q+1,Q+q+1),Q[0].l=-K;
	for(int i=1,l=0,r=0,L=1,R=0,ans=0,la=0;i<=q;i++){
		l=Q[i].l,r=Q[i].r,ans=la;
		if(l/K!=Q[i-1].l/K){
			for(int j=L;j<=R;j++)t[a[j]]=0;
			L=((l/K)+1)*K,R=((l/K)*K)-1,ans=0;
			for(int j=R+1;j<L;j++)--t[a[j]];
		}
		else while(L<((l/K)+1)*K)--t[a[L++]];
		while(R<r)++t[a[++R]],ans=max(ans,t[a[R]]);
		la=ans;
		while(L>l)++t[a[--L]],ans=max(ans,t[a[L]]);
		Ans[Q[i].id]=ans;
	}
	for(int i=1;i<=q;i++)printf("%lld\n",-Ans[i]);
	return 0;
}
