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
const int Mod=1073741824;
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

const int N=1000007;

int n,m,k,a[N],s[N],ans[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};
vector<node> p[N];

signed main(){
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1,l,r,w;i<=m;i++){
        l=read(),r=read(),w=read();
        p[r].pb(node(l,w));
        addmod(s[l],w);
    }
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=i;j++)addmod(sum,s[j]);
        for(int j=i,x=0;j>=1;j--){
            x^=a[j];
            if(x==k){
                addmod(ans[j],sum);
                addmod(ans[i+1],-sum);
            }
            addmod(sum,-s[j]);
        }
        for(unsigned j=0;j<p[i].size();j++)addmod(s[p[i][j].x],-p[i][j].y);
    }
    for(int i=1;i<=n;i++){
        addmod(ans[i],ans[i-1]+Mod+Mod);
        write_(ans[i]);
    }
    pc(10);
    return 0;
}
