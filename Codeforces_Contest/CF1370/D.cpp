/********************************
*FileName:
*Author: Zimse
*Data:
*Description:
*Other:
********************************/

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
#include <cctype>

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define ll long long
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

const int Mod=998244353;//1000000007;
namespace Zimse{
inline int read(){int x=0,y=1;char c=gc();while(c<48||c>57){if(c==45)y=-1;c=gc();}while(c>=48&&c<=57)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;

const int N=1e6+7;
const int INF=1000114514;

int n,m,k,a[N],dis[N][2],vis[N],ans,mx[N],mxp[N],se[N];
vector<int> g[N];

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& _)const{return x>_.x;}
}s[N];
priority_queue<node> q;

void Dij(int S,int p){
	for(int i=1;i<=n;i++)vis[i]=0,dis[i][p]=INF;
	dis[S][p]=0,q.emplace(0,S);
	while(!q.empty()){
		int u=q.top().y;
		q.pop();
		if(vis[u]++)continue;
		for(unsigned i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(dis[u][p]+1<dis[v][p]){
				dis[v][p]=dis[u][p]+1;
				q.emplace(dis[v][p],v);
			}
		}
	}
	return;
}

bool check(int d){
	for(int i=1;i<=k;i++){
		int L=1,R=k,p=0;
		while(L<=R){
			int M=(L+R)/2;
			if(s[i].y+s[M].x>=d)p=M,L=M+1;
			else R=M-1;
		}
		int Mx=mx[p];
		if(mxp[p]==i)Mx=se[p];
		if(s[i].x+Mx>=d)return true;
	}
	return false;
}

signed main(){
	mx[0]=-INF;
	n=read(),m=read(),k=read();
	for(int i=1;i<=k;i++)a[i]=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),g[u].push_back(v),g[v].push_back(u);
	Dij(1,0),Dij(n,1);
	ans=dis[n][0];
	for(int i=1;i<=k;i++)s[i]=node(dis[a[i]][0],dis[a[i]][1]);
	sort(s+1,s+k+1);
	for(int i=1;i<=k;i++){
		mx[i]=mx[i-1],se[i]=se[i-1],mxp[i]=mxp[i-1];
		if(s[i].y>mx[i])se[i]=mx[i],mx[i]=s[i].y,mxp[i]=i;
		else if(s[i].y>se[i])se[i]=s[i].y;
	}
	int L=1,R=INF,res=0;
	while(L<=R){
		int M=(L+R)/2;
		if(check(M))res=M,L=M+1;
		else R=M-1;
	}
	ans=min(ans,res+1);
	_write(ans);
	return 0;
}

