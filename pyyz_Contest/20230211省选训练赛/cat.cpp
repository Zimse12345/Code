/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

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
#define pb push_back
#define ll long long
// #define int long long
#define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
#define Lid ch[id][0]
#define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=4e5+7,SZ=26;
int n,tot,pre,ans,f[N],rt[N],ch[N*32][2],cnt;
char s[N];

struct node{
	int to[SZ],len,link;
}t[N];
vector<int> g[N];

void ins(int& id,int L,int R,int x){
	if(!id)id=++cnt;
	if(L!=R){
		if(x<=M)ins(Lid,L,M,x);
		else ins(Rid,M+1,R,x);
	}
	return;
}

int merge(int id1,int id2){
	if(!id1||!id2)return id1+id2;
	int id=++cnt;
	Lid=merge(ch[id1][0],ch[id2][0]),Rid=merge(ch[id1][1],ch[id2][1]);
	return id;
}

int findpos(int id,int L,int R){
	if(L==R)return L;
	if(Lid)return findpos(Lid,L,M);
	return findpos(Rid,M+1,R);
}

int findR(int id,int L,int R,int x){
	if(!id||x<=L)return 0;
	if(L==R)return L;
	int r=findR(Rid,M+1,R,x);
	return r?r:findR(Lid,L,M,x);
}

void ins(int c){
	int id=++tot,p=pre;
	t[id].len=t[p].len+1;
	ins(rt[id],1,n,t[id].len);
	while(p!=-1&&!t[p].to[c])t[p].to[c]=id,p=t[p].link;
	if(p==-1)t[id].link=0;
	else{
		int q=t[p].to[c];
		if(t[q].len==t[p].len+1)t[id].link=q;
		else{
			int cp=++tot;
			t[cp]=t[q],t[cp].len=t[p].len+1;
			while(p!=-1&&t[p].to[c]==q)t[p].to[c]=cp,p=t[p].link;
			t[q].link=t[id].link=cp;
		}
	}
	pre=id;
	return;
}

void dfs(int u){
	for(unsigned i=0;i<g[u].size();i++){
		dfs(g[u][i]);
		rt[u]=merge(rt[u],rt[g[u][i]]);
	}
	return;
}

void dp(int u,int p){
	int pos=findpos(rt[u],1,n),q=findR(rt[p],1,n,pos);
    f[u]=f[p];
	if(!p||(q&&pos-t[u].len+t[p].len<=q))++f[u],p=u;
    _max(ans,f[u]);
	for(unsigned i=0;i<g[u].size();i++)dp(g[u][i],p);
	return;
}

signed main(){
	// ifile("cat.in");
	// ofile("cat.out");
	
	t[0].link=-1;
	scanf("%s",s+1);
    n=strlen(s+1);
	for(int i=1;i<=n;i++)ins(s[i]-'a');
	for(int i=1;i<=tot;i++)g[t[i].link].pb(i);
	dfs(0);
	for(unsigned i=0;i<g[0].size();i++)dp(g[0][i],0);
	_write(ans);
	return 0;
}
