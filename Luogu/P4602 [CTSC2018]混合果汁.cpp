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
#define Lid ch[id][0]
#define Rid ch[id][1]
#define M ((L+R)/2)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e18+1;
int n,m;

struct node{
	int d,p,l;
	node(int d=0,int p=0,int l=0):d(d),p(p),l(l){}
	bool operator < (const node& A)const{return d<A.d;}
}a[N];

int rt[N],ch[N*64][2],sumL[N*64],sumP[N*64],tot;

void update(int L,int R,int _id,int& id,int x,int y){
	id=++tot,sumL[id]=sumL[_id]+y,sumP[id]=sumP[_id]+x*y;
	if(L^R){
		if(x<=M)update(L,M,ch[_id][0],Lid,x,y),Rid=ch[_id][1];
		else update(M+1,R,ch[_id][1],Rid,x,y),Lid=ch[_id][0];
	}
	return;
}

int query(int L,int R,int id,int k){
	if(L==R){
		if(sumL[id]<k)return INF;
		return k*L;
	}
	else{
		if(sumL[Lid]<=k)return sumP[Lid]+query(M+1,R,Rid,k-sumL[Lid]);
		return query(L,M,Lid,k);
	}
}

signed main(){
	n=read(),m=read();
	for(int i=1,d,p,l;i<=n;i++){
		d=read(),p=read(),l=read();
		a[i]=node(d,p,l);
	}
	sort(a+1,a+n+1);
	for(int i=100000,t=n,RT=0;i;i--){
		rt[i]=rt[i+1];
		while(t&&a[t].d==i)update(1,100000,rt[i],RT,a[t].p,a[t].l),rt[i]=RT,--t;
	}
	for(int i=1,g,l;i<=m;i++){
		g=read(),l=read();
		int L=1,R=100000,ans=-1;
		while(L<=R){
			if(query(1,100000,rt[M],l)<=g)ans=M,L=M+1;
			else R=M-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

