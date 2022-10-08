/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-22
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

const int N=1e6+7;

int n,Q,hd[N],nxt[N],to[N],ec,fa[N],ans[N];
int dep[N],cnt[N],son[N],tot[N][32];
char s[N];

struct query{
    int dep,id;
    query(int dep=0,int id=0):dep(dep),id(id){}
};
vector<query> q[N];

void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs(int u){
    cnt[u]=1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i],dep[v]=dep[u]+1;;
        dfs(v);
        cnt[u]+=cnt[v];
        if(cnt[son[u]]<cnt[v])son[u]=v;
    }
    return;
}

void update(int u){
    tot[dep[u]][s[u]-'a']^=1;
    for(int i=hd[u];i;i=nxt[i])update(to[i]);
    return;
}

void sol(int u,int tag){
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==son[u])continue;
        sol(v,0);
    }
    if(son[u])sol(son[u],1);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==son[u])continue;
        update(v);
    }
    tot[dep[u]][s[u]-'a']^=1;
    for(unsigned i=0;i<q[u].size();i++){
        int p=0;
        for(int c=0;c<26;c++)p+=tot[q[u][i].dep][c];
        if(p<=1)ans[q[u][i].id]=1;
    }
    if(!tag)update(u);
    return;
}

signed main(){
    n=read(),Q=read();
    for(int i=2;i<=n;i++){
        fa[i]=read();
        add(fa[i],i);
    }
    scanf("%s",s+1);
    for(int i=1,a,b;i<=Q;i++){
        a=read(),b=read();
        q[a].push_back(query(b,i));
    }
    dep[1]=1,dfs(1);
    sol(1,1);
    for(int i=1;i<=Q;i++)_ck(ans[i]);
    return 0;
}
