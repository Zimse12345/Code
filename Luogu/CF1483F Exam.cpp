// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
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

const int N=1.01e6;
int n,ch[N][26],fail[N],tot,tg[N],pos[N],pre[N];
int vis[N],vvis[N],ans,ls[N];
int dfn[N],cnt[N],Time;
vector<char> s[N];
vector<int> g[N];
char _s[N];
queue<int> q;

struct fenwick{
    int tr[N];
    inline void ub(int &x){x+=(x&(-x));return;}
    inline void db(int &x){x-=(x&(-x));return;}
    inline void add(int x,int y){for(;x<N;ub(x))tr[x]+=y;return;}
    inline int sum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}
    inline int qry(int l,int r){return sum(r)-sum(l-1);}
}t;

void dfs(int u){
    cnt[u]=1,dfn[u]=++Time;
    for(unsigned i=0;i<g[u].size();i++){
        dfs(g[u][i]),cnt[u]+=cnt[g[u][i]];
    }
    return;
}

signed main(){
    n=read();
    for(int i=1;i<=n;i++){
        scanf("%s",_s);
        int len=strlen(_s),p=0;
        for(int j=0,c;j<len;j++){
            c=_s[j]-'a',s[i].pb(c);
            if(!ch[p][c])ch[p][c]=++tot;
            p=ch[p][c];
        }
        tg[p]=i,pos[i]=p;
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
        pre[u]=pre[fail[u]];
        if(tg[u])pre[u]=u;
        if(u)g[fail[u]].pb(u);
    }
    dfs(0);
    for(int i=1;i<=n;i++){
        int len=s[i].size(),p=0;
        for(int j=0;j<len;j++){
            p=ch[p][s[i][j]];
            int u=p;
            if(j==len-1)u=fail[u];
            u=pre[u];
            ls[j]=tg[u];
            if(ls[j])t.add(dfn[pos[ls[j]]],1);
        }
        int mnL=INF;
        for(int j=len-1;j>=0;j--)if(ls[j]){
            int l=j-s[ls[j]].size()+1;
            if(l>=mnL)vvis[ls[j]]=1;
            _min(mnL,l);
        }
        for(int j=0,x;j<len;j++)if(ls[j]){
            x=ls[j];
            if(vis[x]++)continue;
            if(!vvis[x]&&!t.qry(dfn[pos[x]]+1,dfn[pos[x]]+cnt[pos[x]]-1))++ans;
        }
        for(int j=0;j<len;j++){
            if(ls[j])t.add(dfn[pos[ls[j]]],-1),vis[ls[j]]=vvis[ls[j]]=0;
        }
    }
    _wri(ans);
    return 0;
}

