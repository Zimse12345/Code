// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=3.01e5;
int n,m,ch[N][26],fail[N],tot,tg[N],pos[N],v[N];
int dep[N],cnt[N],son[N],top[N],dfn[N],Time,mx[N*4];
char str[N];
queue<int> q;
vector<int> g[N];
multiset<int> val[N];

void dfs(int u,int from){
    dep[u]=dep[from]+1,cnt[u]=1;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        dfs(v,u),cnt[u]+=cnt[v];
        if(!son[u]||cnt[son[u]]<cnt[v])son[u]=v;
    }
    return;
}

void dfs2(int u,int t){
    top[u]=t,dfn[u]=++Time;
    if(son[u])dfs2(son[u],t);
    for(unsigned i=0;i<g[u].size();i++){
        if(g[u][i]!=son[u])dfs2(g[u][i],g[u][i]);
    }
    return;
}

inline void update(int id,int L,int R,int x,int y){
    if(L==R)mx[id]=y;
    else{
        if(x<=M)update(Lid,L,M,x,y);
        else update(Rid,M+1,R,x,y);
        mx[id]=max(mx[Lid],mx[Rid]);
    }
    return;
}

inline int query(int id,int L,int R,int l,int r){
    if(r<L||R<l)return -1;
    if(l<=L&&r>=R)return mx[id];
    return max(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        scanf("%s",str+1);
        int len=strlen(str+1),p=0;
        for(int j=1,c;j<=len;j++){
            c=str[j]-'a';
            if(!ch[p][c])ch[p][c]=++tot;
            p=ch[p][c];
        }
        pos[i]=p,tg[p]=1;
    }
    q.push(0);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int c=0,v;c<26;c++){
            v=ch[u][c];
            if(v){
                if(u)fail[v]=ch[fail[u]][c];
                q.push(v);
            }
            else ch[u][c]=ch[fail[u]][c];
        }
        tg[u]|=tg[fail[u]];
        if(u)g[fail[u]].pb(u);
    }
    dfs(0,0);
    dfs2(0,0);
    for(int i=0;i<=tot;i++)if(!tg[i])update(1,0,tot+1,dfn[i],-1);
    while(m--){
        int typ=read();
        if(typ==1){
            int x=read(),y=read();
            if(v[x])val[pos[x]].erase(val[pos[x]].find(v[x]));
            v[x]=y,val[pos[x]].insert(y);
            update(1,0,tot+1,dfn[pos[x]],*(--val[pos[x]].end()));
        }
        else{
            scanf("%s",str+1);
            int len=strlen(str+1),ans=-1,p=0;
            for(int i=1;i<=len;i++){
                p=ch[p][str[i]-'a'];
                int u=p;
                while(u){
                    _max(ans,query(1,0,tot+1,dfn[top[u]],dfn[u]));
                    u=fail[top[u]];
                }
            }
            _wri(ans);
        }
    }
    return 0;
}

