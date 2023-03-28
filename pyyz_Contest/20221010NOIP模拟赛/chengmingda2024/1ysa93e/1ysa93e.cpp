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

const int N=1024;
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

int n,m,dis[N][N],vis[N][N],p[N][N],sum,cnt,tag;
char s[N][N];

struct node{
	int x,y,d;
	node(int x=0,int y=0,int d=0):x(x),y(y),d(d){}
	bool operator < (const node& _)const{return d>_.d;}
};
priority_queue<node> q;

bool check(int x){
	cnt=0,tag=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)if(dis[i][j]>x)q.push(node(i,j,0));
	}
	while(!q.empty()){
		int ux=q.top().x,uy=q.top().y,di=q.top().d;
		q.pop();
		if(p[ux][uy]++)continue;
		++cnt;
		if(di<x){
			for(int w=0;w<4;w++){
				int vx=ux+dx[w],vy=uy+dy[w];
				if(1<=vx&&vx<=n&&1<=vy&&vy<=m){
					q.push(node(vx,vy,di+1));
				}
				else tag=0;
			}
		}
	}
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)p[i][j]=0;
	return tag&&cnt==sum;
}

signed main(){
	ifile("1ysa93e.in");
	ofile("1ysa93e.out");
	
	n=read(),m=read();
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.')q.push(node(i,j,0));
			else dis[i][j]=INF,++sum;
		}
	}
	while(!q.empty()){
		int ux=q.top().x,uy=q.top().y;
		q.pop();
		if(vis[ux][uy]++)continue;
		for(int w=0;w<4;w++){
			int vx=ux+dx[w],vy=uy+dy[w];
			int _d=dis[ux][uy]+(s[vx][vy]=='#'?1:0);
			if(1<=vx&&vx<=n&&1<=vy&&vy<=m&&_d<dis[vx][vy]){
				dis[vx][vy]=_d;
				q.push(node(vx,vy,_d));
			}
		}
	}
	int L=1,R=min(n,m),ans=0;
	while(L<=R){
		if(check(M))ans=M,L=M+1;
		else R=M-1;
	}
	_write(ans);
	return 0;
}


