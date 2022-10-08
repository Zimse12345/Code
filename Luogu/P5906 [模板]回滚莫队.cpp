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

const int N=4e5+7,K=250,INF=1e9+7;
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
int n,q,a[N],u[N],tot,Ans[N],t[N],lv[N],rv[N],llv[N],rrv[N];

int bf(int l,int r){
	int res=0;
	for(int i=l;i<=r;i++){
		rrv[a[i]]=i;
		if(!llv[a[i]])llv[a[i]]=i;
		res=max(res,rrv[a[i]]-llv[a[i]]);
	}
	for(int i=l;i<=r;i++)llv[a[i]]=rrv[a[i]]=0;
	return res;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)b[i]=val(read(),i);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(b[i].v!=b[i-1].v)u[++tot]=b[i].v;
		a[b[i].id]=tot;
	}
	q=read();
	for(int i=1,l,r;i<=q;i++)l=read(),r=read(),Q[i]=query(l,r,i);
	sort(Q+1,Q+q+1),Q[0].l=-K;
	for(int i=1,l=0,r=0,L=1,R=0,ans=0,la=0;i<=q;i++){
		l=Q[i].l,r=Q[i].r,ans=la;
		if(l/K!=Q[i-1].l/K){
			for(int j=L-1;j<=R;j++)lv[a[j]]=rv[a[j]]=0;
			L=(l/K+1)*K,R=L-1,la=ans=0;
		}
		if(!(l<L&&r>=R))Ans[Q[i].id]=bf(l,r);
		else{
			while(R<r){
				++R,rv[a[R]]=R;
				if(lv[a[R]]==0)lv[a[R]]=R;
				if(lv[a[R]])ans=max(ans,rv[a[R]]-lv[a[R]]);
			}
			la=ans;
			for(int j=l;j<L;j++){
				rrv[a[j]]=j;
				if(!llv[a[j]])llv[a[j]]=j;
				ans=max(ans,rrv[a[j]]-llv[a[j]]);
				ans=max(ans,rv[a[j]]-llv[a[j]]);
			}
			Ans[Q[i].id]=ans;
			for(int j=l;j<L;j++)llv[a[j]]=rrv[a[j]]=0;
		}
	}
	for(int i=1;i<=q;i++)printf("%lld\n",Ans[i]);
	return 0;
}
