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

#include <algorithm>
const int N=131072;
int f[N][2];

int findSample(int n,int confidence[],int host[],int protocol[]){
    for(int i=0;i<n;i++)f[i][1]=confidence[i];
    for(int i=n-1;i>=0;i--){
        if(i){
            if(protocol[i]==0){
                f[host[i]][0]+=std::max(f[i][0],f[i][1]);
                f[host[i]][1]+=f[i][0];
            }
            else if(protocol[i]==1){
                f[host[i]][1]=std::max(f[host[i]][0],f[host[i]][1]);
                f[host[i]][0]+=f[i][0];
                f[host[i]][1]+=std::max(f[i][0],f[i][1]);
            }
            else{
                f[host[i]][1]=std::max(f[host[i]][1]+f[i][0],f[host[i]][0]+f[i][1]);
                f[host[i]][0]+=f[i][0];
            }
        }
    }
    return std::max(f[0][0],f[0][1]);
}

signed main(){
    int n=4,confidence[4]={3,2,1,4},host[4]={0,0,1,2},protocol[4]={0,1,1,1};
    _write(findSample(n,confidence,host,protocol));
    return 0;
}
