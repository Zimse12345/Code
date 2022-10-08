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

#define M ((L+R)>>1)
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,a[N],rt[N],cnt,ch[N*8][2],ans[N];
stack<int> rbs;
inline int newnode(){if(!rbs.empty()){int id=rbs.top();rbs.pop(),Lid=Rid=0;return id;}return ++cnt;}

void ins(int L,int R,int& id,int x){
	if(!id)id=newnode();
	if(L^R)x>M?ins(M+1,R,Rid,x):ins(L,M,Lid,x);
	return;
}

void split(int L,int R,int id,int x,int& l,int& r){
	if(!id){l=r=0;return;}
	if(L==R){if(x>=M)l=id,r=0;else r=id,l=0;return;}
	else if(x>=M){l=newnode(),ch[l][0]=Lid,r=newnode(),split(M+1,R,Rid,x,ch[l][1],ch[r][1]);rbs.push(id);}
	else{r=newnode(),ch[r][1]=Rid,l=newnode(),split(L,M,Lid,x,ch[l][0],ch[r][0]);rbs.push(id);}
	if((!ch[l][0])&&(!ch[l][1]))rbs.push(l),l=0;
	if((!ch[r][0])&&(!ch[r][1]))rbs.push(r),r=0;
	return;
}

int merge(int l,int r){
	if(!l||!r)return l^r;
	ch[l][0]=merge(ch[l][0],ch[r][0]),ch[l][1]=merge(ch[l][1],ch[r][1]),rbs.push(r);
	return l;
}

void dfs(int L,int R,int id,int x){
	if(!id)return;
	if(L==R)ans[L]=x;
	else dfs(L,M,Lid,x),dfs(M+1,R,Rid,x);
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),ins(1,n,rt[a[i]],i);
	q=read();
	for(int i=1,l,r,x,y;i<=q;i++){
		l=read(),r=read(),x=read(),y=read();
		int p1,p2,p3;
		split(1,n,rt[x],l-1,p1,p2),split(1,n,p2,r,p2,p3);
		rt[x]=merge(p1,p3),rt[y]=merge(rt[y],p2);
	}
	for(int i=1;i<=100;i++)dfs(1,n,rt[i],i);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}

