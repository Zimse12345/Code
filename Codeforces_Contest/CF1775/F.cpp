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

int Mod;
namespace Zimse{
const int INF=1000114514;
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

int T,ty,x,ans,f[1000][1000],F[2000];

signed main(){
	T=read(),ty=read();
	if(ty==2){
		Mod=read();
		f[0][0]=1;
		for(int i=3;i<1100;i++){
			F[i]=i*(i-1)*(i-2)/2/3%Mod;
		}
		for(int i=1;i<800;i++){
			for(int j=0;j<800;j++)if(f[i-1][j]){
				for(int k=0;j+k*i<800;k++){
					addmod(f[i][j+k*i],f[i-1][j]*F[k+3]);
				}
			}
		}
	}
	
	while(T--){
		x=read();
		int mn=INF;
		ans=0;
		if(ty==1){
			for(int i=1;i<=x;i++){
				int j=x/i;
				if(x%i!=0)++j;
				_min(mn,i+j);
			}
			for(int i=1;i<=x;i++){
				int j=x/i;
				if(x%i!=0)++j;
				if(j<i)break;
				if(mn==i+j){
					int rm=i*j-x;
					if(ty==1){
						printf("%lld %lld\n",i,j);
						for(int I=1;I<=i;I++){
							for(int J=1;J<=j;J++){
								if(I==1&&J<=rm)pc('.');
								else pc('#');
							}
							pc(10);
						}
						break; 
					}
				}
			}
		}
		if(ty==2){
			int s=sqrt(x);
			if(s*s<x)++s;
			int s2=s;
			if((s2-1)*s>=x)s2--;
			int ans=0;
			for(int t=0;(s+t)*(s2-t)>=x;t++){
				addmod(ans,f[799][(s+t)*(s2-t)-x]*(s+t==s2-t?1:2));
			}
			printf("%lld %lld\n",(s+s2)*2,ans);
		}
	}
    return 0;
}


