/********************************
*FileName:
*Author: Zimse
*Data: 2022-12-
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
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

using namespace std;

namespace Zimse{
// const int Mod=998244353;
const int Mod=1000000007;

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
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=256;

int n,d[N],f[N][N][N],g[N][N],ans;

signed main(){
    n=read();
    for(int i=1;i<=n;i++)d[i]=read();
    f[0][0][0]=1;
    for(int b=0;b<=n;b++){
        for(int a=0;a<=n*4;a++){
            if(b!=0){
                if(a>1&&b>0)addmod(f[a][b][0],f[a-2][b-1][0]*a%Mod*(a-1)%Mod*inv(2));
                if(b>2)addmod(f[a][b][0],f[a+2][b-3][0]*(b-1)%Mod*(b-2)%Mod*inv(2));
                if(b>1)addmod(f[a][b][0],f[a][b-2][0]*a%Mod*(b-1));
            }
            else if(a!=0){
                if(a%2==0){
                    if(a>3)addmod(f[a][b][0],f[a-4][b][0]*(a-2)%Mod*(a-3));
                    if(b>1)addmod(f[a][b][0],f[a][b-2][0]*b%Mod*(b-1));
                    if(a>1&&b>0)addmod(f[a][b][0],f[a-2][b-1][0]*(a-2)%Mod*b*2);
                    addmod(f[a][b][0],f[a-2][b][0]);
                }
            }
            if(a<=n&&b<=n){
                for(int c=1;c<=n;c++){
                    if(a>0)addmod(f[a][b][c],f[a-1][b][c-1]*a);
                    if(b>0)addmod(f[a][b][c],f[a+1][b-1][c-1]*b);
                }
            }
        }
    }
    g[d[1]+1][d[1]]=1;
    for(int i=d[1]+1;i<=n;i++){
        for(int j=1;j<=i;j++)if(f[i][j]){
            int a=0,b=0;
            for(int t=i-j+1;t<=i;t++){
                if(d[t]==2)++a;
                else ++b;
            }
            for(int t=1;i+t<=n;t++){
                addmod(g[i+t][t],g[i][j]*f[a][b][t]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        int a=0,b=0;
        for(int t=n-i+1;t<=n;t++){
            if(d[t]==2)++a;
            else ++b;
        }
        addmod(ans,g[n][i]*f[a][b][0]);
    }
    _write(ans);
    return 0;
}
