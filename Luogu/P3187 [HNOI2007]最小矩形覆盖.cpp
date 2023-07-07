// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
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

const int N=1.01e6;
const double eps=1e-8;
const double Pi=3.141592653589793;

struct point{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){}
    inline point operator + (const point &_)const{return point(x+_.x,y+_.y);}
    inline point operator - (const point &_)const{return point(x-_.x,y-_.y);}
    inline double operator * (const point &_)const{return x*_.y-y*_.x;}
    inline point operator * (const double &_)const{return point(x*_,y*_);}
}p[N],O,stk[N];
int top;

struct line{
    point u,v,w;
    double angle;
    line(point _u=point(),point _v=point()){
        u=_u,v=_v,w=v-u;
        angle=atan2(w.y,w.x);
        return;
    }
};

inline double dot(point A,point B){
    return A.x*B.x+A.y*B.y;
}

inline double sqdis(point A,point B){
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}

inline bool cmp_PolarAngle(point A,point B){
    double c=(A-O)*(B-O);
    if(c>eps)return true;
    if(c>-eps)return sqdis(O,A)>sqdis(O,B);
    return false;
}

inline bool cmp_yx(point A,point B){
    if(A.y+eps<B.y)return true;
    if(A.y-eps>B.y)return false;
    return A.x<B.x;
}

inline point Rotate(point A,double rad){
    return point(A.x*cos(rad)+A.y*sin(rad),A.y*cos(rad)-A.x*sin(rad));
}

inline point cp(line A,line B){
    double T=((A.v-B.v)*B.w)/(A.w*B.w);
    return A.u*T+A.v*(1-T);
}

inline double GetS(point A,point B,point C){
    return abs((C-A)*(C-B))/2.0;
}

signed main(){
    int n=read();
    double ans=1e18;
    for(int i=1;i<=n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
    O=p[1];
    for(int i=1;i<=n;i++)if(p[i].y<O.y||(p[i].y-eps<=O.y&&p[i].x<O.x))O=p[i];
    sort(p+1,p+n+1,cmp_PolarAngle);
    p[0]=p[n+1]=stk[0]=O;
    for(int i=1;i<=n+1;i++){
        if(i<=n&&abs((p[i]-O)*(p[i-1]-O))<eps&&sqdis(O,p[i])<sqdis(O,p[i-1]))continue;
        while(top>0&&(stk[top]-stk[top-1])*(p[i]-stk[top])<eps){
            if(i>n&&top==1)break;
            --top;
        }
        stk[++top]=p[i];
    }
    for(int i=top;i<top*3;i++)stk[i]=stk[i-top];
    int v=1,L=1,R=1;
    point _s[4];
    for(int u=0;u<top;u++){
        while(v+1<top*2&&(stk[u+1]-stk[u])*(stk[v+1]-stk[v])>0)++v;
        while(L+1<top*2&&dot(stk[u+1]-stk[u],stk[L+1]-stk[L])>0)++L;
        R=max(R,v);
        while(R+1<top*2&&dot(stk[u+1]-stk[u],stk[R+1]-stk[R])<0)++R;
        point A=stk[u+1]-stk[u],B=point(-A.y,A.x);
        line l1=line(stk[u],stk[u]+A),l2=line(stk[L],stk[L]+B);
        line l3=line(stk[v],stk[v]+A),l4=line(stk[R],stk[R]+B);
        point s[4]={cp(l1,l2),cp(l2,l3),cp(l3,l4),cp(l4,l1)};
        if(GetS(s[0],s[1],s[2])+GetS(s[0],s[2],s[3])<ans){
            ans=GetS(s[0],s[1],s[2])+GetS(s[0],s[2],s[3]);
            for(int i=0;i<4;i++)_s[i]=s[i];
        }
    }
    printf("%.5lf\n",ans);
    int I=0;
    for(int i=1;i<4;i++)if(cmp_yx(_s[i],_s[I]))I=i;
    for(int i=0;i<4;i++)printf("%.5lf %.5lf\n",_s[(i+I)%4].x+eps,_s[(i+I)%4].y+eps);
    return 0;
}

