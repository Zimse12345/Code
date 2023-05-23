// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
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
int n,X,rt,tot,dep[N];
long long ans;

struct circle{
    double x,y,r;
    circle(double x=0,double y=0,double r=0):x(x),y(y),r(r){}
}a[N];

struct nd{
    int x,id;
    nd(int x=0,int id=0):x(x),id(id){}
    bool operator < (const nd &_)const{return x<_.x;}
}p[N];

struct node{
    int l,r,id,w,ky;
    node(int l=0,int r=0,int id=0,int w=0,int ky=0):l(l),r(r),id(id),w(w),ky(ky){}
    double calc(double x){
        double y=a[id].y+sqrt((a[id].r-x+a[id].x)*(a[id].r+x-a[id].x));
        if(w)y=a[id].y*2-y;
        return y;
    }
}t[N];

void split(int id,double v,int &l,int &r){
    if(!id){l=r=0;return;}
    if(t[id].calc(X)<=v)l=id,split(t[id].r,v,t[id].r,r);
    else r=id,split(t[id].l,v,l,t[id].l);
    return;
}

int merge(int l,int r){
    if(!l||!r)return l|r;
    if(t[l].ky<t[r].ky){
        t[l].r=merge(t[l].r,r);
        return l;
    }
    t[r].l=merge(l,t[r].l);
    return r;
}

signed main(){
    srand(time(0));
    n=read();
    for(int i=1,x,y,r;i<=n;i++){
        x=read(),y=read(),r=read();
        a[i]=circle(x,y,r);
        p[i]=nd(x-r,i),p[i+n]=nd(x+r,i);
    }
    sort(p+1,p+n*2+1);
    for(int i=1,id;i<=n*2;i++){
        X=p[i].x,id=p[i].id;
        int l,m,r;
        split(rt,a[id].y-0.01,l,r);
        split(r,a[id].y+0.01,m,r);
        if(!m){
            int pr=l;
            while(t[pr].r)pr=t[pr].r;
            int d=dep[t[pr].id];
            if(pr&&t[pr].w)++d;
            if(d&1)ans-=1ll*a[id].r*a[id].r;
            else ans+=1ll*a[id].r*a[id].r;
            dep[id]=d;
            t[++tot]=node(0,0,id,1,rand());
            t[++tot]=node(0,0,id,0,rand());
            rt=merge(merge(l,tot-1),merge(tot,r));
        }
        else rt=merge(l,r);
    }
    printf("%lld\n",ans);
    return 0;
}

