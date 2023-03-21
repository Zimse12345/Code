/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline void _max(double& x,double y){if(x<y)x=y;return;}
inline void _min(double& x,double y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=2048;

struct point{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){}
}p[N];
int n,k;
double ans,f[N][N];

double dis(point x,point y){
    return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}

signed main(){
    // ifile("circle.in");
    // ofile("circle.out");

    n=read(),k=read();
    for(int i=0;i<n;i++){
        double x,y;
        scanf("%lf%lf",&x,&y);
        p[i]=point(x,y);
    }
    if(k<=2){
        printf("0.0");
        return 0;
    }
    int V=n;
    if(n>200)V=1;
    for(int i=0;i<V&&i+k-1<n;i++){
        for(int j=0;j<=k;j++)f[i][j]=-INF;
        f[i][1]=0;
        for(int j=i+1;j<n;j++){
            for(int t=0;t<=k;t++)f[j][t]=-INF;
            for(int t=2;t<=min(k,j-i+1);t++){
                int b=i+t-2;
                if(n>200&&j-n/k-2>b)b=j-n/k-2;
                for(int pre=b;pre<j;pre++){
                    _max(f[j][t],f[pre][t-1]+dis(p[pre],p[j]));
                }
            }
            _max(ans,f[j][k]+dis(p[i],p[j]));
        }
    }
    printf("%.9lf\n",ans);
    return 0;
}
