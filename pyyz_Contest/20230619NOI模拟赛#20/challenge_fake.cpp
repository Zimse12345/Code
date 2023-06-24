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
const double eps=1e-9;
int n,m,ans[N],tot;

struct point{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){}
    point operator - (const point &_)const{return point(x-_.x,y-_.y);}
}p[N];

struct node{
    double x,r;
    int w;
    node(double x=0,double r=0,int w=0):x(x),r(r),w(w){}
    bool operator < (const node &_)const{return x<_.x;}
}s[N];

inline double Cross(point a,point b){
    return a.x*b.y+a.y*b.x;
}

inline double Dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline point Mid(point a,point b){
    return point((a.x+b.x)/2.0,(a.y+b.y)/2.0);
}

inline double getS(point a,point b,point c){
    return abs(Cross(b-a,c-a));
}

inline bool eq(point a,point b){
    return abs(a.x-b.x)<eps&&abs(a.y-b.y)<eps;
}

inline bool Inline(point a,point b,point c){
    if(eq(a,b)||eq(a,c)||eq(b,c))return true;
    if(abs(a.x-b.x)<eps&&abs(a.x-c.x)<eps)return true;
    if(abs(a.x-b.x)<eps||abs(a.x-c.x)<eps||abs(b.x-c.x)<eps)return false;
    return abs((a.y-b.y)/(a.x-b.x)-(a.y-c.y)/(a.x-c.x))<eps;
}

signed main(){
    iF("challenge.in");
    oF("challenge.out");

    n=read(),m=read();
    for(int i=1,x,y;i<=n;i++){
        x=read(),y=read();
        p[i]=point(x,y);
    }
    ans[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(Inline(p[i],p[j],p[k]))continue;
                double mx=max(max(Dis(p[i],p[j]),Dis(p[j],p[k])),Dis(p[k],p[i]));
                int cnt=3;
                point a=p[i],b=p[j],c=p[k];
                double X=((b.y-a.y)*(c.y*c.y-a.y*a.y+c.x*c.x-a.x*a.x)
                    -(c.y-a.y)*(b.y*b.y-a.y*a.y+b.x*b.x-a.x*a.x))
                    /(2.0*((c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y)));
                double Y=((b.x-a.x)*(c.x*c.x-a.x*a.x+c.y*c.y-a.y*a.y)
                    -(c.x-a.x)*(b.x*b.x-a.x*a.x+b.y*b.y-a.y*a.y))
                    /(2.0*((c.y-a.y)*(b.x-a.x)-(b.y-a.y)*(c.x-a.x)));
                double R=Dis(a,point(X,Y));
                // double S=getS(p[i],p[j],p[k]);
                for(int t=1;t<=n;t++)if(t!=i&&t!=j&&t!=k){
                    if(Dis(p[t],point(X,Y))-eps<R&&
                        Dis(p[i],p[t])+eps<mx&&Dis(p[j],p[t])+eps<mx&&Dis(p[k],p[t])+eps<mx)++cnt;
                    // if(abs(getS(p[i],p[j],p[t])+getS(p[i],p[k],p[t])+getS(p[j],p[k],p[t])-S)<eps)++cnt;
                }
                // if(int(ceil(mx))==5&&cnt==5){
                //     printf("(%d,%d,%d)\n",i,j,k);
                // }
                _max(ans[int(ceil(mx))],cnt);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            // if(!(i==3&&j==5))continue;
            // printf("(%d %d)\n",i,j);
            point a=p[i],b=p[j],o=Mid(a,b);
            double r=Dis(a,b)/2;
            tot=0;
            int t=2;
            for(int k=1;k<=n;k++)if(k!=i&&k!=j){
                point c=p[k];
                if(Inline(a,b,c)){
                    if(min(a.x,b.x)-eps<c.x&&c.x<max(a.x,b.x)+eps
                    &&min(a.y,b.y)-eps<c.y&&c.y<max(a.y,b.y)+eps)++t;
                    continue;
                }
                double X=((b.y-a.y)*(c.y*c.y-a.y*a.y+c.x*c.x-a.x*a.x)
                    -(c.y-a.y)*(b.y*b.y-a.y*a.y+b.x*b.x-a.x*a.x))
                    /(2.0*((c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y)));
                double Y=((b.x-a.x)*(c.x*c.x-a.x*a.x+c.y*c.y-a.y*a.y)
                    -(c.x-a.x)*(b.x*b.x-a.x*a.x+b.y*b.y-a.y*a.y))
                    /(2.0*((c.y-a.y)*(b.x-a.x)-(b.y-a.y)*(c.x-a.x)));
                double R=Dis(a,point(X,Y));
                s[++tot]=node(X,R,0);
                if(abs(a.y-b.y)<eps){
                    s[tot].x=Y;
                    if(c.y>a.y)s[tot].w=1;
                }
                else{
                    double K=(a.x-b.x)/(a.y-b.y);
                    double B=a.x-K*a.y;
                    double pos=K*c.y+B;
                    if(c.x>pos)s[tot].w=1;
                    // if(Dis(o,c)<r-eps&&X<o.x-eps)s[tot].w=1;
                    // if(Dis(o,c)+eps>r&&X>o.x+eps)s[tot].w=1;
                }
                // printf("k=%d (%.3lf %.3lf %d) Dis=%.3lf r=%.3lf X=%.3lf o.x=%.3lf\n"
                // ,k,s[tot].x,s[tot].r,s[tot].w,Dis(o,c),r,X,o.x);
                // printf("%.7lf %.7lf %.7lf\n",X,Y,R);
            }
            if(abs(a.y-b.y)<eps)s[++tot]=node(o.y,r,-1);
            else s[++tot]=node(o.x,r,-1);
            sort(s+1,s+tot+1);
            _max(ans[int(ceil(r*2))],t);
            for(int k=1;k<=tot;k++)if(s[k].w==0)++t;
            s[tot+1].x=s[tot+1].r=INF*2;
            for(int L=1,R;L<=tot;){
                R=L;
                while(R<tot&&s[R].x+eps>s[R+1].x)++R;
                for(int k=L;k<=R;k++)if(s[k].w==1)++t;
                // printf("[t=%d x=%.3lf r=%.3lf ceil=%d]\n",t,s[L].x,s[L].r,int(ceil(s[L].r*2)));
                if(s[L].x+eps<s[L+1].x&&ceil(s[L].r*2)<double(m+1))_max(ans[int(ceil(s[L].r*2))],t);
                for(int k=L;k<=R;k++)if(s[k].w==0)--t;
                L=R+1;
            }

            // s[tot+1].x=INF;
            // for(int k=1;k<=tot;k++){
            //     if(s[k].w==1)++t;
            //     if(s[k].x+eps<s[k+1].x&&ceil(s[k].r*2)<double(m+1))_max(ans[int(ceil(s[k].r*2))],t);
            //     if(s[k].w==0)--t;
            // }
            // if(ans[7]==6)printf("(%d,%d)\n",i,j);
            // break;
        }
    }
    for(int i=0;i<=m;i++){
        if(i)_max(ans[i],ans[i-1]);
        wri(ans[i]);
    }
    pc(10);
    return 0;
}

