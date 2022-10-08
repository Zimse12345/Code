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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353,INF=1e9+7;
struct node{int x,y,ty,t,id;
node(int x=0,int y=0,int ty=0,int t=0,int id=0):x(x),y(y),ty(ty),t(t),id(id){}}a[N];
int n,m,ct,tr[N],ans[N],tag[N];

bool cmp_x(const node& A,const node& B){if(A.x==B.x)return A.id<B.id;return A.x<B.x;}
bool cmp_y(const node& A,const node& B){if(A.y==B.y)return A.id<B.id;return A.y<B.y;}
inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x,int v){for(;x<=n;ub(x))tr[x]+=v;return;}
inline int q(int x){int r=0;for(;x;db(x))r+=tr[x];return r;}

void cdq(int L,int R){
	if(L>=R)return;
	int M=(L+R)>>1;
	cdq(L,M),cdq(M+1,R);
	
	int p=L;
	for(int i=M+1;i<=R;i++){
		while(p<=M){
			if(a[p].ty==1){++p;continue;}
			if(a[p].x>a[i].x)break;
			add(a[p].y,a[p].t),++p;
		}
		if(a[i].ty==0)continue;
		ans[a[i].id]+=a[i].t*q(a[i].y);
	}
	for(int i=L;i<p;i++)if(a[i].ty==0)add(a[i].y,-a[i].t);
	
	sort(a+L,a+R+1,cmp_x);
	return;
}

signed main(){
	read(),n=read();
	while(1){
		int op=read();
		if(op==3)break;
		++ct;
		if(op==1){
			int x=read(),y=read(),v=read();
			a[++m]=node(x,y,0,v,ct);
		}
		if(op==2){
			int a1=read(),b1=read(),a2=read(),b2=read();
			a[++m]=node(a1-1,b1-1,1,1,ct);
			a[++m]=node(a1-1,b2,1,-1,ct);
			a[++m]=node(a2,b1-1,1,-1,ct);
			a[++m]=node(a2,b2,1,1,ct);
			tag[ct]=1;
		}
	}
	cdq(1,m);
	for(int i=1;i<=m;i++)if(tag[i])printf("%lld\n",ans[i]);
	return 0;
}

