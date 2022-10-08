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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,aa[N],bb[N],xx[N],yy[N],sz[N];

struct Tree{
	int siz,res;
	vector<vector<int> > ch;
	vector<int> dis;
	
	void init_tree(int SZ){
		ch.resize(0),siz=SZ;
		vector<int> emp;
		emp.resize(0);
		for(int i=0;i<=siz;i++)ch.push_back(emp),dis.push_back(0);
	}
	
	void link(int u,int v){
		ch[u].push_back(v),ch[v].push_back(u);
		return;
	}
	
	void dfs0(int u,int from){
		for(unsigned i=0;i<ch[u].size();i++){
			int v=ch[u][i];
			if(v==from)continue;
			dfs0(v,u),dis[u]=max(dis[u],dis[v]+1);
		}
		return;
	}
	
	void dfs1(int u,int from,int fdis){
		res=(res+max(dis[u],fdis))%Mod;
//		printf("(%d %d %d)\n",u,from,max(dis[u],fdis));
		int mx=-INF,pos=0,se=-INF;
		for(unsigned i=0;i<ch[u].size();i++){
			int v=ch[u][i];
			if(v==from)continue;
			if(dis[v]>mx)se=mx,mx=dis[v],pos=v;
			else if(dis[v]>se)se=dis[v];
		}
//		printf("     [%d %d %d]\n",u,mx,se);
		for(unsigned i=0;i<ch[u].size();i++){
			int v=ch[u][i];
			if(v==from)continue;
			if(v==pos)dfs1(v,u,max(fdis,se+1)+1);
			else dfs1(v,u,max(fdis,mx+1)+1);
		}
		return;
	}
	
	int sol(){
		res=0;
		dfs0(1,0);
		dfs1(1,0,0);
		return res;
	}
}t[N];

signed main(){
	int ttag=1;
	n=read(),sz[0]=1;
	for(int i=1;i<=n;i++){
		aa[i]=read(),bb[i]=read(),xx[i]=read(),yy[i]=read();
		sz[i]=sz[aa[i]]+sz[bb[i]];
		if(!(xx[i]==sz[aa[i]]&&yy[i]==1))ttag=0;
	}
	if(ttag){
		for(int i=1;i<=n;i++){
			int x=sz[i],ans=0;
			if(x&1ll)ans+=x/2;
			int from=(x+1)/2,to=from+x/2-1;
			ans=(ans+(from+to)%Mod*(to-from+1)%Mod)%Mod;
			printf("%lld\n",ans);
		}
		return 0;
	}
	t[0].init_tree(1);
	for(int i=1;i<=n;i++){
		t[i].init_tree(sz[i]);
		for(int u=1;u<=sz[aa[i]];u++){
			t[i].ch[u]=t[aa[i]].ch[u];
		}
		for(int u=1;u<=sz[bb[i]];u++){
			for(unsigned id=0;id<t[bb[i]].ch[u].size();id++){
				if(u+sz[aa[i]]<t[bb[i]].ch[u][id]+sz[aa[i]])t[i].link(u+sz[aa[i]],t[bb[i]].ch[u][id]+sz[aa[i]]);
			}
		}
		t[i].link(xx[i],yy[i]+sz[aa[i]]);
		printf("%lld\n",t[i].sol()%Mod);
	}
	return 0;
}

