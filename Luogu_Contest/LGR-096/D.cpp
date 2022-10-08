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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,ans[N],t[N];
int hd[N],nxt[N],to[N],ec,cnt[N];

void add(int u,int v){
	to[++ec]=v,nxt[ec]=hd[u],hd[u]=ec;
	return;
}

void dfs1(int u,int pr){
	cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v!=pr)dfs1(v,u),cnt[u]+=cnt[v];
	}
	return;
}

struct node{
	int id,cnt;
	node(int id=0,int cnt=0):id(id),cnt(cnt){}
	bool operator < (const node& A)const{return cnt<A.cnt;}
};

//void dfs(int u,int pr,int p,int L){
//	int R=L+cnt[u]-1;
//	t[p]=L;
//	vector<node> V;
//	for(int i=hd[u],v;i;i=nxt[i]){
//		v=to[i];
//		if(v!=pr)V.push_back(node(v,cnt[v]));
//	}
//	sort(V.begin(),V.end());
//	for(int i=0;i<V.size();i++){
//		if(i>0&&V[i].cnt==V[i-1].cnt){
//			
//		}
//		else dfs(V[i].id,u,p+1,L)
//	}
//	return;
//}

int main(){
	n=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	for(int i=1;i<=n;i++)ans[i]=INF;
	printf("1 %d ",n);
	for(int i=2;i<n;i++)printf("%d ",i);
	printf("\n");
//	for(int i=1;i<=n;i++){
//		dfs1(1,0);
//		dfs(i,0,1,1);
//	}
	return 0;
}
