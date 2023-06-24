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

const int N=1.01e5;
int n,m,hd[N],nxt[N],to[N],ec;
char str[2][N],s[N];
int vis[N],cnt[N],_n,mn,rt,_rt,_cnt;
long long ans;

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

struct SAM{
    int tot,pre,sz[N],S[N],pos[N],f[N],g[N];
    struct node{
        int to[26],len,link,ed;
    }t[N];
    vector<int> ch[N];
    void init(){t[0].link=-1,pre=0;return;}

    void ins(int c){
        int id=++tot,p=pre;
        t[id].len=t[p].len+1,sz[id]=1;
        S[t[id].len]=c,t[id].ed=t[id].len,pos[t[id].len]=tot;
        while(p!=-1&&!t[p].to[c])t[p].to[c]=id,p=t[p].link;
        if(p==-1)t[id].link=0;
        else{
            int q=t[p].to[c];
            if(t[q].len==t[p].len+1)t[id].link=q;
            else{
                int cp=++tot;
                t[cp]=t[q],t[cp].len=t[p].len+1,t[cp].ed=t[id].ed;
                while(p!=-1&&t[p].to[c]==q)t[p].to[c]=cp,p=t[p].link;
                t[q].link=t[id].link=cp;
            }
        }
        pre=id;
        return;
    }

    void dfs(int u){
        for(unsigned i=0;i<ch[u].size();i++){
            dfs(ch[u][i]),sz[u]+=sz[ch[u][i]];
        }
        return;
    }

    void dfs2(int u,int from){
        if(from)f[u]+=f[from];
        for(unsigned i=0;i<ch[u].size();i++)dfs2(ch[u][i],u);
        return;
    }

    void build(){
        for(int i=1;i<=tot;i++)ch[t[i].link].pb(i);
        dfs(0);
        return;
    }

    void nxt(int &pos,int len,int c){
        if(len&&!pos)return;
        if(len<t[pos].len){
            if(S[t[pos].ed-len]!=c)pos=0;
            return;
        }
        for(unsigned i=0;i<ch[pos].size();i++){
            if(S[t[ch[pos][i]].ed-len]==c){
                pos=ch[pos][i];
                return;
            }
        }
        pos=0;
        return;
    }

    void calc(){
        dfs2(0,0);
        for(int i=1;i<=m;i++)g[i]=f[pos[i]];
        for(int i=1;i<=tot;i++)f[i]=0;
        return;
    }
}sam[2];

void findrt(int u,int from){
    int mxson=0;
    cnt[u]=1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v]||v==from)continue;
        findrt(v,u),cnt[u]+=cnt[v],_max(mxson,cnt[v]);
    }
    _max(mxson,_n-cnt[u]);
    if(mxson<mn)mn=mxson,rt=u,_rt=from,_cnt=_n-cnt[u];
    return;
}

void dfs(int u,int from,int pos){
    pos=sam[0].t[pos].to[s[u]-'a'];
    if(!pos)return;
    ans+=sam[0].sz[pos];
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v]||v==from)continue;
        dfs(v,u,pos);
    }
    return;
}

void BF(int u,int from){
    dfs(u,0,0);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v]||v==from)continue;
        BF(v,u);
    }
    return;
}

void dfs2(int u,int from,int len,int pos0,int pos1){
    sam[0].nxt(pos0,len,s[u]-'a');
    sam[1].nxt(pos1,len,s[u]-'a');
    if(pos0)sam[0].f[pos0]++;
    if(pos1)sam[1].f[pos1]++;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v]||v==from)continue;
        dfs2(v,u,len+1,pos0,pos1);
    }
    return;
}

void solve(int u,int t,int c){
    if(t==1)dfs2(u,0,0,0,0);
    else{
        int p0=0,p1=0;
        sam[0].nxt(p0,0,c),sam[1].nxt(p1,0,c);
        dfs2(u,0,1,p0,p1);
    }
    sam[0].calc(),sam[1].calc();
    for(int i=1;i<=m;i++)ans+=1ll*t*sam[0].g[i]*sam[1].g[m-i+1];
    return;
}

void divide(int u){
    if(_n<=500){
        BF(u,0);
        return;
    }
    solve(u,1,0);
    vis[u]=1;
    int from=_rt,fromcnt=_cnt;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(vis[v])continue;
        solve(v,-1,s[u]-'a');
        _n=cnt[v];
        if(v==from)_n=fromcnt;
        mn=INF,findrt(v,0);
        divide(rt);
    }
    return;
}

signed main(){
    n=read(),m=read();
    for(int i=1,u,v;i<n;i++){
        u=read(),v=read();
        add(u,v),add(v,u);
    }
    scanf("%s",s+1);
    scanf("%s",str[0]+1);
    sam[0].init(),sam[1].init();
    for(int i=1;i<=m;i++){
        str[1][i]=str[0][m-i+1];
        sam[0].ins(str[0][i]-'a'),sam[1].ins(str[1][i]-'a');
    }
    sam[0].build(),sam[1].build();
    _n=n,mn=INF,findrt(1,0);
    divide(rt);
    printf("%lld\n",ans);
    return 0;
}

