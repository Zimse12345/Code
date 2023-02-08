/************************
*FileName:
*Author: Zimse
*Data: 2023-01-
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
 #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

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

const int N=1000007;

int T,n,a[N],fa[N],sz[N],ans,ring[N],vis[N];
vector<int> ch[N];

void dfs(int u){
	sz[u]=1;
	for(unsigned i=0;i<ch[u].size();i++){
		dfs(ch[u][i]);
		sz[u]+=sz[ch[u][i]];
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read(),ans=0;
		for(int i=1;i<=n;i++)a[i]=read(),ring[i]=vis[i]=0;
		for(int i=1;i<=n;i++)if(!vis[i]){
			int x=i;
			while(1<=x&&x<=n){
				if(vis[x]==i){
					ring[i]=1;
					break;
				}
				vis[x]=i;
				x+=a[x];
			}
		}
		for(int i=1;i<=n;i++)if(!ring[vis[i]]){
			int f=i+a[i];
			if(f<1||f>n)f=0;
			ch[f].pb(i),fa[i]=f;
		}
		dfs(0);
		if(ring[1]){
			int x=1;
			while(vis[x]){
				vis[x]=0;
				ans+=max(0ll,-x+n+1)+max(0ll,x)+sz[0]-1;
				x+=a[x];
			}
		}
		else{
			int p=1,rm=n;
			while(p){
				--rm;
				ans+=sz[0]-1-sz[p]+max(0ll,-p+n+1)+max(0ll,p);
				p=fa[p];
			}
			ans+=(n*2+1)*rm;
		}
		
		_write(ans);
		for(int i=0;i<=n;i++)ch[i].resize(0);
	}
    return 0;
}


