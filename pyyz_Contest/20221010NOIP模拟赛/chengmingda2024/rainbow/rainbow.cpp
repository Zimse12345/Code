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
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const ll Mod=998244353;
//const int Mod=1000000007;
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
inline void addmod(ll& x,ll y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=2e6+7;

int n,m,a[N],vis[N],d[N],t,_d[N],_t;
ll ans=1;
vector<int> g[N];

void dfs(int u,int from){
	d[++t]=a[u],vis[u]=1;
	for(unsigned i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]||v==from)continue;
		dfs(v,u);
	}
	return;
}

ll sum[N],ad[N],len[N]; 
int cl[N],rev[N];
map<int,int> mp;

inline void pushdown(int id){
	if(cl[id]){
		sum[id]=0,rev[Lid]=rev[Rid]=ad[Lid]=ad[Rid]=0,cl[Lid]=cl[Rid]=1;
		cl[id]=0;
	}
	if(rev[id]){
		sum[id]=-sum[id],rev[Lid]^=1,rev[Rid]^=1,ad[Lid]=-ad[Lid],ad[Rid]=-ad[Rid];
		rev[id]=0;
	}
	if(ad[id]){
		addmod(sum[id],ad[id]*len[id]),addmod(ad[Lid],ad[id]),addmod(ad[Rid],ad[id]);
		ad[id]=0;
	}
	return;
}

void upt(int L,int R,int id,int p){
	len[id]=_d[R]-_d[L-1];
	pushdown(id);
	if(R<=p)rev[id]=1,pushdown(id);
	else if(L>p)cl[id]=1,pushdown(id);
	else{
		upt(L,M,Lid,p),upt(M+1,R,Rid,p);
		sum[id]=(sum[Lid]+sum[Rid])%Mod;
	}
	return;
}

void update(int L,int R,int id,int l,int r,int ty,ll val){
	len[id]=_d[R]-_d[L-1];
	pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R){
		if(ty==1)cl[id]=1;
		else if(ty==2)rev[id]=1;
		else ad[id]=val;
		pushdown(id);
	}
	else{
		update(L,M,Lid,l,r,ty,val),update(M+1,R,Rid,l,r,ty,val);
		sum[id]=(sum[Lid]+sum[Rid])%Mod;
	}
	return;
}

ll query(int L,int R,int id,int l,int r){
	len[id]=_d[R]-_d[L-1];
	pushdown(id);
	if(r<L||R<l)return 0;
	if(l<=L&&r>=R)return sum[id];
	return (query(L,M,Lid,l,r)+query(M+1,R,Rid,l,r))%Mod;
}

ll calc(){
	for(int i=1;i<=t;i++)_d[i]=d[i];
	_t=t+1,_d[_t]=1;
	sort(_d+1,_d+_t+1);
	int tt=0;
	for(int i=1;i<=_t;i++)if(_d[i]!=_d[i-1])_d[++tt]=_d[i];
	_t=tt;
	mp.clear();
	for(int i=1;i<=_t;i++)mp[_d[i]]=i;
	for(int i=1;i<=t;i++)d[i]=mp[d[i]];
	update(1,_t,1,1,_t,1,0);
	update(1,_t,1,1,d[1],3,1);
	for(int i=2;i<=t;i++){
		ll s=sum[1];
		upt(1,_t,1,d[i]);
		update(1,_t,1,1,d[i],3,s);
	}
	return sum[1];
}

ll _calc(){
	update(1,_t,1,1,_t,1,0);
	update(1,_t,1,1,mp[1],3,1);
	for(int i=2;i<=t;i++){
		ll s=sum[1];
		upt(1,_t,1,d[i]);
		update(1,_t,1,1,d[i],3,s);
	}
	return query(1,_t,1,mp[1],mp[1]);
}

signed main(){
//	ifile("rainbow.in");
//	ofile("rainbow.out");
	
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)if(g[i].size()<=1&&!vis[i]){
		t=0;
		dfs(i,0);
		ans=ans*calc()%Mod;
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		t=_t=0;
		dfs(i,0);
		int mn=INF,pos=0;
		for(int j=1;j<=t;j++)if(d[j]<mn)mn=d[j],pos=j;
		for(int j=pos;j<=t;j++)_d[++_t]=d[j];
		for(int j=1;j<pos;j++)_d[++_t]=d[j];
		for(int j=1;j<=t;j++)d[j]=_d[j];
		ll d1=d[1];
		ans=(ans*(calc()-_calc()*d1%Mod))%Mod;
	}
	addmod(ans,Mod);
	printf("%lld\n",ans);
	return 0;
}


