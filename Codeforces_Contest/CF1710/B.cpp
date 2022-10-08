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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e18;
int T,n,m,lmx[N],rmx[N],mx[N],ans[N];

struct node{
	int x,p,id;
	node(int x=0,int p=0,int id=0):x(x),p(p),id(id){}
	bool operator < (const node& _)const{return x<_.x;}
}a[N];
int h[N];

struct nod{
	int pos,rpos,val;
	nod(int pos=0,int rpos=0,int val=0):pos(pos),rpos(rpos),val(val){}
	bool operator < (const nod& _)const{return rpos<_.rpos;}
};
multiset<nod> S;

inline int Abs(int x){
	return x<0?-x:x;
}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1,x,p;i<=n;i++)x=read(),p=read(),a[i]=node(x,p,i);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)h[i]=a[i].p;
		S.clear();
		int Val=0,Pos=0;
		for(int i=1;i<=n;i++){
			while(S.size()){
				nod p=*S.begin();
				if(p.rpos<a[i].x)S.erase(S.begin()),Val-=p.val,Pos-=p.pos;
				else break;
			}
			int sz=S.size();
			h[i]+=Val-(sz*a[i].x-Pos);
			S.emplace(a[i].x,a[i].x+a[i].p-1,a[i].p),Val+=a[i].p,Pos+=a[i].x;
		}
		S.clear(),Val=0,Pos=0;
		for(int i=n;i>=1;i--){
			while(S.size()){
				nod p=*S.begin();
//				printf("ck(%d)\n",-p.rpos);
				if(-p.rpos>a[i].x)S.erase(S.begin()),Val-=p.val,Pos-=p.pos;//printf("del(%lld)\n",-p.rpos);
				else break;
			}
			int sz=S.size();
			h[i]+=Val-(Pos-sz*a[i].x);
//			printf("%lld - (%lld - %lld)\n",Val,Pos,sz*a[i].x);
			S.emplace(a[i].x,-(a[i].x-a[i].p+1),a[i].p),Val+=a[i].p,Pos+=a[i].x;//printf("ins(%lld  %lld-%lld+1)\n",a[i].x-a[i].p+1,a[i].x,a[i].p);
		}
		for(int i=1;i<=n;i++){
			lmx[i]=-INF;
			if(h[i]>m){
				int x=h[i]-m;
				lmx[i]=max(lmx[i],x);
			}
			if(i>1)lmx[i]=max(lmx[i],lmx[i-1]+a[i].x-a[i-1].x);
		}
		for(int i=n;i>=1;i--){
			rmx[i]=-INF;
			if(h[i]>m){
				int x=h[i]-m;
				rmx[i]=max(rmx[i],x);
			}
			if(i<n)rmx[i]=max(rmx[i],rmx[i+1]+a[i+1].x-a[i].x);
			mx[i]=max(lmx[i],rmx[i]);
			if(a[i].p>=mx[i])ans[a[i].id]=1;
			else ans[a[i].id]=0;
		}
		for(int i=1;i<=n;i++)printf("(%d %d %d %d)\n",a[i].x,a[i].p,h[i],mx[i]);
		for(int i=1;i<=n;i++)printf("%lld",ans[i]);
		printf("\n");
//		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
//			if(Abs(a[i].x-a[j].x)<a[i].p)h[j]-=a[i].p-Abs(a[i].x-a[j].x);
//		}
//		for(int i=1;i<=n;i++)printf("(%d)",h[i]);
	}
	return 0;
}

