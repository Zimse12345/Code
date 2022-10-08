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
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)>>1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,w[N],hd[N],nxt[N],to[N],ec,deg[N];
int s[N],Time,dfn[N],mi[N*4],Ans[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,++deg[u];return;}
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return y<A.y;}
}query[N];
set<node> S;

void dfs(int u,int from){
	s[++Time]=u,dfn[u]=Time;
	for(int i=hd[u];i;i=nxt[i])if(to[i]^from)dfs(to[i],u);
	return;
}

void build(int L,int R,int id){
	if(L==R)mi[id]=w[s[L]];
	else{
		build(L,M,Lid),build(M+1,R,Rid);
		mi[id]=min(mi[Lid],mi[Rid]);
	}
	return;
}

void update(int L,int R,int id,int x,int y){
	if(L==R)mi[id]=y;
	else{
		if(x<=M)update(L,M,Lid,x,y);
		else update(M+1,R,Rid,x,y);
		mi[id]=min(mi[Lid],mi[Rid]);
	}
	return;
}

int findR(int L,int R,int id,int Lb,int v){
	if(R<Lb)return n+1;
	if(L==R){
		if(mi[id]<v)return L;
		else return n+1;
	}
	int t=findR(L,M,Lid,Lb,v);
	if(t==n+1)return findR(M+1,R,Rid,Lb,v);
	return t;
}

int findL(int L,int R,int id,int Rb,int v){
	if(L>Rb)return 0;
	if(L==R){
		if(mi[id]<v)return R;
		return 0;
	}
	int t=findL(M+1,R,Rid,Rb,v);
	if(t==0)return findL(L,M,Lid,Rb,v);
	return t;
}

int dfs2(int u,int from,int x){
	int pos=0,val=INF;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		if(w[v]>=x&&w[v]<val)val=w[v],pos=v;
	}
	if(pos)return dfs2(pos,u,x);
	return u;
}

void dfs3(int u,int from,int L,int R){
	vector<node> q;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		q.push_back(node(v,w[v]));
	}
	sort(q.begin(),q.end());
	for(int i=0;i<signed(q.size());i++){
		int mid=L-1;
		int LL=L,RR=R;
		while(LL<=RR){
			int MM=(LL+RR)>>1;
			if(query[MM].y<=q[i].y)mid=MM,LL=MM+1;
			else RR=MM-1;
		}
		if(mid>=L)dfs3(q[i].x,u,L,mid);
		L=mid+1;
	}
	for(int i=L;i<=R;i++)Ans[query[i].x]=u;
	return;
}

signed main(){
//	freopen("fall4.in","r",stdin);
//	freopen("my.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	int cnt=0,tag=0,pos=0;
	for(int i=1;i<=n;i++){
		if(deg[i]==1)++cnt,pos=i;
		if(deg[i]==n-1)tag=i;
	}
		while(m--){
			int op=read();
			if(op==1){
				int x=read(),y=read();
				w[x]=y;
			}
			else{
				printf("%d\n",dfs2(1,0,read()));
			}
		}
		return 0;
	return 0;
}

