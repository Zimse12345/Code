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
#define M ((L+R)/2)
#define Lid ch[id][1]
#define Rid ch[id][0]

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
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

const int N=1000007;
int n,k,a[N];
signed ch[N*2][2],tot=1;

struct node{
    signed mxl,mxr,mnl,mnr,pmxpos,pmnpos,smxpos,smnpos,tag;
	int mx,mn,pmx,pmn,smx,smn,sum;
}t[N*2];

void pushup(int id){
    t[id].mx=t[Lid].mx,t[id].mxl=t[Lid].mxl,t[id].mxr=t[Lid].mxr;
	if(t[Rid].mx>t[id].mx)t[id].mx=t[Rid].mx,t[id].mxl=t[Rid].mxl,t[id].mxr=t[Rid].mxr;
	if(t[Lid].smx+t[Rid].pmx>t[id].mx)t[id].mx=t[Lid].smx+t[Rid].pmx,t[id].mxl=t[Lid].smxpos,t[id].mxr=t[Rid].pmxpos;
	t[id].mn=t[Lid].mn,t[id].mnl=t[Lid].mnl,t[id].mnr=t[Lid].mnr;
	if(t[Rid].mn<t[id].mn)t[id].mn=t[Rid].mn,t[id].mnl=t[Rid].mnl,t[id].mnr=t[Rid].mnr;
	if(t[Lid].smn+t[Rid].pmn<t[id].mn)t[id].mn=t[Lid].smn+t[Rid].pmn,t[id].mnl=t[Lid].smnpos,t[id].mnr=t[Rid].pmnpos;
	t[id].pmx=t[Lid].pmx,t[id].pmxpos=t[Lid].pmxpos;
	if(t[Lid].sum+t[Rid].pmx>t[id].pmx)t[id].pmx=t[Lid].sum+t[Rid].pmx,t[id].pmxpos=t[Rid].pmxpos;
	t[id].smx=t[Rid].smx,t[id].smxpos=t[Rid].smxpos;
	if(t[Rid].sum+t[Lid].smx>t[id].smx)t[id].smx=t[Rid].sum+t[Lid].smx,t[id].smxpos=t[Lid].smxpos;
	t[id].pmn=t[Lid].pmn,t[id].pmnpos=t[Lid].pmnpos;
	if(t[Lid].sum+t[Rid].pmn<t[id].pmn)t[id].pmn=t[Lid].sum+t[Rid].pmn,t[id].pmnpos=t[Rid].pmnpos;
	t[id].smn=t[Rid].smn,t[id].smnpos=t[Rid].smnpos;
	if(t[Rid].sum+t[Lid].smn<t[id].smn)t[id].smn=t[Rid].sum+t[Lid].smn,t[id].smnpos=t[Lid].smnpos;
	t[id].sum=t[Lid].sum+t[Rid].sum;
    return;
}

void build(int L,int R,int id){
	if(L==R){
		t[id].mx=t[id].mn=t[id].pmx=t[id].pmn=t[id].smx=t[id].smn=t[id].sum=a[L];
		t[id].mxl=t[id].mxr=t[id].mnl=t[id].mnr=t[id].pmxpos=t[id].pmnpos=t[id].smxpos=t[id].smnpos=L;
		t[id].tag=0;
	}
	else{
        Lid=++tot,Rid=++tot;
		build(L,M,Lid),build(M+1,R,Rid);
        pushup(id);
	}
	return;
}

void pushdown(int id){
	if(t[id].tag){
		if(Lid)t[Lid].tag^=1,t[Rid].tag^=1;
        t[id].tag=0;
		swap(t[id].mx,t[id].mn);
		t[id].mx*=-1,t[id].mn*=-1;
		swap(t[id].mxl,t[id].mnl);
		swap(t[id].mxr,t[id].mnr);
		swap(t[id].pmx,t[id].pmn);
		t[id].pmx*=-1,t[id].pmn*=-1;
		swap(t[id].smx,t[id].smn);
		t[id].smx*=-1,t[id].smn*=-1;
		swap(t[id].pmxpos,t[id].pmnpos);
		swap(t[id].smxpos,t[id].smnpos);
		t[id].sum*=-1;
	}
	return;
}

void update(int L,int R,int id,int l,int r){
	pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R)t[id].tag=1,pushdown(id);
	else{
		update(L,M,Lid,l,r),update(M+1,R,Rid,l,r);
		pushup(id);
	}
	return;
}

signed main(){
    n=read(),k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    build(1,n,1);
    int ans=0;
    for(int i=1;i<=k;i++){
        if(t[1].mx<=0)break;
        ans+=t[1].mx;
        update(1,n,1,t[1].mxl,t[1].mxr);
    }
    _write(ans);
	return 0;
}
