/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-
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
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
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
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=4e6+7;

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return x<_.x;}
};

int n,m,ans[N],is_qry[N];
int ad[N],mx[N],tr[N];
vector<node> upt[N];
vector<int> qry[N];

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x,int y){x+=100;for(;x<N;ub(x))tr[x]+=y;return;}
inline int qs(int x){x+=100;int res=0;for(;x;db(x))res+=tr[x];return res;}

void add_upt(int L,int R,int id,int l,int r,node x){
    if(r<L||R<l)return;
    if(l<=L&&r>=R)upt[id].push_back(x);
    else add_upt(L,M,Lid,l,r,x),add_upt(M+1,R,Rid,l,r,x);
    return;
}

void pushdown(int id){
    if(ad[id]!=0){
        mx[id]+=ad[id],ad[Lid]+=ad[id],ad[Rid]+=ad[id];
        ad[id]=0;
    }
    return;
}

void update(int L,int R,int id,int l,int r,int x){
    pushdown(id);
    if(r<L||R<l)return;
    if(l<=L&&r>=R)ad[id]+=x,pushdown(id);
    else update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x),mx[id]=max(mx[Lid],mx[Rid]);
    return;
}

int query(int L,int R,int id,int x){
    pushdown(id);
    if(L==R)return mx[id];
    if(x<=M)return query(L,M,Lid,x);
    return query(M+1,R,Rid,x);
}

int findpos(int L,int R,int id,int r,int s){
    pushdown(id);
    if(L>r||mx[id]<=s)return 0;
    if(L==R)return L;
    int res=findpos(M+1,R,Rid,r,s);
    if(res)return res;
    return findpos(L,M,Lid,r,s);
}

void divide(int L,int R,int id){
    for(unsigned i=0;i<upt[id].size();i++){
        update(0,m,1,0,upt[id][i].x,upt[id][i].y);
        if(upt[id][i].y>0)add(upt[id][i].x,1);
    }
    if(L==R){
        for(unsigned i=0;i<qry[L].size();i++){
            int x=qry[L][i];
            int sum=(x==m?0:query(0,m,1,x+1));
            int p=findpos(0,m,1,x,sum);
            ans[x]=qs(x)-qs(p-1);
        }
    }
    else divide(L,M,Lid),divide(M+1,R,Rid);
    for(unsigned i=0;i<upt[id].size();i++){
        update(0,m,1,0,upt[id][i].x,-upt[id][i].y);
        if(upt[id][i].y>0)add(upt[id][i].x,-1);
    }
    return;
}

signed main(){
	ifile("plant.in");
	ofile("plant.out");
	
    n=read(),m=read();
    update(0,m,1,0,0,1);
    add(0,1);
    for(int i=1,op,x,y;i<=m;i++){
        op=read();
        if(op<=2){
			x=read(),y=read();
        	upt[x].push_back(node(i,op==1?1:-1));
        	upt[y+1].push_back(node(-i,op==1?-1:1));
        }
        else{
            x=read(),is_qry[i]=1;
            qry[x].push_back(i);
        }
    }
    for(int L=1;L<=n;L++){
    	int id=L;
    	for(unsigned i=0;i<upt[id].size();i++){
        	update(0,m,1,0,_abs(upt[id][i].x),upt[id][i].y);
        	if(upt[id][i].x*upt[id][i].y>0)add(_abs(upt[id][i].x),upt[id][i].y);
    	}
    	for(unsigned i=0;i<qry[L].size();i++){
            int x=qry[L][i];
            int sum=(x==m?0:query(0,m,1,x+1));
            int p=findpos(0,m,1,x,sum);
            ans[x]=qs(x)-qs(p-1);
        }
	}
//    divide(1,n,1);
    for(int i=1;i<=m;i++)if(is_qry[i])_write(ans[i]);
    return 0;
}

