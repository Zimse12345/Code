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

int n,w,a[N],b[N],ans,sta[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return y>_.y;}
};
priority_queue<node> A,B,rA,rB,AB;

signed main(){
    n=read(),w=read();
    for(int i=1;i<=n;i++){
        a[i]=read(),b[i]=read();
        A.emplace(i,a[i]),AB.emplace(i,b[i]);
    }
    for(int i=1;i<=w;i++){
        while(!A.empty()&&sta[A.top().x]!=0)A.pop();
        while(!B.empty()&&sta[B.top().x]!=1)B.pop();
        while(!rA.empty()&&sta[rA.top().x]!=1)rA.pop();
        while(!rB.empty()&&sta[rB.top().x]!=2)rB.pop();
        while(!AB.empty()&&sta[AB.top().x]!=0)AB.pop();
        int aa=INF,bb=INF,_a=INF,_b=INF;
        if(!A.empty())aa=A.top().y;
        if(!B.empty())bb=B.top().y;
        if(!rA.empty()&&!AB.empty())_a=rA.top().y+AB.top().y;
        if(!rB.empty()&&!AB.empty())_b=rB.top().y+AB.top().y;
        if(aa<=bb&&aa<=_a&&aa<=_b){
            int x=A.top().x;
            A.pop(),B.emplace(x,b[x]-a[x]),rA.emplace(x,-a[x]);
            ans+=a[x],sta[x]++;
        }
        else if(bb<=_a&&bb<=_b){
            int x=B.top().x;
            B.pop(),rB.emplace(x,a[x]-b[x]);
            ans+=b[x]-a[x],sta[x]++;
        }
        else if(_a<=_b){
            int x=rA.top().x,y=AB.top().x;
            rA.pop(),AB.pop(),A.emplace(x,a[x]),AB.emplace(x,b[x]),rB.emplace(y,a[y]-b[y]);
            ans+=b[y]-a[x],sta[x]--,sta[y]+=2;
        }
        else{
            int x=rB.top().x,y=AB.top().x;
            rB.pop(),AB.pop(),B.emplace(x,b[x]-a[x]),rA.emplace(x,-a[x]),rB.emplace(y,a[y]-b[y]);
            ans+=a[x]-b[x]+b[y],sta[x]--,sta[y]+=2;
        }
    }
    _write(ans);
    for(int i=1;i<=n;i++)pc(sta[i]+'0');
    pc(10);
    return 0;
}
