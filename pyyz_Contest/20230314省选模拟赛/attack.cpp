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
#define int long long
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

const int N=2048;

int n,m,k,ans;
int d[N],stk[N],pos[N];
int LU[N][N],RU[N][N],LD[N][N],RD[N][N],s[N][N];
char str[N][N];

void calc(int x,int y,int t){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            s[i][j]=(RD[i][j]-LD[i][j-2+y]-RU[i-2+x][j]+LU[i-2+x][j-2+y])%Mod;
            addmod(s[i][j],s[i-1][j]+s[i][j-1]-s[i-1][j-1]);
            addmod(ans,t*fpow(s[i][j],k));
        }
    }
    return;
}

signed main(){
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++){
        scanf("%s",str[i]+1);
        for(int j=1;j<=m;j++)str[i][j]^=1;
    }
    for(int i=1;i<=n;i++){
        int sum=0,top=0,pd=0;
        for(int j=1;j<=m;j++){
            if(str[i][j]&1)pd=0,d[j]=0;
            else ++pd,++d[j];
            pos[top+1]=j;
            int _j=j;
            while(top&&d[j]<stk[top]){
                sum-=(stk[top]-d[j])*(_j-pos[top]),_j=pos[top];
                --top;
            }
            sum+=d[j];
            if(stk[top]!=d[j])stk[++top]=d[j];
            LU[i][j]=sum;
        }
    }
    for(int i=1;i<=m;i++)d[i]=0;
    for(int i=1;i<=n;i++){
        int sum=0,top=0,pd=0;
        for(int j=m;j>=1;j--){
            if(str[i][j]&1)pd=0,d[j]=0;
            else ++pd,++d[j];
            pos[top+1]=j;
            int _j=j;
            while(top&&d[j]<stk[top]){
                sum-=(stk[top]-d[j])*(pos[top]-_j),_j=pos[top];
                --top;
            }
            sum+=d[j];
            if(stk[top]!=d[j])stk[++top]=d[j];
            RU[i][j]=sum;
        }
    }
    for(int i=1;i<=m;i++)d[i]=0;
    for(int i=n;i>=1;i--){
        int sum=0,top=0,pd=0;
        for(int j=1;j<=m;j++){
            if(str[i][j]&1)pd=0,d[j]=0;
            else ++pd,++d[j];
            pos[top+1]=j;
            int _j=j;
            while(top&&d[j]<stk[top]){
                sum-=(stk[top]-d[j])*(_j-pos[top]),_j=pos[top];
                --top;
            }
            sum+=d[j];
            if(stk[top]!=d[j])stk[++top]=d[j];
            LD[i][j]=sum;
        }
    }
    for(int i=1;i<=m;i++)d[i]=0;
    for(int i=n;i>=1;i--){
        int sum=0,top=0,pd=0;
        for(int j=m;j>=1;j--){
            if(str[i][j]&1)pd=0,d[j]=0;
            else ++pd,++d[j];
            pos[top+1]=j;
            int _j=j;
            while(top&&d[j]<stk[top]){
                sum-=(stk[top]-d[j])*(pos[top]-_j),_j=pos[top];
                --top;
            }
            sum+=d[j];
            if(stk[top]!=d[j])stk[++top]=d[j];
            RD[i][j]=sum;
        }
    }
    calc(1,1,1),calc(1,2,-1),calc(2,1,-1),calc(2,2,1);
    addmod(ans,Mod);
    _write(ans);
    return 0;
}
