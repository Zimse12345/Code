/********************************
*FileName:
*Author: Zimse
*Data:
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
#define ll long long
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||c>57){if(c==45)y=-1;c=gc();}while(c>=48&&c<=57)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=2e6+7;

int n,m1,m2,k,hd[N],nxt[N],to[N],len[N],ec;
int dis[N],se[N];

inline void add(int u,int v,int w){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
    return;
}

queue<int> q;

void spfa(){
    for(int i=1;i<=n;i++)dis[i]=se[i]=INF;
    dis[1]=se[1]=0;
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=hd[u],v;i;i=nxt[i]){
            v=to[i];
            int tag=0;
            if(dis[u]+len[i]<dis[v])dis[v]=dis[u]+len[i],tag=1;
            else if(dis[u]+len[i]<se[v]&&dis[u]+len[i]!=dis[v])se[v]=dis[u]+len[i],tag=1;
            if(se[u]+len[i]<se[v]&&se[u]+len[i]!=dis[v])se[v]=se[u]+len[i],tag=1;
            if(tag)q.push(v);
        }
    }
    return;
}

signed main(){
    ifile("stardew.in");
    ofile("stardew.out");
    n=read()+2,m1=read(),m2=read(),k=read();
    for(int i=1,u,v,w;i<=m1;i++){
        u=read()+1,v=read()+1,w=read();
        for(int j=0;j<=k;j++)add(u+j*n,v+j*n,w);
    }
    for(int i=1,u,v,w;i<=m2;i++){
        u=read()+1,v=read()+1,w=read();
        for(int j=0;j<k;j++)add(u+j*n,v+(j+1)*n,w);
    }
    for(int j=0;j<k;j++)add(1+j*n,1+(j+1)*n,0);
    n+=k*n;
    //S=1,T=n+k*n
    spfa();
    _write(se[n]);
    return 0;
}
