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

#define int long long
#define M ((L+R)>>1)
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e10+7;
int n,m,_l,_r,val[N],hd[N],nxt[N*2],to[N*2],cl[N*2],ec,ans=-INF;
int rt,sz,nx,vis[N],cnt[N];
int mx[N*4],ch[N*4][2],tot;
int Val[N],Len[N],t,vval[N],llen[N],tt;
stack<int> rbs;
inline int newnode(){if(!rbs.empty()){int id=rbs.top();mx[id]=-INF,Lid=Rid=0,rbs.pop();return id;}return ++tot;}
inline void add(int u,int v,int c){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,cl[ec]=c;return;}
struct node{int x,y;node(int x,int y):x(x),y(y){}
bool operator < (const node& A)const{return x<A.x;}};

void findrt(int u,int from){
	cnt[u]=1;
	int ms=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]||v==from)continue;
		findrt(v,u),cnt[u]+=cnt[v],ms=max(ms,cnt[v]);
	}
	ms=max(ms,sz-cnt[u]);
	if(ms<nx)nx=ms,rt=u;
	return;
}

void ins(int L,int R,int& id,int x,int y){
	if(!id)id=newnode();
	if(L==R)mx[id]=max(mx[id],y);
	else{
		if(x<=M)ins(L,M,Lid,x,y);
		else ins(M+1,R,Rid,x,y);
		mx[id]=max(mx[Lid],mx[Rid]);
	}
	return;
}

void del(int id){
	if(!id)return;
	del(Lid),del(Rid),rbs.push(id);
	return;
}

int query(int L,int R,int id,int l,int r){
	if((!id)||R<l||r<L)return -INF;
	if(l<=L&&r>=R)return mx[id];
	return max(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

void dfs(int u,int from,int V,int fc,int len){
	Val[++t]=V,Len[t]=len;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]||v==from)continue;
		if(cl[i]==fc)dfs(v,u,V,fc,len+1);
		else dfs(v,u,V+val[cl[i]],cl[i],len+1);
	}
	return;
}

void calc(int u){
	int rt1=0,rt2=0;
	ins(0,n,rt1,0,0);
	vector<node> ch;
	for(int i=hd[u];i;i=nxt[i])if(!vis[to[i]])ch.push_back(node(cl[i],to[i]));
	sort(ch.begin(),ch.end());
	for(unsigned i=0;i<ch.size();i++){
		if(i!=0&&ch[i].x!=ch[i-1].x){
			del(rt2),rt2=0;
			for(int j=1;j<=tt;j++)ins(0,n,rt1,llen[j],vval[j]);
			tt=0;
		}
		t=0,dfs(ch[i].y,u,val[ch[i].x],ch[i].x,1);
		for(int j=1;j<=t;j++){
			int lenL,lenR;
			if(Len[j]<=_l)lenL=_l-Len[j],lenR=_r-Len[j];
			else if(Len[j]<=_r)lenL=0,lenR=_r-Len[j];
			else continue;
			ans=max(ans,max(query(0,n,rt1,lenL,lenR)+Val[j],query(0,n,rt2,lenL,lenR)+Val[j]-val[ch[i].x]));
		}
		for(int j=1;j<=t;j++)ins(0,n,rt2,Len[j],Val[j]),vval[++tt]=Val[j],llen[tt]=Len[j];
	}
	del(rt1),del(rt2),tt=0;
	return;
}

void divide(int u){
	vis[u]=1;
	calc(u);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		sz=cnt[v],nx=INF,findrt(v,u);
		divide(rt);
	}
	return;
}

signed main(){
	n=read(),m=read(),_l=read(),_r=read();
	for(int i=0;i<N*4;i++)mx[i]=-INF;
	for(int i=1;i<=m;i++)val[i]=read();
	for(int i=1,u,v,c;i<n;i++)u=read(),v=read(),c=read(),add(u,v,c),add(v,u,c);
	sz=n,nx=INF,findrt(1,0);
	divide(rt);
	printf("%lld\n",ans);
	return 0;
}

