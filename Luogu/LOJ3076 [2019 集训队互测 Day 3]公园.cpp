// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
#define mid ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
namespace OI{const int INF=1.01e12,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=8.01e5;
int n,m,Q;
set<int> E[N];
queue<int> q;

struct edge{
    int x,y;
    edge(int x=0,int y=0):x(min(x,y)),y(max(x,y)){}
    bool operator < (const edge &_)const{
        if(x==_.x)return y<_.y;
        return x<_.x;
    }
};
map<edge,int> Id;
int pid[N],tot,vis[N];

struct Matrix{
    int val[4][4],_n,_m;
    void init(int __n,int __m,int v=0){
        _n=__n,_m=__m;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)val[i][j]=v;
        }
        return;
    }
    void see(){
        pc('[');for(int i=0;i<_n;i++)wri(val[i][0]);pc(']'),pc(10);
        return;
    }
}M[N],emp2,emp4,Rev,tr[N*4],ans;
vector<int> ch[N];
int opt[N],fa[N];
int cnt[N],dep[N],son[N],dfn[N],top[N],ed[N],Time;

inline int MakeNode(int typ,int x=0,int y=0,int z=0){
    opt[++tot]=typ;
    ch[tot].pb(x);
    if(y)ch[tot].pb(y);
    if(z)ch[tot].pb(z);
    return tot;
}

Matrix Mul(Matrix x,Matrix y){
    Matrix z;
    z.init(x._n,y._m,-INF);
    for(int i=0;i<z._n;i++){
        for(int j=0;j<z._m;j++){
            for(int k=0;k<x._m;k++)_max(z.val[i][j],x.val[i][k]+y.val[k][j]);
        }
    }
    return z;
}

Matrix trans1(Matrix x,Matrix y,int typ){
    Matrix z;
    if(typ==1)z.init(2,4,-INF);
    else z.init(2,2,-INF);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(typ==0)_max(z.val[j][i],y.val[j][0]+x.val[i*2+j][0]);
            if(typ==1)z.val[j][i*2+j]=x.val[i][0]+y.val[j][0];
            if(typ==2)_max(z.val[j][j],x.val[i][0]+y.val[i*2+j][0]);
        }
    }
    return z;
}

Matrix trans2(Matrix x,Matrix y,int typ){
    Matrix z;
    if(typ==1)z.init(4,2,-INF);
    else z.init(4,4,-INF);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                if(typ==0)z.val[i*2+k][i*2+j]=x.val[j][0]+y.val[j*2+k][0];
                if(typ==1)z.val[i*2+k][j]=x.val[i*2+j][0]+y.val[j*2+k][0];
                if(typ==2)z.val[i*2+k][j*2+k]=x.val[i*2+j][0]+y.val[j][0];
            }
        }
    }
    return z;
}

Matrix trans3(Matrix x){
    Matrix y;
    y.init(4,4,-INF);
    for(int i=0;i<4;i++)y.val[i][i]=x.val[i][0];
    return y;
}

Matrix trans(int u){
    Matrix t;
    if(opt[u]==1){
        if(son[u]==0)t=trans1(M[ch[u][1]],M[ch[u][2]],0);
        if(son[u]==1)t=trans1(M[ch[u][0]],M[ch[u][2]],1);
        if(son[u]==2)t=trans1(M[ch[u][0]],M[ch[u][1]],2);
    }
    if(opt[u]==2){
        if(son[u]==0)t=trans2(M[ch[u][1]],M[ch[u][2]],0);
        if(son[u]==1)t=trans2(M[ch[u][0]],M[ch[u][2]],1);
        if(son[u]==2)t=trans2(M[ch[u][0]],M[ch[u][1]],2);
    }
    if(opt[u]==3)t=trans3(M[ch[u][son[u]^1]]);
    if(opt[u]==4)t=Rev;
    if(u<=n)t=emp2;
    if(u>n&&u<=n+m)t=emp4;
    return t;
}

void dfs(int u,int from){
    fa[u]=from,dep[u]=dep[from]+1,cnt[u]=1;
    for(unsigned i=0;i<ch[u].size();i++){
        int v=ch[u][i];
        dfs(v,u);
        cnt[u]+=cnt[v];
        if(cnt[ch[u][son[u]]]<=cnt[v])son[u]=i;
    }
    return;
}

void dfs2(int u,int t){
    dfn[u]=++Time,top[u]=t,ed[t]=u;
    if(ch[u].size())dfs2(ch[u][son[u]],t);
    for(unsigned i=0;i<ch[u].size();i++)if(i!=son[u])dfs2(ch[u][i],ch[u][i]);
    return;
}

