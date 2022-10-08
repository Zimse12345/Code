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

const int N=2e5+7,K=400,INF=1e9;
struct node{int x,y,id,sig;node(int x=0,int y=0,int id=0,int sig=0):x(x),y(y),id(id),sig(sig){}
bool operator < (const node& A)const{if(x/K==A.x/K)return ((x/K)&1)?y>A.y:y<A.y;return x<A.x;}}Q[N];
int n,m,a[N],t,ans[N],sum;
int t1[N],t2[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=read();
	for(int i=1,l1,r1,l2,r2;i<=m;i++){
		l1=read(),r1=read(),l2=read(),r2=read();
		Q[++t]=node(r1,r2,i,1),Q[++t]=node(r1,l2-1,i,-1),Q[++t]=node(l1-1,r2,i,-1),Q[++t]=node(l1-1,l2-1,i,1);
	}
	for(int i=1;i<=t;i++)if(Q[i].y<Q[i].x)swap(Q[i].x,Q[i].y);
	sort(Q+1,Q+t+1);
	for(int i=1,l=0,r=0,L,R;i<=t;i++){
		L=Q[i].x,R=Q[i].y;
		if(!L)continue;
		while(r<R)++r,sum+=t1[a[r]],++t2[a[r]];
		while(l>L)sum-=t2[a[l]],--t1[a[l]],--l;
		while(r>R)sum-=t1[a[r]],--t2[a[r]],--r;
		while(l<L)++l,sum+=t2[a[l]],++t1[a[l]];
		ans[Q[i].id]+=Q[i].sig*sum;
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}

