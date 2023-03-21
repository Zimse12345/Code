/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <algorithm>
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
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=100007;

int T,n,f[N][16],ans;
char F[16],s[N];

signed main(){
    // ifile("one.in");
    // ofile("one.out");

    T=read();
    while(T--){
        scanf("%s",F);
        swap(F[1],F[4]),swap(F[3],F[6]);
        for(int i=0;i<8;i++)F[i]-='0';
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='?')s[i]=2;
            else s[i]-='0';
        }
        if(s[n]!=0)f[n][8]=1;
        if(s[n]!=1)f[n][2]=1;
        for(int i=n-2;i>=1;i-=2){
            for(int t=0;t<16;t++)if(f[i+2][t]){
                for(int x=0;x<2;x++)if(s[i]!=(x^1)){
                    for(int y=0;y<2;y++)if(s[i+1]!=(y^1)){
                        int _t=0;
                        for(int p=0;p<4;p++)if(t&(1<<p)){
                            _t|=(1<<(F[x*4+y*2+p/2]*2+(p&1)));
                            if(F[y*2+p/2]==(p&1))_t|=(1<<(x*2));
                            if(F[4+y*2+p/2]==(p&1))_t|=(1<<(x*2+1));
                        }
                        addmod(f[i][_t],f[i+2][t]);
                    }
                }
            }
        }
        int v=0;
        if(s[1]!=0)v|=8;
        if(s[1]!=1)v|=1;
        for(int i=0;i<16;i++)if(i&v)addmod(ans,f[1][i]);
        _write(ans),ans=0;
        for(int i=1;i<=n;i+=2){
            for(int j=0;j<16;j++)f[i][j]=0;
        }
    }
    return 0;
}
