// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
#define M ((L+R)/2)
namespace Zimse{const int INF=1.01e9,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int &x,int y){if(x<y)x=y;}
inline void _min(int &x,int y){if(y<x)x=y;}
inline void addmod(int &x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=1.01e6;
int n,m,h[N],ql[N],qr[N],Ans[N],pans[N];
int stk[N],H[N],top;

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};
vector<node> p[N],q[N];

struct Line{int l,r;double k,b;Line(int l=0,int r=0,double k=0,double b=0):l(l),r(r),k(k),b(b){}};
struct LiChaoSegmenttree{
#define Lid ch[id][0]
#define Rid ch[id][1]
    int LineTot,cnt,rt,p[N*8],ch[N*8][2];Line s[N];
    inline double f(int id,double x){return s[id].k*x+s[id].b;}

    inline void ins(int L,int R,int &id,int x){
        if(s[x].r<L||R<s[x].l)return;
        if(!id)id=++cnt;
        if(s[x].l<=L&&s[x].r>=R){
            if(!p[id])p[id]=x;
            else if((L==R&&f(p[id],L)<f(x,L))||(s[p[id]].k==s[x].k&&s[p[id]].b<s[x].b))p[id]=x;
            else{
                double X=(s[x].b-s[p[id]].b)/(s[p[id]].k-s[x].k);
                if((X<=double(L)&&s[x].k>s[p[id]].k)||(X>=double(R)&&s[x].k<s[p[id]].k))p[id]=x;
                else{
                    if(!(X>double(M)&&s[p[id]].k<s[x].k))ins(L,M,Lid,x);
                    if(!(X<double(M)&&s[p[id]].k>s[x].k))ins(M+1,R,Rid,x);
                }
            }
        }
        else ins(L,M,Lid,x),ins(M+1,R,Rid,x);
        return;
    }

    inline int query(int L,int R,int id,int x){
        if(!id||L==R)return p[id];
        int _p=(x<=M?query(L,M,Lid,x):query(M+1,R,Rid,x));
        return (f(_p,x)<f(p[id],x)||(f(_p,x)==f(p[id],x)&&p[id]<_p))?p[id]:_p;
    }
    
    inline void init(){
        for(int i=0;i<=cnt;i++)p[i]=ch[i][0]=ch[i][1]=0;
        cnt=LineTot=rt=0;
        return;
    }
#undef Lid
#undef Rid
}tree;

int pl[N],pr[N];
inline int bf(int l,int r){
    int ans=0;
    top=0,stk[0]=l-1;
    for(int i=l;i<=r;i++){
        while(top&&h[i]<=H[top])--top;
        pl[i]=stk[top]+1,stk[++top]=i,H[top]=h[i];
    }
    top=0,stk[0]=r+1;
    for(int i=r;i>=l;i--){
        while(top&&h[i]<=H[top])--top;
        pr[i]=stk[top]-1,stk[++top]=i,H[top]=h[i];
        _max(ans,h[i]*(pr[i]-pl[i]+1));
    }
    return ans;
}

void sub1(){
    for(int i=1;i<=m;i++){
        _write(bf(ql[i],qr[i]));
    }
    return;
}

inline void addline(int l,int r,int k,int w){
    if(w)tree.s[++tree.LineTot]=Line(l,r,k,k*(1-l));
    else tree.s[++tree.LineTot]=Line(l,r,-k,k*((r-l+1)+l));
    tree.ins(1,n,tree.rt,tree.LineTot);
    return;
}

#define Lid (id<<1)
#define Rid (Lid|1)
int mx[N];
inline void update(int id,int L,int R,int x,int y){
    _max(mx[id],y);
    if(L!=R){
        if(x<=M)update(Lid,L,M,x,y);
        else update(Rid,M+1,R,x,y);
    }
    return;
}

inline int query(int id,int L,int R,int l,int r){
    if(r<L||R<l)return 0;
    if(l<=L&&r>=R)return mx[id];
    return max(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
    //  ifile("relics.in");
    //  ofile("relics.out");

    n=read(),m=read();
    for(int i=1;i<=n;i++)h[i]=read();
    int sumlen=0;
    for(int i=1;i<=m;i++)ql[i]=read(),qr[i]=read(),sumlen+=qr[i]-ql[i]+1;
    bf(1,n);
    for(int i=1;i<=n;i++)p[pr[i]].pb(node(pl[i],h[i]));
    for(int i=1;i<=m;i++)q[qr[i]].pb(node(ql[i],i));
    for(int i=1;i<=n;i++){
        for(unsigned j=0;j<p[i].size();j++){
            addline(p[i][j].x,i,p[i][j].y,0);
            update(1,1,n,p[i][j].x,p[i][j].y*(i-p[i][j].x+1));
        }
        for(unsigned j=0;j<q[i].size();j++){
            _max(Ans[q[i][j].y],tree.f(tree.query(1,n,tree.rt,q[i][j].x),double(q[i][j].x)));
            _max(Ans[q[i][j].y],query(1,1,n,q[i][j].x,i));
        }
    }
    tree.init();
    for(int i=0;i<N;i++)mx[i]=0;
    for(int i=1;i<=n;i++)p[i].resize(0),q[i].resize(0);
    for(int i=1;i<=n;i++)p[pl[i]].pb(node(pr[i],h[i]));
    for(int i=1;i<=m;i++)q[ql[i]].pb(node(qr[i],i));
    for(int i=n;i>=1;i--){
        for(unsigned j=0;j<p[i].size();j++){
            addline(i,p[i][j].x,p[i][j].y,1);
        }
        for(unsigned j=0;j<q[i].size();j++){
            _max(Ans[q[i][j].y],tree.f(tree.query(1,n,tree.rt,q[i][j].x),double(q[i][j].x)));
        }
    }
    for(int i=1;i<=n;i++){
        for(unsigned j=0;j<p[i].size();j++){
            update(1,1,n,p[i][j].x,p[i][j].y);
        }
        for(unsigned j=0;j<q[i].size();j++){
            _max(Ans[q[i][j].y],query(1,1,n,q[i][j].x,n)*(q[i][j].x-i+1));
        }
    }
    for(int i=1;i<=m;i++)_write(Ans[i]);
    return 0;
}

