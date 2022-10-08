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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e6+7,Mod=998244353,INF=1e9+7;
int n,ch[N][2],fa[N],tot,_n,_N;
char s[N];
vector<int> t[N];
int hd[N*8],nxt[N*16],to[N*16],ec;

void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

void link(int u,int v){
	add(u,v+2*n),add(v,u+2*n);
	return;
}

void ins(int id){
	int pos=0,len=strlen(s+1);
	for(int i=1;i<=len;i++){
		if(!ch[pos][s[i]-'0'])ch[pos][s[i]-'0']=++tot,fa[tot]=pos;
		pos=ch[pos][s[i]-'0'];
	}
	t[pos].push_back(id);
	return;
}

void dfs(int id){
	if(!id)return;
	if(fa[id]){
		add(_n+id,_n+fa[id]),add(_n+tot+fa[id],_n+tot+id);
	}
	for(unsigned i=0;i<t[id].size();i++){
		add(_n+id,t[id][i]+2*n),add(t[id][i],_n+tot+id);
		if(fa[id]){
			add(t[id][i],_n+fa[id]),add(_n+tot+fa[id],t[id][i]+2*n);
		}
	}
	for(unsigned i=0;i<t[id].size();i++){
		add(_N+1,t[id][i]+2*n),add(t[id][i],_N+2);
		if(i!=0){
			add(_N+1,_N-1),add(_N,_N+2);
			add(t[id][i],_N-1),add(_N,t[id][i]+2*n);
		}
		_N+=2;
	}
	for(unsigned i=t[id].size()-1;i<t[id].size();i--){
		add(_N+1,t[id][i]+2*n),add(t[id][i],_N+2);
		if(i!=t[id].size()-1){
			add(_N+1,_N-1),add(_N,_N+2);
			add(t[id][i],_N-1),add(_N,t[id][i]+2*n);
		}
		_N+=2;
	}
	dfs(ch[id][0]),dfs(ch[id][1]);
	return;
}

int dfn[N],low[N],Time,stk[N],top,vis[N],cl[N],cn;
void tarjan(int u){
	dfn[u]=low[u]=++Time,stk[++top]=u,vis[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		cl[u]=++cn,vis[u]=0;
		while(stk[top]^u)cl[stk[top]]=cn,vis[stk[top--]]=0;
		--top;
	}
	return;
}

signed main(){
	n=read(),_n=n*4;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int pos=0,len=strlen(s+1);
		for(int j=1;j<=len;j++)if(s[j]=='?')pos=j;
		if(!pos)ins(i),ins(i+n);
		else{
			s[pos]='0',ins(i);
			s[pos]='1',ins(i+n);
		}
	}
	_N=_n+tot*2;
	dfs(ch[0][0]),dfs(ch[0][1]);
	for(int i=1;i<=n;i++){
		add(i,i+3*n),add(i+n,i+2*n),add(i+3*n,i),add(i+2*n,i+n);
	}
	for(int i=1;i<=_N;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)if(cl[i+n]==cl[i+3*n]||cl[i]==cl[i+2*n]){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}

