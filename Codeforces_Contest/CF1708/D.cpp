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

const int Mod=998244353;//1000000007;
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
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}

const int N=1e6+7;
const int INF=1000114514;

int T,n,a[N];

struct node{
	int val,cnt;
	node(int val=0,int cnt=0):val(val),cnt(cnt){};
	bool operator < (const node& _)const{return val<_.val;}
};
vector<node> f;

signed main(){
	T=read();
	while(T--){
		n=read();
		f.resize(0);
		for(int i=1;i<=n;i++)a[i]=read();
		int c=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]&&c){
				f.emplace_back(a[i-1],c);
				c=1;
			}
			else ++c;
		}
		f.emplace_back(a[n],c);
		int ans=0;
		while(f.size()>1){
			++ans;
			sort(f.begin(),f.end());
			int m=0,c0=0;
			for(unsigned i=1;i<f.size();i++)a[++m]=f[i].val-f[i-1].val;
			for(unsigned i=0;i<f.size();i++)c0+=f[i].cnt-1;
			sort(a+1,a+m+1);
			f.resize(0);
			int C=0;
			for(int i=1;i<=m;i++){
				if(a[i]!=a[i-1]&&C){
					f.emplace_back(a[i-1],C);
					C=1;
				}
				else ++C;
			}
			if(C)f.emplace_back(a[m],C);
			if(c0)f.emplace_back(0,c0);
		}
		ans=f[0].val;
		if(f[0].cnt>1)ans=0;
		_write(ans);
	}
	return 0;
}


