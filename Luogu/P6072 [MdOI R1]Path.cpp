#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>

#define ll long long
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=1004535809,INF=1e9+7;
int n,hd[N],nxt[N],to[N],c[N],ec;
int fa[N],cnt[N],dis[N];
int rt[N],ch[N*64][2],tg[N*64],tot;
int ans1[N],ans2[N],U,V,Ans,lca;
int son[N],_ans,RT,ANS;
stack<int> rbs;
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,c[ec]=w;return;}
inline int newnode(){if(!rbs.empty()){int id=rbs.top();rbs.pop(),Lid=Rid=tg[id]=0;return id;}return ++tot;}
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return x<A.x;}};

node query(int id,int x){
	int res=0;
	for(int i=30;i>=0;i--){
		if(x&(1<<i)){if(Lid)id=Lid,res|=(1<<i);else id=Rid;}
		else        {if(Rid)id=Rid,res|=(1<<i);else id=Lid;}
	}
	return node(res,tg[id]);
}

void ins(int& Rt,int x,int y){
	if(!Rt)Rt=newnode();
	int id=Rt;
	for(int i=30;i>=0;i--){
		if(x&(1<<i)){if(!Rid)Rid=newnode();id=Rid;}
		else        {if(!Lid)Lid=newnode();id=Lid;}
	}
	tg[id]=y;
	return;
}

void merge(int& id,int _id,int i,int v,int u){
	if(i<0){
		node p=query(id,v);
		ans1[u]=max(ans1[u],p.x),ins(id,v,tg[_id]);
		if(p.x>Ans)Ans=p.x,U=p.y,V=tg[_id],lca=u;
		return;
	}
	if(ch[_id][0])merge(id,ch[_id][0],i-1,v,u);
	if(ch[_id][1])merge(id,ch[_id][1],i-1,v|(1<<i),u);
	rbs.push(_id);
	return;
}

void dfs1(int u,int from,int d){
	dis[u]=d,fa[u]=from,cnt[u]=1;
	vector<node> ch;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		ch.push_back(node(-cnt[v],v)),dfs1(v,u,d^c[i]),cnt[u]+=cnt[v];
	}
	sort(ch.begin(),ch.end());
	if(ch.size())rt[u]=rt[ch[0].y];
	node p=query(rt[u],dis[u]);
	ans1[u]=p.x;
	if(p.x>Ans)Ans=p.x,U=u,V=p.y,lca=u;
	ins(rt[u],dis[u],u);
	for(int i=1,v;i<signed(ch.size());i++){
		v=ch[i].y;
		merge(rt[u],rt[v],30,0,u);
	}
	return;
}

void Ins(int u){
	_ans=max(_ans,query(RT,dis[u]).x),ins(RT,dis[u],u);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==fa[u])continue;
		Ins(v);
	}
	return;
}

void sol(int u,int g){
	ans2[u]=_ans;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==fa[u])continue;
		if(son[u]!=v)Ins(v);
	}
	_ans=max(_ans,query(RT,dis[u]).x),ins(RT,dis[u],u);
	if(u!=g)sol(son[u],g);
}

signed main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	dfs1(1,0,0);
	for(int i=1;i<=n;i++)ans2[i]=Ans;
	int u=U;
	while(u!=1)son[fa[u]]=u,u=fa[u];
	_ans=0,sol(1,U);
	for(int i=1;i<=n;i++)son[i]=0;
	u=V;
	while(u!=1)son[fa[u]]=u,u=fa[u];
	RT=_ans=0,sol(1,V);
	for(int i=1;i<=n;i++)if(cnt[i]>0&&n-cnt[i]>0)ANS=max(ANS,ans1[i]+ans2[i]);
	printf("%d\n",ANS);
	return 0;
}

