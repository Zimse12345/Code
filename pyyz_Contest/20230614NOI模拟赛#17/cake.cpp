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

const int N=1.01e7;
int n,a[N],b[N],mn=INF,mnpos,cur;
int lc[N],rc[N],stk[N],top;
long long sum[N][2],ans[N],s;

inline long long query(int l,int r,int t){
    return sum[r][t&1]-sum[l-1][t&1];
}

void dfs(int pos,int l,int r){
    ans[pos]=s+a[pos];
    int L=l,R=r,p=lc[pos],q=rc[pos];
    while(p||q){
        if(p&&(!q||a[p]<a[q])){
            ans[pos]+=query(L,p,(R-p)^p);
            L=p+1,p=rc[p];
        }
        else{
            ans[pos]+=query(q,R,(q-L)^q);
            R=q-1,q=lc[q];
        }
    }
    if(lc[pos]){
        s+=query(pos,r,(pos-l)^pos);
        dfs(lc[pos],l,pos-1);
        s-=query(pos,r,(pos-l)^pos);
    }
    if(rc[pos]){
        s+=query(l,pos,(r-pos)^pos);
        dfs(rc[pos],pos+1,r);
        s-=query(l,pos,(r-pos)^pos);
    }
    return;
}

signed main(){
    iF("cake.in");
    oF("cake.out");

    n=read();
    for(int i=1;i<=n;i++){
        b[i]=read();
        if(b[i]<mn)mn=b[i],mnpos=i;
    }
    for(int i=mnpos+1;i<=n;i++)a[++cur]=b[i];
    for(int i=1;i<=mnpos;i++)a[++cur]=b[i];
    for(int i=1;i<=n;i++){
        sum[i][0]=sum[i-1][0],sum[i][1]=sum[i-1][1];
        sum[i][i&1]+=a[i];
    }
    for(int i=1;i<n;i++){
        while(top&&a[i]<a[stk[top]])lc[i]=stk[top],--top;
        if(top)rc[stk[top]]=i;
        stk[++top]=i;
    }
    lc[n]=stk[1];
    dfs(n,1,n);
    ans[n]=a[n];
    int l=1,r=n-1;
    while(l<=r){
        if((n-(r-l+1))%2==0)ans[n]+=max(a[l],a[r]);
        if(a[l]<a[r])--r;
        else ++l;
    }
    for(int i=n-mnpos+1;i<=n;i++)printf("%lld\n",ans[i]);
    for(int i=1;i<=n-mnpos;i++)printf("%lld\n",ans[i]);
    return 0;
}

