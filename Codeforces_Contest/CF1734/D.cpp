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

int T,n,k,a[N];

struct node{
	int x,y,z;
	node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
}l[N],r[N];
int lt,rt;

signed main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=k+1,s=0,mn=0;i<=n;i++){
			s+=a[i],mn=min(mn,s);
			if(s>0)r[++rt]=node(s,mn,i),s=mn=0;
		}
		for(int i=k-1,s=0,mn=0;i>=1;i--){
			s+=a[i],mn=min(mn,s);
			if(s>0)l[++lt]=node(s,mn,i),s=mn=0;
		}
		int L=k,R=k,rm=a[k];
		int pl=1,pr=1;
		while(pl<=lt||pr<=rt){
			if(pl<=lt&&-l[pl].y<=rm)rm+=l[pl].x,L=l[pl].z,++pl;
			else if(pr<=rt&&-r[pr].y<=rm)rm+=r[pr].x,R=r[pr].z,++pr;
			else break;
		}
		lt=rt=0;
		int Rm=rm,tag=1;
		while(L>1){
			--L;
			rm+=a[L];
			if(rm<0){
				tag=0;
				break;
			}
		}
		if(tag){
			yes;
			continue;
		}
		tag=1,rm=Rm;
		while(R<n){
			++R;
			rm+=a[R];
			if(rm<0){
				tag=0;
				break;
			}
		}
		_ck(tag);
	}
	return 0;
}


