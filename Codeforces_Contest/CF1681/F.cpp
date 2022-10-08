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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,hd[N],nxt[N],to[N],ec;
int Hd[N],Nxt[N],To[N],tag[N],Ec;
int fa[N],cnt[N],dep[N],son[N],dfn[N],top[N],Time;
int stk[N],tp,cto[N];
ll ans;
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return y==A.y?x<A.x:y<A.y;}
};
vector<node> eg[N];
vector<node> nd;
vector<int> vish;

void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs(int u,int from,int d){
	fa[u]=from,cnt[u]=1,dep[u]=d;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u,d+1),cnt[u]+=cnt[v];
		if(cnt[son[u]]<cnt[v])son[u]=v;
	}
	return;
}

void dfs2(int u,int from,int d){
	dfn[u]=++Time,top[u]=d;
	if(son[u])dfs2(son[u],u,d);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

void Add(int u,int v,int i){
	if(u==v)return;
	if(v<u)swap(u,v);
	int c=0,L=0,R=eg[i].size()-1;
	while(L<=R){
		int M=(L+R)/2;
		if(eg[i][M]<node(u,v))L=M+1;
		else if(node(u,v)<eg[i][M])R=M-1;
		else{c=1;break;}
	}
//	printf("(%d %d %d)\n",u,v,c);
	Nxt[++Ec]=Hd[u],Hd[u]=Ec,To[Ec]=v,tag[Ec]=c;
	swap(u,v);
	Nxt[++Ec]=Hd[u],Hd[u]=Ec,To[Ec]=v,tag[Ec]=c;
	vish.push_back(u),vish.push_back(v);
	return;
}

void dfs3(int u,int from){
	cto[u]=cnt[u];
	for(int i=Hd[u],v;i;i=Nxt[i]){
		v=To[i];
		if(v==from)continue;
		dfs3(v,u);
		if(tag[i])cto[u]-=cnt[v];
		else cto[u]-=(cnt[v]-cto[v]);
	}
	return;
}

void dfs4(int u,int from,int fto){
	for(int i=Hd[u],v;i;i=Nxt[i]){
		v=To[i];
		if(v==from)continue;
		if(tag[i])ans+=1ll*(cto[u]+fto)*cto[v];//printf("(%d+%d)*%d    tot=%lld\n",cto[u],fto,cto[v],ans);
	}
	for(int i=Hd[u],v;i;i=Nxt[i]){
		v=To[i];
		if(v==from)continue;
//		fto+=cto[v];
	}
	fto+=cto[u];
	for(int i=Hd[u],v;i;i=Nxt[i]){
		v=To[i];
		if(v==from)continue;
		if(tag[i])dfs4(v,u,0);
		else dfs4(v,u,fto-cto[v]);
	}
	return;
}

signed main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		if(v<u)swap(u,v);
		eg[w].push_back(node(u,v));
		add(u,v),add(v,u);
	}
	dfs(1,0,1);
	dfs2(1,0,1);
	for(int i=1;i<=n;i++)if(eg[i].size()){
//		printf("color %d\n",i);
		nd.resize(0);
		sort(eg[i].begin(),eg[i].end());
		for(unsigned j=0;j<eg[i].size();j++){
			nd.push_back(node(eg[i][j].x,dfn[eg[i][j].x]));
			nd.push_back(node(eg[i][j].y,dfn[eg[i][j].y]));
		}
		sort(nd.begin(),nd.end());
		tp=0;
		stk[++tp]=1,stk[++tp]=nd[0].x;
		for(unsigned j=1;j<nd.size();j++){
			int u=nd[j].x;
			int mid=LCA(nd[j-1].x,u);
			while(tp>1&&dep[stk[tp-1]]>dep[mid])Add(stk[tp-1],stk[tp],i),--tp;
			if(dep[stk[tp]]>dep[mid])Add(mid,stk[tp],i),--tp;
			if(mid!=stk[tp])stk[++tp]=mid;stk[++tp]=u;
		}
		for(int j=1;j<tp;j++)Add(stk[j],stk[j+1],i);
		
		dfs3(1,0);
		dfs4(1,0,0);
		
		for(int j=1;j<=Ec;j++)Nxt[j]=To[j]=tag[j]=0;
		for(unsigned j=0;j<vish.size();j++)Hd[vish[j]]=0;
		Ec=0;
		vish.resize(0);
	}
	printf("%lld\n",ans);
	return 0;
}

