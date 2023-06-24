// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
#define M ((L+R)/2)
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

const int N=8.01e6;
int a1,b1,a2,b2,q,t[N],len;
int val[N],mxsuf[N],presum[N];

struct node{
    int pos,v;
    node(int pos=0,int v=0):pos(pos),v(v){}
    bool operator < (const node &_)const{return pos<_.pos;}
}p[N];
int tot;

inline int Qmx(int n){
    int L=1,R=tot,t=0;
    while(L<=R){
        if(p[M].pos<=n)t=M,L=M+1;
        else R=M-1;
    }
    return max(mxsuf[t]+val[t]*(n-p[t].pos+1),0ll);
}

inline int Qsum(int n){
    int L=1,R=tot,t=0;
    while(L<=R){
        if(p[M].pos<=n)t=M,L=M+1;
        else R=M-1;
    }
    return presum[t]+val[t]*(n-p[t].pos+1);
}

signed main(){
    iF("snow.in");
    oF("snow.out");

    a1=read(),b1=read(),a2=read(),b2=read(),q=read();
    len=(a1+b1)*(a2+b2);
    for(int i=0;i<=max(a1+b1,a2+b2);i++){
        if(i*(a1+b1)+1<=len)p[++tot]=node(i*(a1+b1)+1,1);
        if(i*(a1+b1)+a1+1<=len)p[++tot]=node(i*(a1+b1)+a1+1,-1);
        if(i*(a2+b2)+1<=len)p[++tot]=node(i*(a2+b2)+1,-1);
        if(i*(a2+b2)+a2+1<=len)p[++tot]=node(i*(a2+b2)+a2+1,1);
    }
    p[++tot]=node(len+1,0);
    sort(p+1,p+tot+1);
    for(int i=1;i<=tot;i++){
        val[i]=val[i-1]+p[i].v;
        presum[i]=presum[i-1]+(p[i].pos-p[i-1].pos)*val[i-1];
        mxsuf[i]=max(mxsuf[i-1]+(p[i].pos-p[i-1].pos)*val[i-1],0ll);
    }
    while(q--){
        int n=read();
        int r=n/(a1+b1)*a1+min(n%(a1+b1),a1);
        int d=Qmx(n%len);
        if(n>len){
            int s=Qsum(n%len);
            _max(d,s+mxsuf[tot]);
            _max(d,presum[tot]*(n/len-1)+s+mxsuf[tot]);
        }
        _wri(r-d);
    }
    return 0;
}

