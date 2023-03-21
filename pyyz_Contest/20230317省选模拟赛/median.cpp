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

int n,a[N],f[N][27],pre[N][27],ans[N];

inline int con(int x,int y,int z){
    return (x+1)+(y+1)*3+(z+1)*9;
}

inline int midnum(int x,int y,int z){
    if(y<x)swap(x,y);
    if(z<y)swap(y,z);
    if(y<x)swap(x,y);
    return y;
}

signed main(){
    // ifile("median.in");
    // ofile("median.out");

    n=read();
    if(n==1){
        _write(0);
        return 0;
    }
    if(n==2){
        write_(0),_write(0);
        return 0;
    }
    for(int i=2;i<n;i++)a[i]=read();
    for(int x=-1;x<=1;x++)if(1<1+x&&1+x<n){
        for(int y=-1;y<=1;y++)if(1<2+y&&2+y<n){
            for(int z=-1;z<=1;z++)if(1<3+z&&3+z<n){
                if(midnum(a[1+x],a[2+y],a[3+z])==a[2])f[2][con(x,y,z)]=1;
            }
        }
    }
    for(int i=3;i<n;i++){
        for(int px=-1;px<=1;px++){
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++)if(f[i-1][con(px,x,y)]){
                    for(int z=-1;z<=1;z++)if(i+1+z<n){
                        if(midnum(a[i-1+x],a[i+y],a[i+1+z])==a[i]){
                            f[i][con(x,y,z)]=1,pre[i][con(x,y,z)]=con(px,x,y);
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<27;i++)if(f[n-1][i]){
        int s=i;
        for(int j=n-1;j>2;j--)ans[j+1]=a[j+s/9],s=pre[j][s];
        ans[3]=a[2+s/9],s%=9,ans[2]=a[1+s/3],ans[1]=a[s%3];
        for(int j=1;j<=n;j++)write_(ans[j]);
        pc(10);
        for(int j=2;j<n;j++)if(midnum(ans[j-1],ans[j],ans[j+1])!=a[j])printf("WA\n");
        return 0;
    }
    _write(-1);
    return 0;
}
