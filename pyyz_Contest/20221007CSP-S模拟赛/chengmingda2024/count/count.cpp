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

namespace Zimse{
const int Mod=998244353;
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
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1e6+7;

int n,k,hd[N],nxt[N],to[N],ec;
ll ans;
int len[N],f[4001][4001][3],g[4001][3];

inline void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

void dp(int u,int from){
	f[u][0][0]=1,f[u][0][1]=1;
	len[u]=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dp(v,u);
		for(int x=0;x<=len[u];x++){
			for(int y=0;y<=len[v];y++){
				for(int I=0;I<3;I++)if(f[u][x][I]){
					for(int J=1;J<3;J++)if(f[v][y][J]){
						if(I+J>3||(I&&J&&x+y+1>k))continue;
						if(I+J==3){
							ll A=f[u][x][I],B=f[v][y][J];
							ans+=A*B;
							continue;
						}
						int d=0;
						if(I)_max(d,x);
						if(J)_max(d,y+1);
						g[d][I+J]+=f[u][x][I]*f[v][y][J];
					}
				}
			}
		}
		len[u]=max(len[u],len[v]+1);
		for(int j=0;j<=len[u];j++){
			for(int t=0;t<3;t++)f[u][j][t]+=g[j][t],g[j][t]=0;
		}
	}
	return;
}

signed main(){
	ifile("count.in");
	ofile("count.out");
	
	n=read(),k=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dp(1,0);
	printf("%lld\n",ans*6);
	return 0;
}


