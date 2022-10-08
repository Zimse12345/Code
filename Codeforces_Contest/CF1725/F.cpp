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

const int Mod=998244353;//1000000007;
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

const int N=1e6+7;
const int INF=1000114514;

int n,L[N],R[N],q,ans[N];

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& _)const{return x<_.x;}
};
vector<node> p;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)L[i]=read(),R[i]=read();
	for(int t=1,k=0;t<=2000000000;t*=2,k++){
		for(int i=1;i<=n;i++){
			int len=R[i]-L[i]+1;
//			printf("<%d,%d>\n",len,t);
			if(t<=len)++ans[k];
			else if(L[i]/t==R[i]/t){
				int l=L[i]%t,r=R[i]%t;//printf("A[%d,%d %d,%d]\n",l,r,L[i],R[i]);
				p.emplace_back(l,1);
				p.emplace_back(r+1,-1);
			}
			else{
				int l=L[i]%t,r=R[i]%t;//printf("B[%d,%d %d,%d]\n",l,r,L[i],R[i]);
				p.emplace_back(0,1);
				p.emplace_back(r+1,-1);
				p.emplace_back(l,1);
				p.emplace_back(t,-1);
			}
		}
		sort(p.begin(),p.end());
		int s=0,mx=0;
		for(unsigned i=0,j;i<p.size();){
			j=i;
			while(j+1<p.size()&&p[j+1].x==p[j].x)++j;
			for(int I=i;I<=j;I++)s+=p[I].y;//printf("%d (%d %d)\n",t,p[I].x,p[I].y);
			mx=max(mx,s);
			i=j+1;
		}
		ans[k]+=mx;
		p.resize(0);
	}
	q=read();
	while(q--){
		int z=read();
		int t=1,k=0;
		while(!(z&t))t*=2,++k;
		_write(ans[k]);
	}
	return 0;
}


