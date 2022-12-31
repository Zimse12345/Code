/********************************
*FileName:
*Author: Zimse
*Data: 2022-12-
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
#define pb push_back
#define ll long long
 #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

using namespace std;

namespace Zimse{
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
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1000007;

int T,n,a[N],b[N],vis[N],ans;
queue<int> q;
multiset<int> s[N];

void dfs(int u){
	if(vis[u]++)return;
	dfs(*s[u].begin());
	s[u].erase(s[u].begin());
	if(s[u].size())dfs(*s[u].begin());
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		ans=1;
		for(int i=1;i<=n;i++)a[i]=read(),vis[i]=0,s[i].clear();
		for(int i=1;i<=n;i++)b[i]=read();
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i])s[a[i]].insert(b[i]),s[b[i]].insert(a[i]);
			else ans=(ans*n)%Mod,vis[a[i]]=1;
		}
		int tag=1;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++)if(!vis[i]){
			if(!s[i].size())tag=0;
			if(s[i].size()==1)q.push(i);
		}
		if(!tag)ans=0;
		else{
			while(!q.empty()){
				int x=q.front();
				q.pop();
				if(!s[x].size()){
					tag=0;
					break;
				}
				int y=*s[x].begin();
				s[y].erase(x);
				s[x].erase(y);
				vis[x]=1;
				if(s[y].size()==1&&vis[y]==0)q.push(y);
			}
			if(!tag)ans=0;
			else for(int i=1;i<=n;i++){
				if(!vis[i])dfs(i),ans=(ans*2)%Mod;
			}
		}
		_write(ans);
	}
    return 0;
}


