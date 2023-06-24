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

const int N=2.01e6;
int n,a[N],L[N],R[N],sum[N][2],LL[N],RR[N];

void bf(){
    for(int i=n;i<n+n;i++){
        int l=i,r=i,s=a[i];
        while(r-l+1<n){
            if(a[l-1]>a[r+1]){
                --l;
                if((r-l+1)&1)s+=a[l];
            }
            else{
                ++r;
                if((r-l+1)&1)s+=a[r];
            }
        }
        _wri(s);
    }
    return;
}

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node &_)const{
        if(x==_.x)return y<_.y;
        return x<_.x;
    }
};
map<node,int> mp;

inline int query(int l,int r){
    int _l=l,_r=r;
    if(a[l-1]==a[r+1]){
        if(n&1)return a[l-1];
        return 0;
    }
    if(mp[node(l,r)])return mp[node(l,r)];
    int s=0;
    if(a[l-1]>a[r+1]){
        int to=L[r+1];
        if(l<=to&&to<=r)to=LL[r+1];
        int o=(l-1)&1;
        if((r-l+1)&1)o^=1;
        s=(sum[l-1][o]-sum[to][o]);
        l=to+1;
    }
    else{
        int to=R[l-1];
        if(l<=to&&to<=r)to=RR[l-1];
        int o=(r+1)&1;
        if((r-l+1)&1)o^=1;
        s=(sum[to-1][o]-sum[r][o]);
        r=to-1;
    }
    int res=s+query(l,r);
    mp[node(_l,_r)]=res;
    return res;
}

signed main(){
    iF("cake.in");
    oF("cake.out");

    n=read();
    for(int i=0;i<n;i++)a[i]=a[i+n]=a[i+n+n]=read();
    if(n<=5000){
        bf();
        return 0;
    }
    for(int i=0;i<n*3;i++){
        sum[i][0]=sum[i-1][0],sum[i][1]=sum[i-1][1];
        sum[i][i&1]+=a[i];
        L[i]=i-1,R[i]=i+1;
        while(L[i]>=0&&a[L[i]]>a[i])--L[i];
        while(R[i]<n*3&&a[R[i]]>a[i])++R[i];
        LL[i]=L[i]-1;
        RR[i]=R[i]+1;
        while(LL[i]>=0&&a[LL[i]]>a[i])--LL[i];
        while(RR[i]<n*3&&a[RR[i]]>a[i])++RR[i];
    }
    for(int i=n;i<n+n;i++){
        int l=i,r=i,s=a[i];
        s+=query(l,r);
        _wri(s);
    }
    return 0;
}

