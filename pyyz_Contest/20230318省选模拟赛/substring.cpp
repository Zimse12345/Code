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

const int N=16007,M=2048;

char Llim[N],Rlim[N];
int Llen,Rlen,n;
int ch[N][10],tot,fail[N],g[N][1024];
int f[M][N],pre[M][N];
char prec[M][N];
bool tg[M][N];
queue<int> Q;

void dfs(int i,int pos,bool u,bool v,int a0){
    if(i>Rlen)return;
     for(int c=0;c<10;c++){
        if(u&&c<Llim[i])continue;
        if(v&&c>Rlim[i])continue;
        bool _u=(u&&(c==Llim[i])),_v=(v&&(c==Rlim[i]));
        if(a0&&c==0)dfs(i+1,0,_u,_v,true);
        else{
            if(!ch[pos][c])ch[pos][c]=++tot;
            if((!_u&&!_v)||i==Rlen)++g[ch[pos][c]][Rlen-i];
            else dfs(i+1,ch[pos][c],_u,_v,false);
        }
    }
    return;
}

signed main(){
    scanf("%s %s",Llim+1,Rlim+1);
    Llen=strlen(Llim+1),Rlen=strlen(Rlim+1),n=read();
    int c=Rlen-Llen;
    for(int i=Rlen;i>c;i--)Llim[i]=Llim[i-c];
    for(int i=1;i<=c;i++)Llim[i]='0';
    for(int i=1;i<=Rlen;i++)Llim[i]-='0',Rlim[i]-='0';
    dfs(1,0,true,true,true);
    Q.push(0);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<10;i++){
            if(ch[u][i]){
                if(u)fail[ch[u][i]]=ch[fail[u]][i];
                Q.push(ch[u][i]);
            }
            else ch[u][i]=ch[fail[u]][i];
        }
        for(int i=0;i<=Rlen;i++)g[u][i]+=g[fail[u]][i];
    }
    for(int i=0;i<=tot;i++){
        for(int j=1;j<=Rlen;j++)g[i][j]+=g[i][j-1];
    }
    f[0][0]=0;
    for(int i=1;i<=tot;i++)f[0][i]=-INF;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=tot;j++)f[i][j]=-INF;
        for(int j=0;j<=tot;j++){
            for(int c=0;c<10;c++){
                int v=f[i-1][j]+g[ch[j][c]][min(Rlen,n-i)];
                if(v>f[i][ch[j][c]]||(v==f[i][ch[j][c]]&&c<prec[i][ch[j][c]])){
                    f[i][ch[j][c]]=v;
                    prec[i][ch[j][c]]=c,pre[i][ch[j][c]]=j;
                }
            }
        }
    }
    int mx=0;
    for(int i=0;i<=tot;i++)_max(mx,f[n][i]);
    _write(mx);
    for(int i=0;i<=tot;i++)if(mx==f[n][i])tg[n][i]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=tot;j++){
            for(int c=0;c<10;c++)if(
                f[i][j]+g[ch[j][c]][min(Rlen,n-i-1)]==f[i+1][ch[j][c]]
            )tg[i][j]|=tg[i+1][ch[j][c]];
        }
    }
    int p=0;
    for(int i=0;i<n;i++){
        for(int c=0;c<10;c++)if(tg[i+1][ch[p][c]]&&
            f[i][p]+g[ch[p][c]][min(Rlen,n-i-1)]==f[i+1][ch[p][c]]){
            pc('0'+c),p=ch[p][c];
            break;
        }
    }
    pc(10);
    return 0;
}
