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
#define int long long
#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
#define Lid ch[id][0]
#define Rid ch[id][1]

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

const int N=8e6+7;

int n,ch[N][2],tot,rt,tag[N],_tag[N],ans,f[100],p2[100],sum,_sum;
int v[2];

inline int lowbit(int x){
	return x&(-x);
}

inline int popcnt(int x){
	int res=0;
	while(x)x-=lowbit(x),++res;
	return res; 
}

inline void ins(int L,int R,int& id,int l,int r,int P){
	if(r<L||R<l||tag[id])return;
	if(!id)id=++tot;
	if(l<=L&&r>=R&&!_tag[id]){
		int len=R-L+1;
		if(len==1){
			int i=(popcnt(L)&1ll);
			ans+=v[i^1],++v[i],ans+=_sum/2;
		}
		else _sum+=len,ans+=len/2*sum+f[P];
		sum+=len;
		tag[id]=_tag[id]=1;
	}
	else{
		ins(L,M,Lid,l,r,P-1),ins(M+1,R,Rid,l,r,P-1);
		tag[id]=(tag[Lid]&tag[Rid]);
		_tag[id]=(_tag[Lid]|_tag[Rid]);
	}
	return;
}

signed main(){
	ifile("sequence.in");
	ofile("sequence.out");
	
	f[1]=1,p2[0]=1;
	for(int i=1;i<=35;i++)p2[i]=p2[i-1]*2;
	for(int i=2;i<=35;i++)f[i]=(f[i-1]*2+p2[i-1]*p2[i-2]);
	n=read();
	int L=0,R=p2[32]-1;
	for(int i=1,l,r;i<=n;i++){
		l=read(),r=read();
		ins(L,R,rt,l,r,32);
		_write(ans);
	}
	return 0;
}


