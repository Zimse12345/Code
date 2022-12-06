/********************************
*FileName:
*Author: Zimse
*Data: 2022-10-
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
#define pb push_back
#define ll long long
 #define int long long
 #define M ((L+R)/2)
 #define Lid (id<<1)
 #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

using namespace std;

namespace Zimse{
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
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=200007;

int T,n,z[N],ans;
char s[N];

int mn[N*8],ad[N*8],sum[N*8],cnt[N*8];

void build(int L,int R,int id){
	mn[id]=ad[id]=0;
	if(L!=R)build(L,M,Lid),build(M+1,R,Rid);
	return;
}

void pushdown(int id){
	if(ad[id]){
		mn[id]+=ad[id],ad[Lid]+=ad[id],ad[Rid]+=ad[id],ad[id]=0;
	}
	return;
}

void add(int L,int R,int id,int l,int r,int v){
	pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R)ad[id]+=v,pushdown(id);
	else{
		add(L,M,Lid,l,r,v),add(M+1,R,Rid,l,r,v);
		mn[id]=min(mn[Lid],mn[Rid]);
	}
	return;
}

int findL(int L,int R,int id){
	if(mn[id]>0)return 0;
	if(L==R)return L;
	int res=findL(L,M,Lid);
	if(res)return res;
	return findL(M+1,R,Rid);
}

void Build(int L,int R,int id){
	int mid=L+(R-L)/2;
	sum[id]=cnt[id]=0;
	if(L!=R)Build(L,mid,Lid),Build(mid+1,R,Rid);
	return;
}

void Add(int L,int R,int id,int x){
	int mid=L+(R-L)/2;
	sum[id]+=x,cnt[id]+=1;
	if(L!=R){
		if(x<=M)Add(L,mid,Lid,x);
		else Add(mid+1,R,Rid,x);
	}
	return;
}

int qsum(int L,int R,int id,int x){
	int mid=L+(R-L)/2;
	if(R<x)return 0;
	if(L>=x)return sum[id];
	return qsum(L,mid,Lid,x)+qsum(mid+1,R,Rid,x);
}

int qcnt(int L,int R,int id,int x){
	int mid=L+(R-L)/2;
	if(R<x)return 0;
	if(L>=x)return cnt[id];
	return qcnt(L,mid,Lid,x)+qcnt(mid+1,R,Rid,x);
}

signed main(){
	T=read();
	while(T--){
		ans=0;
		n=read();
		scanf("%s",s+1);
		build(1,n,1);
		Build(-n,n,1);
		int sumY=0,B=0;
		
		for(int i=1;i<=n;i++){
			z[i]=0;
			if(s[i]=='(')add(1,n,1,1,i,1);
			else{
				int p=findL(1,n,1);
				add(1,n,1,1,p-1,-1),sumY+=i-p+1;
			}
			Add(-n,n,1,B);
			if(s[i]=='(')--B;
			else ++B;
			int Sum=qsum(-n,n,1,B),Cnt=qcnt(-n,n,1,B);
			ans+=sumY+Sum-Cnt*B;
		}
		_write(ans);
	}
    return 0;
}


