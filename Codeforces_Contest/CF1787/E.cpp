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
// #define int long long
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

int T,n,k,x,rm[N],tot,vis[N];

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
};
vector<node> ans;

signed main(){
	T=read();
	while(T--){
		n=read(),k=read(),x=read();
		int X=0;
		for(int i=1;i<=n;i++)X^=i,vis[i]=0;
		if((k&1)&&(X!=x)){
			no;
			continue;
		}
		else if((k%2==0)&&X!=0){
			no;
			continue;
		}
		int d=1,tag=0;
		for(int i=1;i<=30;i++)if(x&(1<<i))d=(1<<i);
		d*=2;
		for(int l=0,r;l<=n;){
			r=min(n,l+d-1);
			for(int i=l;i<=l+d/2-1&&i<=n;i++){
				if((i^x)<=n){
					ans.pb(node(i,i^x));
				}
				else tag=1;
			}
			l=r+1;
		}
		if(int(ans.size())+tag<k)no;
		else{
			yes;
			for(int i=0;i<k-1;i++){
				if(ans[i].x==0)printf("1 %d\n",ans[i].y);
				else printf("2 %d %d\n",ans[i].x,ans[i].y);
				vis[ans[i].x]=1,vis[ans[i].y]=1;
			}
			int xx=0;
			for(int i=1;i<=n;i++)if(!vis[i])rm[++tot]=i,xx^=i;
			if(xx!=x)while(1);
			printf("%d ",tot);
			for(int i=1;i<=tot;i++)printf("%d ",rm[i]);
			pc(10);
		}
		ans.resize(0),tot=0;
	}
    return 0;
}


