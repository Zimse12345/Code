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

int T,n,v[N],fac[N];

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& _)const{return x<_.x;}
};
priority_queue<node> q;

signed main(){
	T=read();
	fac[0]=fac[1]=1;
	for(int i=2;i<N;i++)fac[i]=fac[i-1]+fac[i-2];
	while(T--){
		n=read();
		int sum=0;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++){
			v[i]=read();
			sum+=v[i];
			q.emplace(v[i],i);
		}
		int nw=-1,tag=1;
		while(sum>0)sum-=fac[++nw];
		if(sum<0)no;
		else{
			int pre=0;
			for(int i=nw;i>=0;i--){
				node a=q.top(),b;
				q.pop();
				if(!q.empty())b=q.top(),q.pop();
				if(a.x>=fac[i]&&a.y!=pre){
					a.x-=fac[i],pre=a.y;
				}
				else if(b.x>=fac[i]){
					b.x-=fac[i],pre=b.y;
				}
				else tag=0;
				q.push(a),q.push(b);
			}
			_ck(tag);
		}
	}
	return 0;
}


