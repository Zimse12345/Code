/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
 #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

int Mod;
namespace Zimse{
const int INF=1000114514;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
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

const int N=1024;
int n,C,a[N][N],det=1;
inline int ldl(int x,int k=Mod-2){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}

signed main(){
	n=read(),Mod=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=read()%Mod;
		}
	}
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=i;j<=n;j++)if(a[j][i]){t=j;break;}
		if(!t){
			printf("0\n");
			return 0;
		}
		for(int j=t;j<=n;j++)if(a[j][i]&&a[j][i]<a[t][i])t=j;
		if(t^i){
            for(int j=1;j<=n;j++)swap(a[i][j],a[t][j]);
            det=-det;
        }
		for(int j=i+1;j<=n;j++)if(i^j){
            if(a[j][i]>a[i][i]){
                for(int k=1;k<=n;k++)swap(a[i][k],a[j][k]);
                det=-det;
            }
			while(a[j][i]){
				int x=a[i][i]/a[j][i];
				for(int k=1;k<=n;k++)addmod(a[i][k],-a[j][k]*x%Mod+Mod),swap(a[i][k],a[j][k]);
                det=-det;
			}
		}
		det=(det*a[i][i])%Mod;
	}
	addmod(det,Mod);
	_write(det);
	return 0;
}
