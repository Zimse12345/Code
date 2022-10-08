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

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,hd[N],nxt[N*2],to[N*2],ec,sta[N];
int fa[N],dep[N],cnt[N],son[N],top[N];
int sz,rt,ms,vis[N],Fa[N],fe[N];
multiset<int> s[N*2],S[N],SS;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void findrt(int u,int from){
    cnt[u]=1;
    int mc=0;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from||vis[v])continue;
        findrt(v,u),cnt[u]+=cnt[v],mc=max(mc,cnt[v]);
    }
    mc=max(mc,sz-cnt[u]);
    if(mc<ms)ms=mc,rt=u;
    return;
}

void dfs(int u,int from,int id,int dis){
    s[id].insert(-dis);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from||vis[v])continue;
        dfs(v,u,id,dis+1);
    }
}

void divide(int u){
    vis[u]=1;
    int mx=0,se=0;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v])continue;
        dfs(v,u,i,1);
        int x=*s[i].begin();
        // printf("(%d %d %d)\n",u,v,x);
        S[u].insert(x);
        if(x<mx)se=mx,mx=x;
        else if(x<se)se=x;
    }
    SS.insert(mx+se);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v])continue;
        sz=cnt[v],ms=INF,findrt(v,u),Fa[rt]=u,fe[rt]=i;
        divide(rt);
    }
    return;
}

void dfs1(int u,int from,int d){
    fa[u]=from,dep[u]=d,cnt[u]=1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs1(v,u,d+1),cnt[u]+=cnt[v];
        if(cnt[son[u]]<cnt[v])son[u]=v;
    }
    return;
}

void dfs2(int u,int from,int d){
    top[u]=d;
    if(son[u])dfs2(son[u],u,d);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from||v==son[u])continue;
        dfs2(v,u,v);
    }
    return;
}

inline int LCA(int u,int v){
    while(top[u]^top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}

inline int Dis(int u,int v){
    return dep[u]+dep[v]-2*dep[LCA(u,v)];
}

signed main(){
	n=read();
    for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
    dfs1(1,0,1),dfs2(1,0,1);
    sz=n,ms=INF,findrt(1,0);
    divide(rt);
    m=read();
    for(int i=1;i<=ec;i++)s[i].insert(0),s[i].insert(1);
    for(int i=1;i<=n;i++)S[i].insert(0),S[i].insert(1);
    SS.insert(1),SS.insert(1);
    while(m--){
        char op;
        do{op=getchar();}while(op!='G'&&op!='C');
        if(op=='G'){
            if(n>3000){
                printf("%d\n",-(*SS.begin()));
                continue;
            }
            int ans=1;
            for(int i=1;i<=n;i++){
                multiset<int>::iterator it=S[i].begin();
                int x=*it;
                ++it;
                if(*it==0&&sta[i])continue;
                x+=*it;
                ans=min(ans,x);
            }
            printf("%d\n",-ans);
        }
        else{
            int x=read(),y,z=x;
            while(1){
                y=fe[x],x=Fa[x];
                if(x==0)break;
                int dis=-Dis(x,z);
                // printf(">(%d %d %d)\n",x,z,dis);
                int sfrom=*s[y].begin();
                if(sta[z])s[y].insert(dis);
                else s[y].erase(s[y].find(dis));
                int sto=*s[y].begin();
                if(sfrom!=sto){
                    multiset<int>::iterator it=S[x].begin();
                    int Sfrom=*it;
                    ++it;
                    Sfrom+=*it;
                    S[x].erase(S[x].find(sfrom));
                    S[x].insert(sto);
                    it=S[x].begin();
                    int Sto=*it;
                    ++it;
                    Sto+=*it;
                    if(Sfrom!=Sto){
                        SS.erase(SS.find(Sfrom));
                        SS.insert(Sto);
                    }
                }
            }
            // multiset<int>::iterator it=S[z].begin();
            // int v=*it;
            // ++it,v+=*it;
            // if(sta[z])SS.insert(v);
            // else if(*SS.lower_bound(v)==v)SS.erase(SS.find(v));
            sta[z]^=1;
        }
    }
	return 0;
}