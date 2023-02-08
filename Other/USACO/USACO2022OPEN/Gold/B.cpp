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
// #define int long long
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
inline void addmod(int& x,int y){x+=y;if(x>=Mod)x-=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=2048;

int T,n,s1[N],t1,s2[N],t2,f[N][N],g[N][N],nxt1[N][2],nxt2[N][2];
char str[N];
int ff[N][N],gg[N][N];

signed main(){
    T=read();
    while(T--){
        n=read();
        scanf("%s",str+1);
        for(int i=1;i<=n;i++){
            if(str[i]=='0'){
                t1=0,s1[++t1]=0;
                continue;
            }
            if(str[i]=='1')continue;
            if(str[i]=='+')s1[++t1]=1;
            else s1[++t1]=0;
        }
        scanf("%s",str+1);
        for(int i=1;i<=n;i++){
            if(str[i]=='0'){
                t2=0,s2[++t2]=0;
                continue;
            }
            if(str[i]=='1')continue;
            if(str[i]=='+')s2[++t2]=1;
            else s2[++t2]=0;
        }
        nxt1[t1][0]=nxt1[t1][1]=t1+1;
        for(int i=t1-1;i>=0;i--){
            nxt1[i][0]=nxt1[i+1][0],nxt1[i][1]=nxt1[i+1][1];
            nxt1[i][s1[i+1]]=i+1;
        }
        nxt2[t2][0]=nxt2[t2][1]=t2+1;
        for(int i=t2-1;i>=0;i--){
            nxt2[i][0]=nxt2[i+1][0],nxt2[i][1]=nxt2[i+1][1];
            nxt2[i][s2[i+1]]=i+1;
        }
        f[0][0]=g[0][0]=1;
        for(int i=0;i<=t1;i++){
            int F=0,G=0;
            for(int j=0;j<=t2;j++){
                addmod(F,ff[i][j]),addmod(G,gg[i][j]);
                addmod(f[i][j],F),addmod(g[i][j],G);
                addmod(ff[i+1][j],ff[i][j]),addmod(gg[i+1][j],gg[i][j]);
                if(f[i][j]){
                    int _i=nxt1[i][1]-1,_j=nxt2[j][1]-1;
                    addmod(G,f[i][j]);
                    addmod(gg[i+1][j],f[i][j]);
                    addmod(gg[i][j],f[i][j]);
                    addmod(gg[i][_j+1],Mod-f[i][j]);
                    addmod(gg[_i+1][j],Mod-f[i][j]);
                    addmod(gg[_i+1][_j+1],f[i][j]);
                }
                if(g[i][j]){
                    int _i=nxt1[i][0]-1,_j=nxt2[j][0]-1;
                    addmod(F,g[i][j]);
                    addmod(ff[i+1][j],g[i][j]);
                    addmod(ff[i][j],g[i][j]);
                    addmod(ff[i][_j+1],Mod-g[i][j]);
                    addmod(ff[_i+1][j],Mod-g[i][j]);
                    addmod(ff[_i+1][_j+1],g[i][j]);
                }
            }
        }
        int ans=(f[t1][t2]+g[t1][t2])%Mod;
        _write(ans);
        for(int i=0;i<=t1+1;i++){
            for(int j=0;j<=t2+1;j++)f[i][j]=g[i][j]=ff[i][j]=gg[i][j]=0;
        }
        t1=t2=0;
    }
    return 0;
}
