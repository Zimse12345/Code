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
const int Mod=998244353;
// const int Mod=1000000007;

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

const int N=1000007;

int L,R,n,m,llim[N],rlim[N];
int hd[N],nxt[N],to[N],ec;
int n1,n2,vis[N],Tag=1,tag[2][2],ans[N];
vector<int> s1,s2;

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs(int u,int col){
    if(!vis[u])vis[u]=col+1;
    else{
        if(vis[u]!=col+1)Tag=0;
        return;
    }
    if(col)s2.pb(u);
    else s1.pb(u);
    if(!(llim[u]<=n1&&n1<=rlim[u]))tag[0][col]=0;
    if(!(llim[u]<=n2&&n2<=rlim[u]))tag[1][col]=0;
    for(int i=hd[u];i;i=nxt[i])dfs(to[i],col^1);
    return;
}

signed main(){
    L=read(),R=read();
    n=read(),m=read();
    for(int i=1;i<=n;i++)llim[i]=read(),rlim[i]=read();
    for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v),add(v,u);
    n1=INF,n2=-INF;
    for(int i=1;i<=n;i++)_min(n1,rlim[i]),_max(n2,llim[i]);
    if(n1+n2<L)n2+=L-n1-n2;
    if(n1+n2>R)n1-=n1+n2-R;
    if(n1<0||n2<0){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        tag[0][0]=tag[0][1]=tag[1][0]=tag[1][1]=1;
        s1.resize(0),s2.resize(0);
        dfs(i,0);
        if(!Tag){
            printf("IMPOSSIBLE\n");
            return 0;
        }
        int b=0;
        if(tag[0][0]&&tag[1][1])b=0;
        else if(tag[0][1]&&tag[1][0])b=1;
        else{
            printf("IMPOSSIBLE\n");
            return 0;
        }
        for(unsigned j=0;j<s1.size();j++)ans[s1[j]]=b+1;
        for(unsigned j=0;j<s2.size();j++)ans[s2[j]]=(b^1)+1;
    }
    printf("POSSIBLE\n%d %d\n",min(n1,n2),max(n1,n2));
    for(int i=1;i<=n;i++)write(ans[i]);
    pc(10);
    return 0;
}
