/********************************
*FileName:
*Author: Zimse
*Data: 2022-10-
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

const int N=1000007;

int n,q,a[N],pre[N],ans[N],cnt0[N];

struct query{
	int l,id;
	query(int l=0,int id=0):l(l),id(id){}
};
vector<query> qu[N];
map<int,int> p0,p1;

signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,l,r;i<=q;i++){
		ans[i]=-1;
		l=read(),r=read();
		qu[r].pb(query(l,i));
	}
	p0[0]=0;
	for(int r=1,l=0;r<=n;r++){
		pre[r]=pre[r-1]^a[r];
		cnt0[r]=cnt0[r-1]+(a[r]==0?1:0);
		for(unsigned i=0;i<qu[r].size();i++){
			l=qu[r][i].l;
			if(pre[r]^pre[l-1])continue;
			int f=-1;
			if(r&1){
				if(p0.find(pre[r])!=p0.end())f=p0[pre[r]];
			}
			else{
				if(p1.find(pre[r])!=p1.end())f=p1[pre[r]];
			}
			if(f>=l-1){
				if(cnt0[r]-cnt0[l-1]==r-l+1)ans[qu[r][i].id]=0;
				else if(((r-l+1)&1)||a[l]==0||a[r]==0)ans[qu[r][i].id]=1;
				else ans[qu[r][i].id]=2;
			}
		}
		if(r&1)p1[pre[r]]=r;
		else p0[pre[r]]=r;
	}
	for(int i=1;i<=q;i++)_write(ans[i]);
    return 0;
}


