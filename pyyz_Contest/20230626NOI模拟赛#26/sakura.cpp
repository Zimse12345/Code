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
int T,n,a[N],ans[N],len,tg,L,R,W,rt;

struct Num{
    int id,v;
    Num(int id=0,int v=0):id(id),v(v){}
    bool operator < (const Num& _)const{return v<_.v;}
}A[N];

struct node{
    int l,r,ky,sz,rev,fa;
    node(int l=0,int r=0,int ky=0,int sz=0,int rev=0,int fa=0):l(l),r(r),ky(ky),sz(sz),rev(rev),fa(fa){}
}t[N];

inline void pushup(int id){
    t[id].sz=t[t[id].l].sz+t[t[id].r].sz+1;
    if(t[id].l)t[t[id].l].fa=id;
    if(t[id].r)t[t[id].r].fa=id;
    t[id].fa=0;
    return;
}

inline void pushdown(int id){
    if(!t[id].rev)return;
    swap(t[id].l,t[id].r);
    if(t[id].l)t[t[id].l].rev^=1;
    if(t[id].r)t[t[id].r].rev^=1;
    t[id].rev=0;
    return;
}

inline void split(int id,int x,int &l,int &r){
    pushdown(id);
    if(!id){l=r=0;return;}
    if(x>=t[t[id].l].sz+1)l=id,split(t[l].r,x-t[t[id].l].sz-1,t[l].r,r),pushup(l);
    else r=id,split(t[r].l,x,l,t[r].l),pushup(r);
    return;
}

inline int merge(int l,int r){
    pushdown(l),pushdown(r);
    if(!l||!r)return l|r;
    if(t[l].ky<t[r].ky){
        t[l].r=merge(t[l].r,r);
        pushup(l);
        return l;
    }
    t[r].l=merge(l,t[r].l);
    pushup(r);
    return r;
}

inline int kth(int id,int x){
    pushdown(id);
    if(t[t[id].l].sz+1<x)return kth(t[id].r,x-t[t[id].l].sz-1);
    if(x<=t[t[id].l].sz)return kth(t[id].l,x);
    return id;
}

inline void Dfs(int u){
    pushdown(u);
    if(!u)return;
    Dfs(t[u].l),wri(u),Dfs(t[u].r);
    return;
}

inline int getpos(int x){
    vector<int> s;
    int u=x,rk=1;
    while(u)s.pb(u),u=t[u].fa;
    int sz=s.size();
    for(int i=sz-1;i>0;i--){
        pushdown(s[i]);
        if(t[s[i]].r==s[i-1])rk+=t[t[s[i]].l].sz+1;
    }
    pushdown(x);
    rk+=t[t[x].l].sz;
    return rk;
}

inline void opt(int x){
    if(R<x)L=x-L,R=x-R;
    else L=x+(n-L+1),R=x+(n-R+1);
    swap(L,R),W^=1;
    ans[++len]=x;
    int l,mid,r;
    split(rt,x,l,r);
    split(l,x-1,l,mid);
    t[l].rev=t[r].rev=1;
    rt=merge(l,merge(mid,r));
    return;
}

inline void solve(){
    L=R=getpos(1),W=0;
    if(L<n)opt(L+1);
    else opt(n-2),opt(n);
    for(int i=2;i<n;i++){
        if(!W)opt(R+1);
        int p=getpos(i);
        opt(p),++R;
        if(L!=1&&R<n)opt(R+1);
        else{
            if(L>2)opt(L-2),opt(n);
            else if(L!=1){opt(1);break;}
        }
    }
    if(kth(rt,1)==n){
        for(int i=1;i<n;i++)if(A[kth(rt,i)].v==A[kth(rt,i+1)].v){
            int x=kth(rt,i),y=kth(rt,i+1);
            opt(getpos(x)),opt(getpos(y)),opt(getpos(x));
            break;
        }
    }
    int ck=1;
    for(int i=1;i<=n;i++){
        a[i]=A[kth(rt,i)].v;
        if(i>1&&a[i]<a[i-1])ck=0;
    }
    if(ck){
        _wri(len);
        for(int i=1;i<=len;i++)wri(ans[i]);
        pc(10);
    }
    else _wri(-1),pc(10);
    return;
}

inline void RevSwap(int x,int y){
    if(x==y)return;
    tg^=1;
    opt(getpos(x));
    opt(getpos(y));
    opt(getpos(x));
    return;
}

struct Fenwick{
    int v[N];
    inline void ub(int &x){x+=(x&(-x));return;}
    inline void db(int &x){x-=(x&(-x));return;}
    inline void add(int x,int y){for(;x<N;ub(x))v[x]+=y;return;}
    inline int sum(int x){int res=0;for(;x;db(x))res+=v[x];return res;}
    inline void clear(){for(int i=0;i<N;i++)v[i]=0;return;}
}fenwick;

signed main(){
    iF("sakura.in");
    oF("sakura.out");
    
    srand(time(0));
    T=read();
    while(T--){
        n=read(),len=tg=rt=0;
        for(int i=1;i<=n;i++)a[i]=read(),A[i]=Num(i,a[i]);
        sort(A+1,A+n+1);
        int e=0;
        for(int i=1;i<=n;i++){
            a[A[i].id]=i;
            if(i<n&&A[i].v==A[i+1].v)e=1;
        }
        for(int i=1;i<=n;i++){
            t[a[i]]=node(0,0,rand(),1,0,0),rt=merge(rt,a[i]);
        }
        if(e){
            solve();
            continue;
        }
        int cnt=0;
        fenwick.clear();
        for(int i=1;i<=n;i++){
            cnt+=fenwick.sum(n)-fenwick.sum(a[i]);
            fenwick.add(a[i],1);
        }
        if(cnt&1){
            if(n%4==0||n%4==3)opt(1);
            else if(n%4==1)opt(2);
            else{_wri(-1);continue;}
        }
        for(int i=1;i<=n;i++){
            if(!tg)RevSwap(kth(rt,i),i);
            else RevSwap(kth(rt,n-i+1),i);
        }
        _wri(len);
        for(int i=1;i<=len;i++)wri(ans[i]);
        pc(10);
    }
    return 0;
}



