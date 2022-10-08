/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-14
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

const int Mod=19260817;//1000000007;
namespace Zimse{
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
}using namespace Zimse;

const int N=4e5+7;
const int INF=1000114514;

int n,a[N];
int T,ch[N*32][2],tot;
bool sz[N*32],cnt[32],ans[32];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0,pos=0;j<26;j++){
			if(a[i]&(1<<j)){
				cnt[j]^=1;
				if(!ch[pos][1])ch[pos][1]=++tot;
				pos=ch[pos][1],sz[pos]^=1;
			}
			else{
				if(!ch[pos][0])ch[pos][0]=++tot;
				pos=ch[pos][0],sz[pos]^=1;
			}
		}
	}
	int k=0;
	for(int i=1;i<=n;i++){
		for(int j=0,pos=0;j<26;j++){
			if((a[i]+k)&(1<<j)){
				cnt[j]^=1,pos=ch[pos][1],sz[pos]^=1;
			}
			else{
				pos=ch[pos][0],sz[pos]^=1;
			}
		}
		while(k<a[i]){
			for(int j=0,pos=0;j<26;j++){
				cnt[j]^=sz[ch[pos][0]]^sz[ch[pos][1]];
				T=ch[pos][0],ch[pos][0]=ch[pos][1],ch[pos][1]=T;
				pos=ch[pos][0];
				if(!pos)break;
			}
			++k;
		}
		for(int j=0;j<26;j++)ans[j]^=cnt[j];
	}
	int Ans=0;
	for(int j=0;j<26;j++)if(ans[j])Ans+=(1<<j);
	_write(Ans);
	return 0;
}

