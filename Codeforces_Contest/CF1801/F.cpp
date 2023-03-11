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
 #define int long long
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

const int N=10000007;

int n,k,a[N],vis[N],v[N],m;
double f[N];

signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=k;i++)vis[k/i+(k%i?1:0)]=1;
	for(int i=1;i<=k;i++)if(vis[i])v[++m]=i;
	f[1]=1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(a[i]>200000&&a[i]>k/2&&v[j]*(n-i+1)>k)continue;
			int _j=1;
			for(int l=1,r;l<=a[i];){
				r=a[i]/(a[i]/l);
				int L=_j,R=m;
				while(L<=R){
					int M=(L+R)/2;
					if(v[j]*r>=v[M])_j=M,L=M+1;
					else R=M-1;
				}
				double p=1.0/double(a[i])*double(a[i]/r);
				f[_j]=max(f[_j],f[j]*p);
				l=r+1;
				if((a[i]>200000&&a[i]>k/2&&v[_j]*(n-i+1)>k)||_j>=m)break;
			}
		}
	}
	printf("%.9lf\n",f[m]*double(k));
    return 0;
}


