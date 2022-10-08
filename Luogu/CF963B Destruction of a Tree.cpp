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
int n,tag[N],ans[N],tot;
int hd[N],nxt[N],to[N],ec;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
vector<int> ch[N];

void del(int u){
	int sz=0;
	for(int i=0;i<signed(ch[u].size());i++)sz+=tag[ch[u][i]];
	if(!(sz&1)){
		ans[++tot]=u,tag[u]=0;
		for(int i=0;i<signed(ch[u].size());i++)if(tag[ch[u][i]])del(ch[u][i]);
	}
	return;
}

int dfs(int u){
	int sz=ch[u].size(),r=0;
	for(int i=0;i<sz;i++)r+=dfs(ch[u][i]);
	if(u!=1&&(r&1)){
		ans[++tot]=u,tag[u]=0;
		for(int i=0;i<sz;i++)if(tag[ch[u][i]])del(ch[u][i]);
	}
	return tag[u];
}

void maketree(int u,int from){
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		ch[u].push_back(v),maketree(v,u);
	}
	return;
}

signed main(){
	n=read();
	for(int i=1,f;i<=n;i++){
		f=read();
		if(f)add(f,i),add(i,f);
		tag[i]=1;
	}
	maketree(1,0);
	dfs(1);
	if(tag[1])del(1);
	if(tot^n)printf("NO\n");
	else{
		printf("YES\n");
		for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	}
	return 0;
}

