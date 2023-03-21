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

const int N=1000007;

int a[N],b[N];

inline void Swap(int x,int y){
    if(y<x)swap(x,y);
    write_(x),_write(y);
    swap(a[x],a[y]);
    return;
}

signed main(){
    int n=read(),s=0;
    for(int i=1;i<=n;i++){
        b[i]=read();
        a[b[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++)if(a[i]<a[j])++s;
    }
    if((s^(n*(n-1)/2))&1){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    int tag=0;
    for(int i=n;i>1;i--){
        if(a[i]^i){
            int p=0;
            for(int j=1;j<i;j++){
                if(a[j]!=i&&a[j]!=tag)Swap(j,i);
                else if(a[j]==i)p=j;
            }
            Swap(p,i);
            tag=0;
        }
        else{
            int p=0;
            for(int j=1;j<i;j++)if(a[j]==i-1)p=j;
            if(p==i-1){
                Swap(i-1,i);
                Swap(i-2,i-1),tag=i-2;
                for(int j=1;j<i-1;j++)Swap(j,i);
            }
            else{
                int q=(a[1]==i-1?2:1);
                Swap(q,i);
                Swap(q,i-1),tag=q;
                for(int j=1;j<i;j++)if(j!=q)Swap(j,i);
            }
        }
    }
    return 0;
}
