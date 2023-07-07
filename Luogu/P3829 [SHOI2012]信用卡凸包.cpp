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
const double eps=1e-9;
const double Pi=3.141592653589793;
const double dx[4]={1,1,-1,-1},dy[4]={1,-1,-1,1};

struct point{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){}
    inline point operator + (const point &_)const{return point(x+_.x,y+_.y);}
    inline point operator - (const point &_)const{return point(x-_.x,y-_.y);}
    inline double operator * (const point &_)const{return x*_.y-y*_.x;}
}p[N],O,stk[N];
int top;

inline point Rotate(point p,double rad){
    return point(p.x*cos(rad)+p.y*sin(rad),p.y*cos(rad)-p.x*sin(rad));
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

signed main(){
    int n=read(),m=0;
    double a,b,r,ans=0;
    scanf("%lf%lf%lf",&a,&b,&r),ans=2.0*Pi*r;
    a=a/2.0-r,b=b/2.0-r;
    for(int i=1;i<=n;i++){
        double x,y,rad;
        scanf("%lf%lf%lf",&x,&y,&rad);
        for(int w=0;w<4;w++)p[++m]=Rotate(point(b*dx[w],a*dy[w]),-rad)+point(x,y);
    }
    O=p[1];
    for(int i=1;i<=m;i++)if(p[i].y<O.y||(p[i].y-eps<=O.y&&p[i].x<O.x))O=p[i];
    sort(p+1,p+m+1,cmp_PolarAngle);
    p[0]=p[m+1]=stk[++top]=O;
    for(int i=1;i<=m+1;i++){
        if(i<=m&&abs((p[i]-O)*(p[i-1]-O))<eps&&sqdis(O,p[i])<sqdis(O,p[i-1]))continue;
        while(top>1&&(stk[top]-stk[top-1])*(p[i]-stk[top])<eps)--top;
        stk[++top]=p[i];
    }
    for(int i=1;i<top;i++)ans+=sqrt(sqdis(stk[i],stk[i+1]));
    printf("%.2lf\n",ans);
    return 0;
}

