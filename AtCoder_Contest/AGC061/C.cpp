// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1000007;

int n,a[N],b[N],l[N],r[N],f[N];
vector<int> s[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=read();
	for(int i=1,p=1;i<=n;i++){
		while(b[p]<a[i])++p;
		l[i]=p;
	}
	for(int i=n,p=n;i>=1;i--){
		while(a[p]>b[i])--p;
		r[i]=p,s[p].pb(l[i]);
	}
	f[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=2*f[i-1]%Mod;
		for(unsigned j=0;j<s[i].size();j++)_mod(f[i],-f[s[i][j]-1]);
	}
	_mod(f[n],Mod);
	_wri(f[n]);
    return 0;
}


