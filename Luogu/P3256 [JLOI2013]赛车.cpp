// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define double long double
// #define int long long
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
const double eps=1e-24;
const double Pi=3.141592653589793;

struct point{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){}
    inline point operator + (const point &_)const{return point(x+_.x,y+_.y);}
    inline point operator - (const point &_)const{return point(x-_.x,y-_.y);}
    inline double operator * (const point &_)const{return x*_.y-y*_.x;}
    inline point operator * (const double &_)const{return point(x*_,y*_);}
};

struct line{
    point u,v,w;
    int id;
    double angle;
    line(point _u=point(),point _v=point(),int _id=0){
        u=_u,v=_v,w=v-u;
        angle=atan2(w.y,w.x);
        id=_id;
        return;
    }
}p[N],stk[N];

int n,pos[N],v[N],top;
int ans[N],tot;

inline double sqdis(point A,point B){
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}

inline point cp(line A,line B){
    double T=((A.v-B.v)*B.w)/(A.w*B.w);
    return A.u*T+A.v*(1-T);
}

inline bool cmp_PolarAngle(line A,line B){
    if(abs(A.angle-B.angle)<eps)return A.w*(B.u-A.u)>0;
    return A.angle<B.angle;
}

inline double GetS(point A,point B,point C){
    return abs((C-A)*(C-B))/2.0;
}

signed main(){
    n=read();
    for(int i=1;i<=n;i++)pos[i]=read();
    for(int i=1;i<=n;i++){
        v[i]=read();
        p[i]=line(point(0,pos[i]),point(1,pos[i]+v[i]),i);
    }
    stk[++top]=line(point(0,0),point(0,1000),0);
    sort(p+1,p+n+1,cmp_PolarAngle);
    for(int i=1;i<=n;i++){
        while(top>1&&p[i].w*(cp(stk[top],stk[top-1])-p[i].u)<-eps)--top;
        stk[++top]=p[i];
    }
    for(int i=2;i<=top;i++)ans[++tot]=stk[i].id;
    sort(ans+1,ans+tot+1);
    _wri(tot);
    for(int i=1;i<=tot;i++)wri(ans[i]);
    pc(10);
    return 0;
}

