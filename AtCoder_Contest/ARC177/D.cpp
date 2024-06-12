// Author:Zimse  Data:2023-07-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
 #define int long long
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
int n,h,p[N],q[N],L[N],R[N],stk[N],tp;

struct node{
    int x,y,z;
    node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
    bool operator < (const node& _)const{return x<_.x;}
}a[N],t[N];
int c,vis[N];

signed main(){
    n=read(),h=read();
    for(int i=1,x;i<=n;i++){
        x=read();
        a[i]=node(x,i);
    }
    sort(a+1,a+n+1);
    for(int i=0;i<=n;i++)p[i]=1;
    p[0]=0;
    for(int l=1,r;l<=n;){
        r=l;
        while(r<n&&a[r+1].x-a[r].x<=h)++r;
        c=0;
        for(int i=l;i<=r;i++)t[++c]=node(a[i].y,i-l+1);
        for(int i=1;i<=c;i++)vis[i]=0;
        vis[0]=vis[c+1]=1;
        tp=0;
        for(int i=1;i<=c;i++){
            while(tp&&t[i].x<t[stk[tp]].x)--tp;
            stk[++tp]=i;
            t[i].z=tp;
        }
        tp=0;
        for(int i=c;i>=1;i--){
            while(tp&&t[i].x<t[stk[tp]].x)--tp;
            stk[++tp]=i;
            t[i].z+=tp-1;
        }
        sort(t+1,t+c+1);
        int sum=0;
        for(int i=1;i<=c;i++){
            int P=0;
            vis[t[i].y]=1;
            if(vis[t[i].y-1]){
                _mod(P,fpow(inv(2),t[i].z));
            }
            if(vis[t[i].y+1]){
                _mod(P,fpow(inv(2),t[i].z));
            }
            _mod(sum,P);
            (p[t[i].x-1]*=inv(sum))%=Mod;
            if(i<c)(p[t[i+1].x-1]*=sum)%=Mod;
            else (p[n]*=sum)%=Mod;
        }
        p[t[1].x-1]=0;
        l=r+1;
    }
    for(int i=n-1;i>=0;i--)(p[i]*=p[i+1])%=Mod;
    for(int i=0;i<=n;i++){
        p[i]=(Mod+1-p[i])%Mod;
    }
    for(int i=0;i<n;i++)wri(((p[i]-p[i+1])*fpow(2,n)%Mod+Mod)%Mod);
    pc(10); 
    return 0;
}



