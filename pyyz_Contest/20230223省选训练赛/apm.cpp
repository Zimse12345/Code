/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
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

namespace Zimse{
const int INF=1000114514;
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
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=100007,B=43;

int n,q,powB[N],ipowB[N],fa[N];
vector<int> s[N];

struct FenwickTree{
    int tr[N];
    inline void ub(int &x){x+=(x&(-x));return;}
    inline void db(int &x){x-=(x&(-x));return;}
    inline void add(int x,int y){for(;x<N;ub(x))addmod(tr[x],y);return;}
    inline int sum(int x){int res=0;for(;x;db(x))addmod(res,tr[x]);return res;}
}a,b;

void update(int l1,int r1,int l2,int r2){
    int lh=(Mod+a.sum(r1)-a.sum(l1-1))*ipowB[l1-1]%Mod;
    int rh=(Mod+b.sum(r2)-b.sum(l2-1))*ipowB[n-r2]%Mod;
    if(lh==rh)return;
    if(l1==r1){
        int x=fa[l1],y=fa[l2];
        if(s[x].size()<s[y].size())swap(x,y);
        for(unsigned i=0;i<s[y].size();i++){
            s[x].pb(s[y][i]),fa[s[y][i]]=x;
            a.add(s[y][i],(x-y+Mod)*powB[s[y][i]-1]);
            b.add(s[y][i],(x-y+Mod)*powB[n-s[y][i]]);
        }
        s[y].resize(0);
    }
    else{
        int len=(r1-l1+1)/2;
        update(l1,l1+len-1,r2-len+1,r2),update(l1+len,r1,l2,r2-len);
    }
    return;
}

signed main(){
	// ifile("apm.in");
	// ofile("apm.out");
	
    powB[0]=ipowB[0]=1;
    for(int i=1;i<N;i++)powB[i]=powB[i-1]*B%Mod,ipowB[i]=inv(powB[i]);
    n=read(),q=read();
    for(int i=1;i<=n;i++){
        a.add(i,i*powB[i-1]);
        b.add(i,i*powB[n-i]);
        fa[i]=i,s[i].pb(i);
    }
    while(q--){
        int opt=read();
        if(opt==1){
            int l=read(),r=read(),mid=(l+r)/2;
            if((r-l+1)&1)update(l,mid-1,mid+1,r);
            else update(l,mid,mid+1,r);
        }
        else{
            int l1=read(),r1=read(),l2=read(),r2=read();
            if(r1-l1!=r2-l2)printf("Not equal\n");
            else{
                int lh=(Mod+a.sum(r1)-a.sum(l1-1))*ipowB[l1-1]%Mod;
                int rh=(Mod+a.sum(r2)-a.sum(l2-1))*ipowB[l2-1]%Mod;
                if(lh==rh)printf("Equal\n");
                else printf("Unknown\n");
            }
        }
    }
    return 0;
}
