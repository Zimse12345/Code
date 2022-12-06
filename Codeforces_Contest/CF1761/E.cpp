/********************************
*FileName:
*Author: Zimse
*Data: 2022-11-
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
// #define int long long
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
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=4096;

int T,n,vis[N],deg[N],a[N],tot;
char s[N][N];
vector<int> nd;

void dfs(int u){
	if(vis[u]++)return;
	nd.push_back(u);
	for(int i=1;i<=n;i++)if(s[u][i]=='1')dfs(i);
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
			for(int j=1;j<=n;j++)if(s[i][j]=='1')++deg[i];
		}
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++)if(!vis[i]){
			++cnt;
			nd.resize(0);
			dfs(i);
			int mn=INF,p=0,sz=nd.size();
			for(int j=0;j<sz;j++){
				if(deg[nd[j]]<mn)mn=deg[nd[j]],p=nd[j];
			}
			if(deg[p]<sz-1||deg[p]==0){
				ans=p;
			}
			else a[++tot]=i;
		}
		if(cnt==1)printf("0\n");
		else if(ans)printf("1\n%d\n",ans);
		else{
			if(tot>2)printf("2\n%d %d\n",a[1],a[2]);
			else{
				if(deg[a[1]]>deg[a[2]])swap(a[1],a[2]);
				printf("%d\n",deg[a[1]]+1);
				printf("%d ",a[1]);
				for(int i=1;i<=n;i++)if(s[a[1]][i]=='1')printf("%d ",i);
				printf("\n");
			}
		}
		tot=0;
		for(int i=1;i<=n;i++)deg[i]=vis[i]=0;
	}
    return 0;
}


