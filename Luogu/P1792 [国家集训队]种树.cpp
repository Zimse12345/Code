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
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

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

int n,m,a[N],l[N],r[N],ans,val[N],vis[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return y<_.y;}
};
priority_queue<node> q;

signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=val[i]=read();
        l[i]=i-1,r[i]=i+1;
        q.emplace(i,a[i]);
    }
    l[1]=n,r[n]=1;
    for(int i=1;i<=m;i++){
        while(!q.empty()&&vis[q.top().x])q.pop();
        if(q.empty()){
            printf("Error!\n");
            return 0;
        }
        int pos=q.top().x;
        ans+=q.top().y;
        q.pop();
        int lp=l[pos],rp=r[pos];
        if(lp==rp||l[lp]==rp){
            while(!q.empty())q.pop();
            continue;
        }
        r[l[lp]]=pos,l[r[rp]]=pos,l[pos]=l[lp],r[pos]=r[rp];
        vis[lp]=vis[rp]=1;
        val[pos]=val[lp]+val[rp]-val[pos];
        q.emplace(pos,val[pos]);
    }
    _write(ans);
    return 0;
}
