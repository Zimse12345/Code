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
#define pb push_back
#define ll long long
#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
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
const int INF=1e18;
}using namespace Zimse;

const int N=1e6+7;

int n,k,w[N],s,a[N],tot;

void dfs(int x,int sum,int mx){
    if(x>n||sum+w[x]>mx||tot>=k)return;
    a[++tot]=sum+w[x];
    dfs(x+1,sum+w[x],mx);
    dfs(x+1,sum,mx);
    return;
}

signed main(){
    n=read(),k=read();
    for(int i=1;i<=n;i++){
        w[i]=read();
        if(w[i]<0)s+=w[i],w[i]=-w[i];
    }
    sort(w+1,w+n+1);
    int L=0,R=INF,p=INF;
    while(L<=R){
        int M=(L+R)/2;
        tot=0,a[++tot]=0,dfs(1,0,M);
        if(tot>=k)p=M,R=M-1;
        else L=M+1;
    }
    tot=0,a[++tot]=0,dfs(1,0,p-1);
    sort(a+1,a+tot+1);
    for(int i=1;i<=tot;i++)_write(a[i]+s);
    for(int i=tot+1;i<=k;i++)_write(p+s);
    return 0;
}
