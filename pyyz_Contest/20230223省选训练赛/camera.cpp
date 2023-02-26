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

const int N=1200007;

int n,l[N],r[N],mx,popc[N],val[N];

inline int lowbit(int x){return x&(-x);}

signed main(){
    // ifile("camera.in");
	// ofile("camera.out");

    for(int i=1;i<N;i++)popc[i]=popc[i^lowbit(i)]+1;
    n=read();
    for(int i=1;i<=n;i++){
        l[i]=read(),r[i]=read();
        _max(mx,r[i]);
    }
    int V=0;
    if(mx<=20){
        for(int i=1;i<=n;i++){
            for(int j=l[i];j<=r[i];j++)val[i]|=(1<<(j-1));
            V|=val[i];
        }
        int mn=INF,ans=0;
        for(int i=0;i<(1<<mx);i++){
            if((V|i)!=V)continue;
            int Mx=0,tag=1;
            for(int j=1;j<=n;j++){
                int t=popc[val[j]&i];
                if(!t)tag=0;
                _max(Mx,t);
            }
            if(!tag)continue;
            if(Mx<mn)mn=Mx,ans=i;
            if(Mx==mn){
                vector<int> x,y;
                for(int j=0;j<mx;j++){
                    if(ans&(1<<j))x.pb(j);
                    if(i&(1<<j))y.pb(j);
                }
                int t=0;
                for(unsigned j=0;j<min(x.size(),y.size());j++){
                    if(x[j]<y[j]){
                        t=1;
                        break;
                    }
                    if(x[j]>y[j]){
                        t=2;
                        break;
                    }
                }
                if(t==0&&y.size()<x.size())t=2;
                if(t==2)ans=i;
            }
        }
        _write(mn);
        for(int i=0;i<mx;i++)if(ans&(1<<i))write_(i+1);
        pc(10);
    }
    return 0;
}
