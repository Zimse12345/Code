/********************************
*FileName:
*Author: Zimse
*Data:
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
#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

const int Mod=1000000007;
namespace Zimse{
inline int read(){int x=0,y=1;char c=gc();while(c<48||c>57){if(c==45)y=-1;c=gc();}while(c>=48&&c<=57)x=x*10+c-48,c=gc();return x*y;}
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
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;

const int N=1e6+7;
const int INF=1000114514;

int n,mu[N],pr[N],prime[N],tot;
int ff[N],F[N],G[N];

signed main(){
    mu[1]=1;
    for(int i=2;i<N;i++){
        if(!pr[i])pr[i]=i,mu[i]=-1,prime[++tot]=i;
        for(int j=1;j<=tot&&i*prime[j]<N;j++){
            pr[i*prime[j]]=prime[j],mu[i*prime[j]]=-mu[i];
            if(pr[i]==prime[j]){mu[i*prime[j]]=0;break;}
        }
    }
    n=read();
    int ans=0;
    for(int d=1;d<=n;d++){
        for(int k=1;k*d<=n;k++){
            for(int s=1;s*k*d<=n;s++){
                addmod(ff[s*k*d],mu[d]*k*(s-1));
            }
        }
    }
    for(int i=1,s=0,ss=0;i<=n;i++){
        F[i]=s;
        ss+=ff[i];
        s+=ss;
    }
    for(int d=1;d<=n;d++){
        for(int k=1;k*d<=n;k++)addmod(G[k*d],mu[k]*d%Mod*k%Mod*k%Mod);
    }
    for(int i=1;i<=n;i++)if(n%i==0)addmod(ans,F[i]*G[n/i]);
    addmod(ans,Mod);
    _write(ans);
    return 0;
}


