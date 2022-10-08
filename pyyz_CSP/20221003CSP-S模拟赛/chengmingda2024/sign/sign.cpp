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

int n,D[N],A[N],B[N],val[N],vt,Vt,ac[N],bc[N];
map<int,int> V;

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& _)const{
		if(x==_.x)return y<_.y;
		return x<_.x;
	}
};
map<node,int> Cnt;

signed main(){
	ifile("sign.in");
	ofile("sign.out");
	
	n=read();
	for(int i=1;i<=n;i++){
		D[i]=read(),A[i]=D[i]+read(),B[i]=D[i]-read();
		val[++vt]=A[i],val[++vt]=B[i];
	}
	sort(val+1,val+vt+1);
	for(int i=1;i<=vt;i++)if(i==1||val[i]!=val[i-1])val[++Vt]=val[i],V[val[i]]=Vt;
	for(int i=1;i<=n;i++){
		A[i]=V[A[i]],B[i]=V[B[i]];
//		printf("node(%d %d)\n",A[i],B[i]);
	}
	int pa=0,pb=0,mx=0,cnt=0;
	for(int l=1,r=1;r<=n;r++){
		if(A[r]!=A[r-1])pa=r-1;
		if(B[r]!=B[r-1])pb=r-1;
		++ac[A[r]],++bc[B[r]],++Cnt[node(A[r],B[r])];
		while(r-l+1!=ac[A[r]]+bc[B[pa]]-Cnt[node(A[r],B[pa])]
			&&r-l+1!=ac[A[pb]]+bc[B[r]]-Cnt[node(A[pb],B[r])]){
			--ac[A[l]],--bc[B[l]],--Cnt[node(A[l],B[l])];
			++l;
		}
//		printf("(%d %d) pa=%d pb=%d\n",l,r,pa,pb);
		if(r-l+1>mx)mx=r-l+1,cnt=1;
		else if(r-l+1==mx)++cnt;
	}
	printf("%d %d\n",mx,cnt);
	return 0;
}


