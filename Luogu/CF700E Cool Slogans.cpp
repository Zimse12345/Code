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
#define M ((L+R)/2)
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,SZ=26,INF=1e9+7;
int n,tot,pre,ans,f[N];
int rt[N],ch[N*32][2],cnt;
char s[N];

struct node{
	int to[SZ],len,link;
}t[N];
vector<int> g[N];

void ins(int& id,int L,int R,int x){
	if(!id)id=++cnt;
	if(L!=R){
		if(x<=M)ins(Lid,L,M,x);
		else ins(Rid,M+1,R,x);
	}
	return;
}

int merge(int id1,int id2){
	if(!id1||!id2)return id1+id2;
	int id=++cnt;
	Lid=merge(ch[id1][0],ch[id2][0]),Rid=merge(ch[id1][1],ch[id2][1]);
	return id;
}

int findpos(int id,int L,int R){
	if(L==R)return L;
	if(Lid)return findpos(Lid,L,M);
	return findpos(Rid,M+1,R);
}

int findR(int id,int L,int R,int x){
	if(!id||x<=L)return 0;
	if(L==R)return L;
	int r=findR(Rid,M+1,R,x);
	return r?r:findR(Lid,L,M,x);
}

void ins(int c){
	int id=++tot,p=pre;
	t[id].len=t[p].len+1;
	ins(rt[id],1,n,t[id].len);
	while(p!=-1&&!t[p].to[c])t[p].to[c]=id,p=t[p].link;
	if(p==-1)t[id].link=0;
	else{
		int q=t[p].to[c];
		if(t[q].len==t[p].len+1)t[id].link=q;
		else{
			int cp=++tot;
			t[cp]=t[q],t[cp].len=t[p].len+1;
			while(p!=-1&&t[p].to[c]==q)t[p].to[c]=cp,p=t[p].link;
			t[q].link=t[id].link=cp;
		}
	}
	pre=id;
	return;
}

void dfs(int u){
	for(unsigned i=0;i<g[u].size();i++)if(g[u][i]){
		dfs(g[u][i]);
		rt[u]=merge(rt[u],rt[g[u][i]]);
	}
	return;
}

void dp(int u,int p){
	int pos=findpos(rt[u],1,n),q=findR(rt[p],1,n,pos);
	if(!p||(q&&pos-t[u].len+t[p].len<=q))f[u]=f[p]+1,ans=max(ans,f[u]),p=u;
	else f[u]=f[p];
	for(unsigned i=0;i<g[u].size();i++)if(g[u][i])dp(g[u][i],p);
	return;
}

signed main(){
	t[0].link=-1;
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)ins(s[i]-'a');
	for(int i=1;i<=tot;i++)g[t[i].link].push_back(i);
	dfs(0);
	for(unsigned i=0;i<g[0].size();i++)if(g[0][i])dp(g[0][i],0);
	printf("%d\n",ans);
	return 0;
}

