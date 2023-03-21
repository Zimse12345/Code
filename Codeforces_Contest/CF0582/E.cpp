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
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=65536;

char str[N];
int len,n,f[512][N],lim1,lim0,ans,g[N];

void FWT_AND(int *a,int tag=1){
    for(int i=0;i<16;i++){
        for(int j=0;j<N;j++)if(j&(1<<i))addmod(a[j-(1<<i)],a[j]*tag);
    }
    return;
}

void FWT_OR(int *a,int tag=1){
    for(int i=0;i<16;i++){
        for(int j=0;j<N;j++)if(j&(1<<i))addmod(a[j],a[j-(1<<i)]*tag);
    }
    return;
}

int dfs(int L,int R){
    if(L==R){
        if(str[L]=='?'){
            for(int c=0;c<4;c++){
                for(int tag=0;tag<2;tag++){
                    int x=0;
                    for(int i=0;i<16;i++){
                        if(((i&(1<<c))?1:0)^tag)x|=(1<<i);
                    }
                    f[L][x]++;
                }
            }
        }
        else{
            int c=0,tag=0,x=0;
            if('a'<=str[L])c=str[L]-'a',tag=1;
            else c=str[L]-'A';
            for(int i=0;i<16;i++){
                if(((i&(1<<c))?1:0)^tag)x|=(1<<i);
            }
            f[L][x]++;
        }
        return L;
    }
    int mid=0;
    for(int i=L,s=0;i<=R;i++){
        if(str[i]=='(')++s;
        if(str[i]==')')--s;
        if(!s){
            mid=i+1;
            break;
        }
    }
    int l=dfs(L+1,mid-2),r=dfs(mid+2,R-1);
    if(str[mid]!='|'){
        FWT_AND(f[l]),FWT_AND(f[r]);
        for(int i=0;i<N;i++)f[mid][i]=1ll*f[l][i]*f[r][i]%Mod;
        FWT_AND(f[mid],-1);
        FWT_AND(f[l],-1),FWT_AND(f[r],-1);
    }
    if(str[mid]!='&'){
        FWT_OR(f[l]),FWT_OR(f[r]);
        for(int i=0;i<N;i++)g[i]=1ll*f[l][i]*f[r][i]%Mod;
        FWT_OR(g,-1);
        for(int i=0;i<N;i++)addmod(f[mid][i],g[i]);
    }
    return mid;
}

signed main(){
    scanf("%s",str+1);
    len=strlen(str+1);
    n=read();
    while(n--){
        int a=read(),b=read(),c=read(),d=read(),e=read();
        int x=(1<<(a+b*2+c*4+d*8));
        if(e)lim1|=x;
        else lim0|=x;
    }
    int p=dfs(1,len);
    for(int i=0;i<N;i++){
        if((i&lim1)==lim1&&(i&lim0)==0)addmod(ans,f[p][i]);
    }
    addmod(ans,Mod);
    _write(ans);
    return 0;
}
