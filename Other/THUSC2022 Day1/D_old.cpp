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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7,B=11;
int n,m,X,hd[N],fa[N],nxt[N],to[N],ec,a[N],bd[N];
int dep[N],cnt[N],son[N],dfn[N],Id[N],top[N],Time;
int fx[N],hs[N],lh[N],rh[N],ah[N],htot,Ans[N];
char s[N],p[N],_p[N];
int _opt[N],_x[N],_y[N];
map<int,int> val;
vector<char> ss;
vector< vector<char> > S;
vector<int> pos[N];
int sum[11][N];
inline void addedge(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

inline void db(int& x){x-=(x&(-x));return;}
inline void ub(int& x){x+=(x&(-x));return;}
inline void add(int id,int x,int v){for(;x<=n;ub(x))sum[id][x]+=v;return;}
inline int qsum(int id,int x){int res=0;for(;x;db(x))res+=sum[id][x];return res;}
inline int ldl(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}

void dfs(int u,int from,int d){
	dep[u]=d,cnt[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u,d+1),cnt[u]+=cnt[v];
		if(cnt[son[u]]<cnt[v])son[u]=v;
	}
	return;
}

void dfs2(int u,int from,int t){
	dfn[u]=++Time,Id[Time]=u,top[u]=t;
	if(son[u])dfs2(son[u],u,t);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||v==son[u])continue;
		dfs2(v,u,v);
	}
	return;
}

int getlca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

int goup(int x,int dis){
	while(dep[x]-dep[fa[top[x]]]<=dis){
		dis-=(dep[x]-dep[fa[top[x]]]);
		x=fa[top[x]];
	}
	x=Id[dfn[x]-dis];
	return x;
}

int ffindval(int l,int r,int v){
	//printf("+ find  %d %d %d\n",l,r,v);
	int L=0,R=pos[v].size()-1,_L=INF,_R=-INF;
	while(L<=R){
		int M=(L+R)/2;
		if(pos[v][M]>=l)_L=M,R=M-1;
		else L=M+1;
	}
	L=0,R=pos[v].size()-1;
	while(L<=R){
		int M=(L+R)/2;
		if(pos[v][M]<=r)_R=M,L=M+1;
		else R=M-1;
	}
	return max(0ll,_R-_L+1);
}

int findval(int x,int dis,int v){
	v=val[v];
	int res=0;
	while(dep[x]-dep[fa[top[x]]]<=dis){
		dis-=(dep[x]-dep[fa[top[x]]]);
		res+=ffindval(dfn[top[x]],dfn[x],v);
		x=fa[top[x]];
	}
	if(dis)res+=ffindval(dfn[x]-dis+1,dfn[x],v);
	return res;
}

signed main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	n=read(),m=read(),X=read();
	for(int i=2;i<=n;i++)fa[i]=read(),addedge(fa[i],i),addedge(i,fa[i]);
	dfs(1,0,1);
	dfs2(1,0,1);
	scanf("%s",s+1);
	bool all1=1;
	for(int i=2;i<=n;i++){
		a[i]=s[i-1]-'0';
		if(a[i]!=1)all1=0;
	}
	
	for(int i=2;i<=n;i++){
		hs[i]=(hs[fa[i]]*B+a[i])%Mod;
		if(dep[i]>X){
			fx[i]=goup(i,X);
			hs[i]=(hs[i]-ldl(B,X)*a[fx[i]])%Mod;
			hs[i]=(hs[i]+Mod)%Mod;
		}
	}
	
	if(X==1){
		for(int i=2;i<=n;i++)add(a[i],dfn[i],1);
		while(m--){
			int opt=read(),x=read(),y=read();
			scanf("%s",s+1),s[1]-='0';
			if(opt==1){
				if(dep[x]<dep[y])x=y;
				add(a[x],dfn[x],-1);
				a[x]=s[1];
				add(a[x],dfn[x],1);
			}
			else{
				int cnt=0;
				while(top[x]^top[y]){
					if(dep[top[x]]<dep[top[y]])swap(x,y);
					cnt+=qsum(s[1],dfn[x])-qsum(s[1],dfn[top[x]]-1),x=fa[top[x]];
				}
				if(dep[x]>dep[y])swap(x,y);
				cnt+=qsum(s[1],dfn[y])-qsum(s[1],dfn[x]);
				printf("%lld\n",cnt);
			}
		}
		return 0;
	}
	
	bool upt_tag=0;
	ss.push_back(0);
	S.push_back(ss);
	for(int i=1;i<=m;i++){
		_opt[i]=read(),_x[i]=read(),_y[i]=read();
		if(_opt[i]==1)upt_tag=1;
		scanf("%s",s+1);
		ss.resize(0);
		for(int j=1;j<=X;j++){
			ss.push_back(s[j]);
			if(s[j]!='1')all1=0;
		}
		S.push_back(ss);
	}
	if(all1){
		for(int I=1;I<=m;I++){
			int opt=_opt[I],x=_x[I],y=_y[I];
			int lca=getlca(x,y);
			if(opt==2){
				printf("%lld\n",max(0ll,dep[x]+dep[y]-dep[lca]-dep[lca]-X+1));
			}
		}
		return 0;
	}
