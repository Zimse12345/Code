/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-
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
#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
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
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1e18;
}using namespace Zimse;

const int N=1e6+7;

int n,m,cost1,cost2,dis[N],vis[N];
vector<char> mp[N];
char str[N];

struct edge{
    int to,w;
    edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N];

struct node{
    int pos,dis;
    node(int pos=0,int dis=0):pos(pos),dis(dis){}
    bool operator < (const node& _)const{return _.dis<dis;}
};
priority_queue<node> q;

inline int Id(int x,int y){
    if(0<=x&&x<n&&0<=y&&y<m){
        return x*m+y;
    }
    return -1;
}

void add(int u,int v,int w){
    if(u==-1||v==-1)return;
    g[v].pb(edge(u,w));
}

signed main(){
    n=read(),m=read();
    cost1=read(),cost2=read();
    for(int i=0;i<n;i++){
        scanf("%s",str);
        for(int j=0;j<m;j++)mp[i].pb(str[j]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='L'){
                add(Id(i,j),Id(i-1,j+1),cost1);
                add(Id(i,j),Id(i+1,j+1),cost1);
                add(Id(i,j),Id(i,j+2),cost2);
                add(Id(i,j+1),Id(i-1,j),cost1);
                add(Id(i,j+1),Id(i+1,j),cost1);
                add(Id(i,j+1),Id(i,j-1),cost2);
            }
            if(mp[i][j]=='U'){
                add(Id(i,j),Id(i+1,j-1),cost1);
                add(Id(i,j),Id(i+1,j+1),cost1);
                add(Id(i,j),Id(i+2,j),cost2);
                add(Id(i+1,j),Id(i,j-1),cost1);
                add(Id(i+1,j),Id(i,j+1),cost1);
                add(Id(i+1,j),Id(i-1,j),cost2);
            }
            if(mp[i][j]=='.')add(Id(i,j),n*m,0);
        }
    }
    for(int i=0;i<n*m;i++)dis[i]=INF;
    q.push(node(n*m,0));
    while(!q.empty()){
        int u=q.top().pos;
        q.pop();
        if(vis[u]++)continue;
        for(unsigned i=0;i<g[u].size();i++){
            int v=g[u][i].to,d=dis[u]+g[u][i].w;
            if(d<dis[v]){
                dis[v]=d;
                q.push(node(v,d));
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='#')dis[Id(i,j)]=INF;
            // if(dis[Id(i,j)]==INF)printf("X  ");
            // else printf("%d ",dis[Id(i,j)]);
        }
        // pc(10);
    }
    int ans=INF;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j+1<m)_min(ans,dis[Id(i,j)]+dis[Id(i,j+1)]);
            if(i+1<n)_min(ans,dis[Id(i,j)]+dis[Id(i+1,j)]);
        }
    }
    if(ans==INF)ans=-1;
    _write(ans);
    return 0;
}
