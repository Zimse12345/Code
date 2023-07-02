// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
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
int n,m;
struct point{
    int x,y;
    point(int x=0,int y=0):x(x),y(y){}
    point operator - (const point &_)const{return point(x-_.x,y-_.y);}
    int operator * (const point &_)const{return x*_.y-y*_.x;}
}p[N],q[N],o,stk[N];

inline int dis2(point a,point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

inline bool cmp(point a,point b){
    if(0==(a-o)*(b-o))return dis2(a,o)>dis2(b,o);
    return 0<(a-o)*(b-o);
}

signed main(){
    iF("psg.in");
    oF("psg.out");
    
    n=read();
    for(int i=1,x,y;i<=n;i++){
        x=read(),y=read();
        p[i]=point(x,y);
    }
    m=read();
    while(m--){
        int l=read(),u=read(),r=read(),d=read(),tot=0,top=0,ans=0;
        o=point(INF,INF);
        for(int i=1;i<=n;i++){
            if(l<=p[i].x&&p[i].x<=r&&u<=p[i].y&&p[i].y<=d){
                q[++tot]=p[i];
                if(q[tot].y<q[1].y||(q[tot].y==q[1].y&&q[tot].x<q[1].x))swap(q[tot],q[1]);
            }
        }
        o=q[1];
        sort(q+2,q+tot+1,cmp);
        stk[++top]=o,q[tot+1]=o;
        for(int i=2;i<=tot+1;i++){
             if(0==(q[i]-o)*(q[i-1]-o)&&i<=tot&&i>2)continue;
            int tag=1;
            while(top>1){
                int v=(stk[top]-stk[top-1])*(q[i]-stk[top]);
                if(v<=0)--top;
                else break;
            }
            if(tag)stk[++top]=q[i];
        }
        for(int i=2;i<top;i++){
            ans+=(stk[i]-o)*(stk[i+1]-o);
        }
        printf("%.1lf\n",double(ans)/2.0);
    }
    return 0;
}


