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
    inline point operator * (const double &_)const{return point(x*_,y*_);}
}p[N];

struct line{
    point u,v,w;
    line(point u=point(),point v=point()):u(u),v(v),w(v-u){}
};

inline point Rotate(point A,double rad){
    return point(A.x*cos(rad)+A.y*sin(rad),A.y*cos(rad)-A.x*sin(rad));
}

inline point Mid(point A,point B){
    return (A+B)*0.5;
}

inline point cp(line A,line B){
    double T=((A.v-B.v)*B.w)/(A.w*B.w);
    return A.u*T+A.v*(1-T);
}

inline double dis(point A,point B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

inline line PerpendicularBisector(line A){
    return line(Mid(A.u,A.v),Mid(A.u,A.v)+Rotate(A.v-A.u,Pi/2));
}

inline point Circle(point A,point B,point C){
    return cp(PerpendicularBisector(line(A,B)),PerpendicularBisector(line(B,C)));
}

inline int rd(){
    int x=rand()%4096,y=rand()%4096;
    return x*4096+y;
}

signed main(){
    srand(time(0));
    int n=read();
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
        swap(p[i],p[rd()%i+1]);
    }
    point O=point(0,0);
    double r=0;
    for(int i=1;i<=n;i++)if(dis(O,p[i])>r+eps){
        O=p[i],r=0;
        for(int j=1;j<i;j++)if(dis(O,p[j])>r+eps){
            O=Mid(p[i],p[j]),r=dis(O,p[i]);
            for(int k=1;k<j;k++)if(dis(O,p[k])>r+eps){
                O=Circle(p[i],p[j],p[k]),r=dis(O,p[i]);
            }
        }
    }
    printf("%.2lf %.2lf %.2lf",O.x,O.y,r);
    return 0;
}

