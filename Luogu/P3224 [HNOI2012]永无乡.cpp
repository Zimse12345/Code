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
#define M ((L+R)>>1)
#define Lid (ch[id][0])
#define Rid (ch[id][1])

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,q,p[N],P[N],fa[N],sz[N],rt[N];
int ch[N*64][2],v[N*64],cnt;
char op;
stack<int> rbs;
inline int F(int x){if(fa[x]^x)fa[x]=F(fa[x]);return fa[x];}
inline int newnode(){if(!rbs.empty()){int id=rbs.top();rbs.pop();
Lid=Rid=v[id]=0;return id;}return ++cnt;}

void update(int L,int R,int& id,int x){
	if(!id)id=newnode();
	++v[id];
	if(L^R){
		if(x<=M)update(L,M,Lid,x);
		else update(M+1,R,Rid,x);
	}
	return;
}

void merge(int& from,int& to){
	if(!from)return;
	if(!to)to=newnode();
	v[to]+=v[from];
	merge(ch[from][0],ch[to][0]),merge(ch[from][1],ch[to][1]);
	rbs.push(from);
	return;
}

void add(int x,int y){
	x=F(x),y=F(y);
	if(x==y)return;
	if(sz[x]<sz[y])swap(x,y);
	fa[y]=x,sz[x]+=sz[y];
	merge(rt[y],rt[x]);
	return;
}

int query(int L,int R,int id,int x){
	if(L==R)return P[L];
	if(v[Lid]>=x)return query(L,M,Lid,x);
	return query(M+1,R,Rid,x-v[Lid]);
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		p[i]=read(),P[p[i]]=i,fa[i]=i,sz[i]=1;
		update(1,n,rt[i],p[i]); 
	} 
	for(int i=1,x,y;i<=m;i++)x=read(),y=read(),add(x,y);
	q=read();
	for(int i=1,x,y;i<=q;i++){
		do{op=getchar();}while(op!='B'&&op!='Q');
		x=read(),y=read();
		if(op=='B')add(x,y);
		else{
			x=F(x);
			if(v[rt[x]]<y)printf("-1\n");
			else printf("%d\n",query(1,n,rt[x],y));
		}
	}
	return 0;
}

