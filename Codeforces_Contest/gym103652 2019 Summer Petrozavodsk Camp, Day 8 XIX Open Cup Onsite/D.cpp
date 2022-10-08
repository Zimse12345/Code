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

struct subnode{int x,y,z;
subnode(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
};
vector<subnode> edges;
namespace Solve{
	const int N=6018;
	int n,m,q,tot,tot2,qwq;
	int ff[N],stk[N],stk1[N],stk2[N],dep[N],v[N],v2[N],dis[N];
	map<int,int> mp;
	struct Edge{int to,next,fl;}e[N<<4],e2[N<<4];
	void add(int x,int y,int z){;//printf("(%d %d)\n",x,y);
		e[tot].to=y; e[tot].fl=z;
		e[tot].next=v[x]; v[x]=tot++;
	}
	void add2(int x,int y,int z){
		e2[++tot2].to=y; e2[tot2].fl=z;
		e2[tot2].next=v2[x]; v2[x]=tot2;
	}
	void bfs(int s){
		memset(dep,0,sizeof(dep));
		int head(1),tail(0); stk[++tail]=s; dep[s]=1;
		while(head<=tail){
			int w=stk[head++];
			for(int p=v[w];p>=0;p=e[p].next){
				int kp=e[p].to;
				if(e[p].fl>0 && !dep[kp]){
					dep[kp]=dep[w]+1;
					stk[++tail]=kp;
				}
			}
		}
	}
	int dfs(int s,int t,int sur){
		if(s==t || !sur)return sur;
		int flow=0;
		for(int p=v[s];p>=0;p=e[p].next){
			int kp=e[p].to;
			if(dep[kp]!=dep[s]+1 || e[p].fl<=0)continue;
			int tmp=dfs(kp,t,min(sur,e[p].fl));
				sur-=tmp; flow+=tmp;
			e[p].fl-=tmp; e[p^1].fl+=tmp;
			if(!sur)break;
		}
		if(!flow)dep[s]=-1;
		return flow;
	}
	int dinic(int s,int t){
		int res=0;
		for(int i=1;i<tot;i+=2)e[i].fl=e[i^1].fl=(e[i].fl+e[i^1].fl)>>1;
		while(bfs(s),dep[t]>0)res+=dfs(s,t,1e9+7);
		return res;
	}
	void build(int *f,int sz){ 
		if(sz==1)return;
		int cut=dinic(f[0],f[1]);
		add2(f[0],f[1],cut); add2(f[1],f[0],cut);
		int p(0),q(0);
		for(int i=0;i<sz;i++){
			if(dep[f[i]])stk1[p++]=f[i];
			else stk2[q++]=f[i];
		}
		for(int i=0;i<p;i++)f[i]=stk1[i];
		for(int i=0;i<q;i++)f[p+i]=stk2[i];
		if(p)build(f,p);
		if(q)build(f+p,q);
	}
	void dfs2(int x,int fa,int D){
		for(int p=v2[x];p;p=e2[p].next){
			int kp=e2[p].to;
			if(kp!=fa){
				dis[kp]=min(D,e2[p].fl);
				dfs2(kp,x,dis[kp]);
			}
		}
	}
	void clear(){
		for(int i=1;i<=n;i++)v[i]=v2[i]=0; tot=tot2=0; mp.clear();
	}
	void push(int x){if(!mp[x])mp[x]=++qwq;}
	int solve(vector<subnode> ms){
		m=ms.size(); qwq=0;
		for(int i=0;i<m;i++)
			push(ms[i].x),push(ms[i].y);
		n=qwq;
//		cerr<<"n="<<n<<endl;
		for(int i=0;i<m;i++)
			ms[i].x=mp[ms[i].x],ms[i].y=mp[ms[i].y];
		memset(v,-1,sizeof(v));
		memset(v2,0,sizeof v2);
		for(int i=0;i<m;i++){
			int u=ms[i].x,o=ms[i].y;
			if(u>o)continue;
			add(u,o,1); add(o,u,1);
		}
		for(int i=1;i<=n;i++)ff[i-1]=i;
		build(ff,n);
		int ans=0;
		for(int i=1;i<=n;i++){
			dis[i]=0; dfs2(i,-1,1000);
			for(int j=1;j<=n;j++)ans+=dis[j];
		}
		clear();
		return ans/2;
	}
}

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int _n,_m,T,vis[N*N];
char s[N][N];

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
};
node getpos(int x,int y){
	int X,Y;
	if(y&1)X=4*x-1;
	else X=4*x+1;
	Y=6*y-1;
	return node(X,Y);
}
int getid(int x,int y){
	return (x-1)*_m+y;
}
char getChar(int x,int y){
	node pos=getpos(x,y);
	return s[pos.x][pos.y];
}

