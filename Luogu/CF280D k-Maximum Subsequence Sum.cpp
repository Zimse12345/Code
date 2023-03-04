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
// #define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)

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
int n,a[N],q,LL[N],RR[N];

struct node{
	int mx,mxl,mxr,mn,mnl,mnr,pmx,pmxpos,pmn,pmnpos,smx,smxpos,smn,smnpos,tag,sum;
}t[N];

node merge(node l,node r){
    node res;
    res.mx=l.mx,res.mxl=l.mxl,res.mxr=l.mxr;
	if(r.mx>res.mx)res.mx=r.mx,res.mxl=r.mxl,res.mxr=r.mxr;
	if(l.smx+r.pmx>res.mx)res.mx=l.smx+r.pmx,res.mxl=l.smxpos,res.mxr=r.pmxpos;
	res.mn=l.mn,res.mnl=l.mnl,res.mnr=l.mnr;
	if(r.mn<res.mn)res.mn=r.mn,res.mnl=r.mnl,res.mnr=r.mnr;
	if(l.smn+r.pmn<res.mn)res.mn=l.smn+r.pmn,res.mnl=l.smnpos,res.mnr=r.pmnpos;
	res.pmx=l.pmx,res.pmxpos=l.pmxpos;
	if(l.sum+r.pmx>res.pmx)res.pmx=l.sum+r.pmx,res.pmxpos=r.pmxpos;
	res.smx=r.smx,res.smxpos=r.smxpos;
	if(r.sum+l.smx>res.smx)res.smx=r.sum+l.smx,res.smxpos=l.smxpos;
	res.pmn=l.pmn,res.pmnpos=l.pmnpos;
	if(l.sum+r.pmn<res.pmn)res.pmn=l.sum+r.pmn,res.pmnpos=r.pmnpos;
	res.smn=r.smn,res.smnpos=r.smnpos;
	if(r.sum+l.smn<res.smn)res.smn=r.sum+l.smn,res.smnpos=l.smnpos;
	res.sum=l.sum+r.sum,res.tag=0;
    return res;
}

void build(int L,int R,int id){
	if(L==R){
		t[id].mx=t[id].mn=t[id].pmx=t[id].pmn=t[id].smx=t[id].smn=t[id].sum=a[L];
		t[id].mxl=t[id].mxr=t[id].mnl=t[id].mnr=t[id].pmxpos=t[id].pmnpos=t[id].smxpos=t[id].smnpos=L;
		t[id].tag=0;
	}
	else{
		build(L,M,Lid),build(M+1,R,Rid);
        t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

void pushdown(int id){
	if(t[id].tag){
		t[Lid].tag^=1,t[Rid].tag^=1,t[id].tag=0;
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
        t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

void uptval(int L,int R,int id,int x,int y){
    pushdown(id);
    if(L==R){
        t[id].mx=t[id].mn=t[id].pmx=t[id].pmn=t[id].smx=t[id].smn=t[id].sum=a[L];
		t[id].mxl=t[id].mxr=t[id].mnl=t[id].mnr=t[id].pmxpos=t[id].pmnpos=t[id].smxpos=t[id].smnpos=L;
		t[id].tag=0;
    }
    else{
        if(x<=M)uptval(L,M,Lid,x,y),pushdown(Rid);
        else uptval(M+1,R,Rid,x,y),pushdown(Lid);
        t[id]=merge(t[Lid],t[Rid]);
    }
    return;
}

node query(int L,int R,int id,int l,int r){
    pushdown(id);
    if(l<=L&&r>=R)return t[id];
    if(r<=M)return query(L,M,Lid,l,r);
    if(l>M)return query(M+1,R,Rid,l,r);
    return merge(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

signed main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    q=read();
    build(1,n,1);
    for(int i=1,op,l,r,k;i<=q;i++){
        op=read(),l=read(),r=read();
        if(op==1){
            k=read();
            int ans=0,_j=0;
            for(int j=1;j<=k;j++){
                node p=query(1,n,1,l,r);
                if(p.mx<=0)break;
                ans+=p.mx,++_j,LL[j]=p.mxl,RR[j]=p.mxr;
                update(1,n,1,p.mxl,p.mxr);
            }
            _write(ans);
            for(int j=1;j<=_j;j++)update(1,n,1,LL[j],RR[j]);
        }
        else{
            a[l]=r;
            uptval(1,n,1,l,r);
        }
    }
	return 0;
}
