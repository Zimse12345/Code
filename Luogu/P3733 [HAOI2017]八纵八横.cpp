/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#pragma GCC target("avx")
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
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
#define int unsigned
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
}using namespace Zimse;using namespace std;

const int N=4096;

int n,m,q,Id,tim[N],fa[N],sz[N],*ptr[N],val[N],cnt,W[N],Cnt;
bitset<1024> ans[N],fw[N],B[N];
char str[N];

struct edge{
    int u,v;
    bitset<1024> w;
}s[N];
vector<edge> t[N*2];

inline edge make_edge(int u,int v){
    edge e;
    e.u=u,e.v=v,e.w.reset();
    int len=strlen(str+1),p=0;
    for(int i=len;i>=1;i--)e.w[p++]=(str[i]&1);
    return e;
}

void update(int id,int L,int R,int l,int r,const edge& e){
    if(l<=L&&r>=R){
        t[id].pb(e);
        return;
    }
    if(l<=M)update(Lid,L,M,l,r,e);
    if(r>M)update(Rid,M+1,R,l,r,e);
    return;
}

inline void ins(bitset<1024> b){
    for(int i=1000;i<=1000;i--)if(b[i]){
        if(B[i][i])b^=B[i];
        else{
            B[i]=b,W[++Cnt]=i;
            return;
        }
    }
    return;
}

bitset<1024> Path;
inline void link(const edge& e){
    int u=e.u,v=e.v;
    Path.reset();
    while(fa[u]!=u)Path^=fw[u],u=fa[u];
    while(fa[v]!=v)Path^=fw[v],v=fa[v];
    if(u==v)ins(Path^e.w);
    if(sz[u]<sz[v])swap(u,v);
    ptr[++cnt]=&fa[v],val[cnt]=fa[v];
    ptr[++cnt]=&sz[u],val[cnt]=sz[u];
    fa[v]=u,sz[u]+=sz[v],fw[v]=(Path^e.w);
    return;
}

void solve(int id,int L,int R){
    int _cnt=cnt,_Cnt=Cnt;
    for(unsigned i=0;i<t[id].size();i++)link(t[id][i]);
    if(L==R){
        for(int i=1000;i<=1000;i--)if(B[i][i]){
            if(!ans[L][i])ans[L]^=B[i];
        }
    }
    else solve(Lid,L,M),solve(Rid,M+1,R);
    while(cnt>_cnt)*ptr[cnt]=val[cnt],--cnt;
    while(Cnt>_Cnt)B[W[Cnt]].reset(),--Cnt;
    return;
}

signed main(){
    n=read(),m=read(),q=read();
    for(int i=1,u,v;i<=m;i++){
        u=read(),v=read(),scanf("%s",str+1);
        edge e=make_edge(u,v);
        update(1,0,q,0,q,e);
    }
    for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
    for(int i=1;i<=q;i++){
        scanf("%s",str+1);
        if(str[2]=='d'){    //Add
            int u=read(),v=read();
            scanf("%s",str+1);
            s[++Id]=make_edge(u,v),tim[Id]=i;
        }
        else if(str[2]=='h'){   //Change
            int k=read();
            scanf("%s",str+1);
            update(1,0,q,tim[k],i-1,s[k]);
            s[k]=make_edge(s[k].u,s[k].v),tim[k]=i;
        }
        else{   //Cancel
            int k=read();
            update(1,0,q,tim[k],i-1,s[k]),tim[k]=0;
        }
    }
    for(int i=1;i<=Id;i++)if(tim[i])update(1,0,q,tim[i],q,s[i]);
    solve(1,0,q);
    for(int i=0;i<=q;i++){
        int p=1000;
        while(p>0&&ans[i][p]==0)--p;
        for(int j=p;j<=1000;j--)pc(48^ans[i][j]);
        pc(10);
    }
    return 0;
}