void update(int id,int L,int R,int pos,Matrix x){
    if(L==R)tr[id]=x;
    else{
        if(pos<=mid)update(Lid,L,mid,pos,x);
        else update(Rid,mid+1,R,pos,x);
        tr[id]=Mul(tr[Lid],tr[Rid]);
    }
    return;
}

Matrix query(int id,int L,int R,int l,int r){
    if(l<=L&&r>=R)return tr[id];
    if(r<=mid)return query(Lid,L,mid,l,r);
    if(l>mid)return query(Rid,mid+1,R,l,r);
    return Mul(query(Lid,L,mid,l,r),query(Rid,mid+1,R,l,r));
}

signed main(){
    Rev.init(4,4,-INF),emp2.init(2,2,-INF),emp4.init(4,4,-INF);
    Rev.val[0][0]=Rev.val[1][2]=Rev.val[2][1]=Rev.val[3][3]=0;
    for(int i=0;i<4;i++)emp2.val[i][i]=emp4.val[i][i]=0;

    n=read(),m=read();
    for(int i=1,x,y;i<=n;i++){
        pid[i]=++tot,x=read(),y=read();
        M[tot]._n=2,M[tot]._m=1;
        M[tot].val[0][0]=x,M[tot].val[1][0]=y;
    }
    for(int i=1,u,v,x,y;i<=m;i++){
        u=read(),v=read(),x=read(),y=read();
        E[u].insert(v),E[v].insert(u);
        Id[edge(u,v)]=++tot;
        M[tot]._n=4,M[tot]._m=1;
        M[tot].val[0][0]=M[tot].val[3][0]=x,M[tot].val[1][0]=M[tot].val[2][0]=y;
    }
    for(int i=1;i<=n;i++)if(E[i].size()<=2)q.push(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(vis[x]++)continue;
        if(!E[x].size())break;
        if(E[x].size()==1){
            int y=*E[x].begin();
            int e=Id[edge(x,y)];
            if(y<x)e=MakeNode(4,e);
            pid[y]=MakeNode(1,pid[x],e,pid[y]);
            E[x].erase(y),E[y].erase(x);
            if(E[y].size()<=2)q.push(y);
            Id.erase(edge(x,y));
        }
        else{
            int a=*E[x].begin();
            E[x].erase(a),E[a].erase(x);
            int b=*E[x].begin();
            E[x].erase(b),E[b].erase(x);
            int e1=Id[edge(a,x)],e2=Id[edge(b,x)];
            if(x<a)e1=MakeNode(4,e1);
            if(b<x)e2=MakeNode(4,e2);
            int e3=MakeNode(2,e1,pid[x],e2);
            edge e=edge(a,b);
            if(Id[e])Id[e]=MakeNode(3,Id[e],e3);
            else{
                Id[e]=e3;
                E[a].insert(b),E[b].insert(a);
            }
            if(E[a].size()<=2)q.push(a);
            if(E[b].size()<=2)q.push(b);
            Id.erase(edge(a,x)),Id.erase(edge(b,x));
        }
    }
    dfs(tot,0);
    dfs2(tot,tot);
    for(int u=1;u<=tot;u++){
        if(opt[u])M[u]=M[ch[u][son[u]]];
        Matrix t=trans(u);
        M[u]=Mul(t,M[u]);
        update(1,1,tot,dfn[u],t);
    }
    ans=Mul(query(1,1,tot,dfn[tot],dfn[ed[tot]]),M[ed[tot]]);
    _wri(max(ans.val[0][0],ans.val[1][0]));
    Q=read();
    while(Q--){
        int u=read(),x=read(),y=read();
        if(u<=n)M[u].val[0][0]=x,M[u].val[1][0]=y;
        else M[u].val[0][0]=M[u].val[3][0]=x,M[u].val[1][0]=M[u].val[2][0]=y;
        while(top[u]!=tot){
            int f=top[u];
            M[f]=Mul(query(1,1,tot,dfn[f],dfn[ed[f]]),M[ed[f]]);
            update(1,1,tot,dfn[fa[f]],trans(fa[f]));
            u=fa[f];
        }
        ans=Mul(query(1,1,tot,dfn[tot],dfn[ed[tot]]),M[ed[tot]]);
        _wri(max(ans.val[0][0],ans.val[1][0]));
    }
    return 0;
}

