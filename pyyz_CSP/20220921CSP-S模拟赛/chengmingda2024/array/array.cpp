/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-21
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

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
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
const int INF=1000114514;
}using namespace Zimse;

const int N=1e6+7;

void exgcd(int a,int b,int& x,int& y){
    if(b)exgcd(b,a%b,y,x),y-=(a/b)*x;
    else x=1,y=0;
    return;
}

signed main(){
    ifile("array.in"),ofile("array.out");
    int n=read(),a=read(),b=read(),ans=0;
    if(a>b)swap(a,b);
    int g=_gcd(a,b);
    int A=0,B=0;
    exgcd(a,b,A,B);
    for(int i=1,x=0;i<=n;i++){
        x=read();
        if(x%g!=0){
            _write(-1);
            return 0;
        }
        int t=x/g;
        int p=t*A,q=t*B;
        int res=_abs(p)+_abs(q);
        if(p>0){
            int k=p/(b/g);
            p-=k*(b/g),q+=k*(a/g);
            _min(res,_abs(p)+_abs(q));
            p-=b/g,q+=a/g;
            _min(res,_abs(p)+_abs(q));
        }
        if(p<0){
            int k=-((-p)/(b/g));
            p-=k*(b/g),q+=k*(a/g);
            _min(res,_abs(p)+_abs(q));
            p+=b/g,q-=a/g;
            _min(res,_abs(p)+_abs(q));
        }
        // printf("%d = %d*%d + %d*%d\n",x,p,a,q,b);
        ans+=res;
    }
    _write(ans);
	return 0;
}
