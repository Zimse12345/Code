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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,d[N],D,fa[N],cnt[N],vis[N],ansu[N],ansv[N],anst,du[N];
inline int F(int x){if(x^fa[x])fa[x]=F(fa[x]);return fa[x];}
set<int> s[N];
set<int>::iterator it;
struct node{int id;node(int id=0):id(id){}
bool operator < (const node& A)const{return du[id]<du[A.id];}};
priority_queue<node> q;

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)d[i]=read(),D+=d[i];
	if(D!=(n-1)*2){
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i,cnt[i]=1;
		if(d[i])s[i].insert(i),du[i]=d[i];
		else{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		int A=F(u),B=F(v);
		if(A==B){
			printf("-1");
			return 0;
		}
		if(cnt[A]<cnt[B])swap(A,B);
		cnt[A]+=cnt[B],fa[B]=A;
		for(it=s[B].begin();it!=s[B].end();it++)s[A].insert(*it);
		s[B].clear();
		--d[u],--d[v];
		if(d[u]<0||d[v]<0){
			printf("-1\n");
			return 0;
		}
		if(d[u]==0)s[A].erase(s[A].find(u));
		if(d[v]==0)s[A].erase(s[A].find(v));
		du[A]=du[A]+du[B]-2;
	}
	for(int i=1,x;i<=n;i++){
		x=F(i);
		if(vis[x]++)continue;
		q.push(x);
	}
	while(signed(q.size())>1){
		int p1=q.top().id;q.pop();
		int p2=q.top().id;q.pop();
		if(signed(s[p1].size())==0||signed(s[p2].size())==0){
			printf("-1\n");
			return 0;
		}
		int u=*s[p1].begin(),v=*s[p2].begin();
		++anst,ansu[anst]=u,ansv[anst]=v;
		--d[u],--d[v];
		if(d[u]==0)s[p1].erase(s[p1].find(u));
		if(d[v]==0)s[p2].erase(s[p2].find(v));
		for(it=s[p2].begin();it!=s[p2].end();it++)s[p1].insert(*it);
		s[p2].clear(),du[p1]=du[p1]+du[p2]-2;
		q.push(p1);
	}
	for(int i=1;i<=anst;i++)printf("%d %d\n",ansu[i],ansv[i]);
	return 0;
}

