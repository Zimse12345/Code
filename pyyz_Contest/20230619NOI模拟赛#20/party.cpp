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

const int N=1.01e6;
int n,m,t,a[N],b[N];
vector<array<int,2>> p[N];
priority_queue<array<int,3>> q;

inline bool check(int w,int c){
    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++)b[i]=0;
    for(int i=1,s=0;i<=t;i++){
        for(auto&x:p[i])if(x[0]>t)q.push({x[0],i,x[1]});
        int k=(a[i]+c-w+1)/2;
        while(s<k&&!q.empty()){
            auto x=q.top();
            q.pop();
            int v=min(x[2],k-s);
            s+=v,x[2]-=v,b[x[1]]+=v,b[x[0]]-=v;
            if(x[2])q.push(x);
        }
    }
    for(int i=1;i<=n;i++){
        b[i]+=b[i-1];
        if(a[i]+c-b[i]*2>w)return false;
    }
    return true;
}

signed main(){
    iF("party.in");
    oF("party.out");

    n=read(),m=read();
    int sum=0;
    while(m--){
        int l=read(),r=read(),x=read();
        if(l>r)swap(l,r);
        a[l]+=x,a[r]-=x;
        p[l].push_back({r,x});
        sum+=min(r-l+1,n-(r-l+1));
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
        if(a[i]>a[t])t=i;
    }
    int L=max(0ll,sum/n),R=a[t],ans=a[t];
    while(L<=R){
        if(check(M,a[t]-M)||check(M,a[t]-M+1))ans=M,R=M-1;
        else L=M+1;
    }
    _wri(ans);
    return 0;
}

