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

int T,n,a[N],b[N],K,L,sta[N];
ll ans;

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return y<_.y;}
};
priority_queue<node> A,B,AB,rA,rB;

void clear(priority_queue<node>& q){
    while(!q.empty())q.pop();
    return;
}

signed main(){
    T=read();
    while(T--){
        n=read(),K=read(),L=read(),ans=0;
        for(int i=1;i<=n;i++)a[i]=read(),A.emplace(i,a[i]);
        for(int i=1;i<=n;i++)b[i]=read(),B.emplace(i,b[i]),AB.emplace(i,a[i]+b[i]),sta[i]=0;
        while(K>0){
            while(!A.empty()&&(sta[A.top().x]&1))A.pop();
            while(!B.empty()&&(sta[B.top().x]&2))B.pop();
            while(!rA.empty()&&(sta[rA.top().x]&1))rA.pop();
            while(!rB.empty()&&(sta[rB.top().x]&2))rB.pop();
            while(!AB.empty()&&sta[AB.top().x])AB.pop();
            if(K>L){
                int x=A.top().x,y=B.top().x;
                A.pop(),B.pop();
                ans+=a[x]+b[y];
                rA.emplace(y,a[y]),rB.emplace(x,b[x]);
                sta[x]|=1,sta[y]|=2;
                if(x==y)--L;
                else{
                    if(sta[x]==3)--L;
                    if(sta[y]==3)--L;
                }
            }
            else{
                int ab=-INF,_a=-INF,_b=-INF;
                if(!AB.empty())ab=AB.top().y;
                if(!rB.empty()&&!A.empty())_a=rB.top().y+A.top().y;
                if(!rA.empty()&&!B.empty())_b=rA.top().y+B.top().y;
                if(ab>=_a&&ab>=_b){
                    int x=AB.top().x;
                    AB.pop();
                    ans+=ab;
                    sta[x]|=3;
                    --L;
                }
                else if(_a>=_b){
                    int x=A.top().x,y=rB.top().x;
                    A.pop(),rB.pop();
                    ans+=_a;
                    rB.emplace(x,b[x]);
                    sta[x]|=1,sta[y]|=2;
                    if(sta[x]==3)--L;
                    if(sta[y]==3)--L;
                }
                else{
                    int x=rA.top().x,y=B.top().x;
                    rA.pop(),B.pop();
                    ans+=_b;
                    rA.emplace(y,a[y]);
                    sta[x]|=1,sta[y]|=2;
                    if(sta[x]==3)--L;
                    if(sta[y]==3)--L;
                }
            }
            --K;
        }
        printf("%lld\n",ans);
        clear(A),clear(B),clear(rA),clear(rB),clear(AB);
    }
    return 0;
}