//	upt_tag=1;
	if(!upt_tag){
		for(int I=1,h;I<=m;I++){
			h=0;
			for(int i=0;i<X;i++)h=(h*B+S[I][i]-'0')%Mod;
			lh[I]=h;
			h=0;
			for(int i=X-1;i>=0;i--)h=(h*B+S[I][i]-'0')%Mod;
			rh[I]=h;
			ah[++htot]=lh[I],ah[++htot]=rh[I];
			
			int x=_x[I],y=_y[I],lca=getlca(x,y);
			int _dep=dep[lca]+X-1;
			if(dep[x]>_dep)x=goup(x,dep[x]-_dep);
			if(dep[y]>_dep)y=goup(y,dep[y]-_dep);
			for(int i=1;i<=X;i++)s[i]=S[I][i-1]-'0';
			s[X+1]=0;
			int t=0,_t=0,cnt=0;
			while(x!=lca)p[++t]=a[x],x=fa[x];
			while(y!=lca)_p[++_t]=a[y],y=fa[y];
			for(int i=_t;i>0;i--)p[++t]=_p[i];
			for(int i=2,j=0;i<=X;i++){
				while(j&&s[j+1]!=s[i])j=bd[j];
				bd[i]=s[j+1]==s[i]?++j:j;
			}
			for(int i=1,j=0;i<=t;i++){
				while(j&&s[j+1]!=p[i])j=bd[j];
				if(s[j+1]==p[i])++j;
				if(j==X)++cnt;
			}
			Ans[I]+=cnt;
		}
		sort(ah+1,ah+htot+1);
		ah[0]=-1;
		int _tot=0;
		for(int i=1;i<=htot;i++)if(ah[i]!=ah[i-1]){
			ah[++_tot]=ah[i];
			val[ah[i]]=_tot;
		}
		for(int i=1;i<=n;i++){
			if(val[hs[i]])pos[val[hs[i]]].push_back(dfn[i]);//printf("%d +%d\n",hs[i],dfn[i]);
		}
		for(int i=1;i<=_tot;i++)sort(pos[i].begin(),pos[i].end());
		for(int I=1;I<=m;I++){
//			printf("[%d %d %d]\n",I,lh[I],rh[I]);
			int x=_x[I],y=_y[I],lca=getlca(x,y);
			int _dep=dep[lca]+X-1;
			if(dep[x]>_dep)Ans[I]+=findval(x,dep[x]-_dep,rh[I]);
			if(dep[y]>_dep)/*printf("(%d %d)\n",y,dep[y]-_dep),*/Ans[I]+=findval(y,dep[y]-_dep,lh[I]);
			printf("%lld\n",Ans[I]);
		}
		return 0;
	}
	else{
		for(int I=1;I<=m;I++){
			int opt=_opt[I],x=_x[I],y=_y[I];
			int lca=getlca(x,y);
			for(int i=1;i<=X;i++)s[i]=S[I][i-1]-'0';
			s[X+1]=0;
			if(opt==1){
				int t=1;
				while(x!=lca)a[x]=s[t++],x=fa[x];
				t=X;
				while(y!=lca)a[y]=s[t--],y=fa[y];
			}
			else{
				int t=0,_t=0,cnt=0;
				while(x!=lca)p[++t]=a[x],x=fa[x];
				while(y!=lca)_p[++_t]=a[y],y=fa[y];
				for(int i=_t;i>0;i--)p[++t]=_p[i];
				for(int i=2,j=0;i<=X;i++){
					while(j&&s[j+1]!=s[i])j=bd[j];
					bd[i]=s[j+1]==s[i]?++j:j;
				}
				for(int i=1,j=0;i<=t;i++){
					while(j&&s[j+1]!=p[i])j=bd[j];
					if(s[j+1]==p[i])++j;
					if(j==X)++cnt;
				}
				printf("%lld\n",cnt);
			}
		}
	}
	return 0;
}

