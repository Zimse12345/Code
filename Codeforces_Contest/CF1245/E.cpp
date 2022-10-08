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

int a[16][16],t[16][16];
double r[N];
double f[16][16],g[16][16];

signed main(){
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			a[i][j]=read();
			if(i&1)t[i][1]=1;
			else t[i][10]=1;
		}
	}
	for(int i=1;i<=6;i++){
		double s=1,t=double(6-i)/6.0;
		for(int j=1;j<=10000;j++){
			r[i]+=s,s*=t;
		}
	}
	for(int i=1;i<=10;i++){
		if(i&1){
			for(int j=1;j<=10;j++){
				if(i==1&&j==1)continue;
				double s=0;
				int k=0;
				for(int d=1;d<=6;d++){
					int to=j-d;
					if(to>0)s+=f[i][to],k+=1;
					else{
						if(i==1)continue; 
						k+=1;
						s+=f[i-1][1-to];
					}
				}
				s/=double(k);
				f[i][j]=r[k]+s;
				g[i][j]=f[i][j];
				if(i-a[i][j]>=1&&g[i-a[i][j]][j]<f[i][j])f[i][j]=g[i-a[i][j]][j];
			}
		}
		else{
			for(int j=10;j>=1;j--){
				double s=0;
				int k=0;
				for(int d=1;d<=6;d++){
					int to=j+d;
					if(to<=10)s+=f[i][to],k+=1;
					else{
						k+=1;
						s+=f[i-1][10-(to-11)];
					}
				}
				s/=double(k);
				f[i][j]=r[k]+s;
				g[i][j]=f[i][j];
				if(i-a[i][j]>=1&&g[i-a[i][j]][j]<f[i][j])f[i][j]=g[i-a[i][j]][j];
			}
		}
	}
	printf("%.7lf\n",f[10][1]);
	return 0;
}