vector<int> G[N*N];
void link(int u,int v){//printf("(%d %d)\n",u,v);
	G[u].push_back(v);
	return;
}

void Make_Graph(){
    const int MAX_LEN=1000;
    int n,m;
	scanf("%d%d",&n,&m);getchar();
	_n=n,_m=m;
    int w=4*n+1;
    if(m>1)w+=2;
    for(int i=1;i<=w;i++){
//    	printf("[%d/%d]\n",i,w);
        fgets(s[i]+1,MAX_LEN,stdin);
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		node pos=getpos(i,j);
    		int X=pos.x,Y=pos.y;
    		if(getChar(i,j)=='*'){
    			if(j%2==0){
    				if(j>1){
    					if(getChar(i,j-1)=='*'){//左上 
    						if(s[X-1][Y-3]==' '){
    							link(getid(i,j),getid(i,j-1));
							}
						}
						if(i<n&&getChar(i+1,j-1)=='*'){//左下 
							if(s[X+1][Y-3]==' '){
								link(getid(i,j),getid(i+1,j-1));
							}
						}
					}
					if(j<m){
						if(getChar(i,j+1)=='*'){//右上 
							if(s[X-1][Y+3]==' '){
    							link(getid(i,j),getid(i,j+1));
							}
						}
						if(i<n&&getChar(i+1,j+1)=='*'){//右下 
							if(s[X+1][Y+3]==' '){
    							link(getid(i,j),getid(i+1,j+1));
							}
						}
					}
					if(i>1&&getChar(i-1,j)=='*'){//上 
						if(s[X-2][Y]==' '){
							link(getid(i,j),getid(i-1,j));
						}
					}
					if(i<n&&getChar(i+1,j)=='*'){//下 
						if(s[X+2][Y]==' '){
							link(getid(i,j),getid(i+1,j));
						}
					}
				}
				else{
    				if(j>1){
    					if(i>1&&getChar(i-1,j-1)=='*'){//左上 
    						if(s[X-1][Y-3]==' '){
    							link(getid(i,j),getid(i-1,j-1));
							}
						}
						if(getChar(i,j-1)=='*'){//左下 
							if(s[X+1][Y-3]==' '){
								link(getid(i,j),getid(i,j-1));
							}
						}
					}
					if(j<m){
						if(i>1&&getChar(i-1,j+1)=='*'){//右上 
							if(s[X-1][Y+3]==' '){
    							link(getid(i,j),getid(i-1,j+1));
							}
						}
						if(getChar(i,j+1)=='*'){//右下 
							if(s[X+1][Y+3]==' '){
    							link(getid(i,j),getid(i,j+1));
							}
						}
					}
					if(i>1&&getChar(i-1,j)=='*'){//上 
						if(s[X-2][Y]==' '){
							link(getid(i,j),getid(i-1,j));
						}
					}
					if(i<n&&getChar(i+1,j)=='*'){//下 
						if(s[X+2][Y]==' '){
							link(getid(i,j),getid(i+1,j));
						}
					}
				}
			}
		}
	}
    return;
}

vector<subnode> es;
void dfs(int u){
	vis[u]=1;
	for(int i=0,v;i<signed(G[u].size());i++){
		v=G[u][i];
		es.push_back(subnode(u,v,1));
		if(!vis[v]){
			dfs(v);
		}
	}
	return;
}

signed main(){
    T=read();
    int qwqwq=0;
    while(T--){
        Make_Graph();
        int nn=_n*_m;
		int ans=0;
        for(int i=1;i<=nn;i++)if(!vis[i]){
        	es.clear();
        	dfs(i);
        	if(es.size())ans+=Solve::solve(es);
		}
        for(int i=1;i<=nn;i++)G[i].clear(),vis[i]=0;
		printf("Case #%d: %d\n",++qwqwq,ans);
    }
    
    return 0;
}

