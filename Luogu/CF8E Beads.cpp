/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-25
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

int n,k;
int s[N],f[N][2][2];

int calc(){
    f[0][0][0]=1;
    for(int i=1;i<=n-i+1;i++){
        f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=0;
        for(int l=0;l<2;l++){
            for(int r=0;r<2;r++){
                if(s[i]!=-1&&s[i]!=l)continue;
                if(s[n-i+1]!=-1&&s[n-i+1]!=r)continue;
                if(i==n-i+1&&l!=r)continue;
                for(int x=0;x<2;x++){
                    for(int y=0;y<2;y++){
                        int _x=x,_y=y;
                        if(!x){
                            if(l<r)_x=1;
                            else if(r<l)continue;
                        }
                        if(!y){
                            if(l<(r^1))_y=1;
                            else if((r^1)<l)continue;
                        }
                        f[i][_x][_y]+=f[i-1][x][y];
                    }
                }
            }
        }
    }
    int w=(n+1)/2;
    int res=f[w][0][0]+f[w][0][1]+f[w][1][0]+f[w][1][1];
    int tag=1;
    for(int i=1;i<=n;i++)if(s[i]==1)tag=0;
    return res-tag;
}

signed main(){
    n=read(),k=read();
    for(int i=1;i<=n;i++)s[i]=-1;
    if(calc()<k){
        _write(-1);
        return 0;
    }
    for(int i=1;i<=n;i++){
        s[i]=0;
        int c=calc();
        if(c<k)k-=c,s[i]=1;
    }
    for(int i=1;i<=n;i++)write(s[i]);
    pc(10);
    return 0;
}
