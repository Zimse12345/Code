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
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,H1=1e9+7,INF=1e9+7;
int T,n,m,h1[N],ans;
int hd[N],nxt[N*2],to[N*2],ec;
int sz,rs,rt,cnt[N],vis[N]; 
int LH[N],RH[N],Len[N],tot;
char s[N],tmp[N];
int wl[N],wr[N],kl[N],kr[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void findrt(int u,int from){
	int ms=0;
	cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]||v==from)continue;
		findrt(v,u),cnt[u]+=cnt[v];
		ms=max(ms,cnt[v]);
	}
	ms=max(ms,sz-cnt[u]);
	if(ms<rs)rs=ms,rt=u;
	return;
}

void dfs(int u,int from,int len,int lh,int rh){
	lh=lh*H1+s[u];if(len!=1)rh+=s[u]*h1[len-2];
	Len[++tot]=len,LH[tot]=lh,RH[tot]=rh;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]||v==from)continue;
		dfs(v,u,len+1,lh,rh);
	}
	return;
}

void calc(int u,int t,char c){
	int res=0;
	tot=0,dfs(u,0,1,0,0);
	if(t==-1)for(int i=1;i<=tot;i++)LH[i]=LH[i]+h1[Len[i]]*c,RH[i]=RH[i]*H1+s[u],++Len[i];
	for(int i=1;i<=tot;i++){
		if(LH[i]==wl[Len[i]])++kl[Len[i]%m];
		if(RH[i]==wr[Len[i]-1])++kr[(Len[i]-1)%m];
	}
	for(int i=1;i<=tot;i++)if(Len[i]%m)res+=kl[Len[i]%m]*kr[m-Len[i]%m],kl[Len[i]%m]=kr[m-Len[i]%m]=0;
	
	res+=kl[0]*kr[0];
	for(int i=1;i<=tot;i++)kr[(Len[i]-1)%m]=0;
	kl[0]=kr[0]=0;
	ans+=res*t;
	return;
}

void divide(int u){
	vis[u]=1;
	calc(u,1,'\0');
	for(int i=hd[u];i;i=nxt[i])if(!vis[to[i]])calc(to[i],-1,s[u]);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		sz=cnt[v],rs=INF,findrt(v,u);
		divide(rt);
	}
	return;
}

signed main(){
	h1[0]=1;
	for(int i=1;i<N;i++)h1[i]=h1[i-1]*H1;
	T=read();
	while(T--){
		n=read(),m=read(),ec=ans=0;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)hd[i]=vis[i]=0;
		for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
		scanf("%s",tmp+1);
		for(int i=1,p1=1,p2=m;i<=n;i++){
			wl[i]=wl[i-1]+h1[i-1]*tmp[p1],wr[i]=wr[i-1]*H1+tmp[p2];
			++p1,--p2;
			if(!p2)p1=1,p2=m;
		}
		sz=n,rs=INF,findrt(1,0);
		divide(rt);
		printf("%lld\n",ans);
	}
	
	return 0;
}

