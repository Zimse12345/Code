// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.01e9,Mod=1000000007;int read(){int x=0
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
int n,q,a[N],ans[N],L[N],R[N],top,sum[N],psum[N],p2[N],pre[N];
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};
vector<node> Q[N];

inline int calc(int x,int y){
    if(!x)return 0;
    while(y>0&&x<=Mod*2)x*=2,--y;
    x*=p2[y];
    if(x>=Mod*2)x=x%Mod+Mod*2;
    return x;
}

signed main(){
    p2[0]=1;
    for(int i=1;i<N;i++)p2[i]=p2[i-1]*2%Mod;
    n=read(),q=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        pre[i]=(pre[i-1]+a[i]*p2[i-1])%Mod;
    }
    for(int i=1,l,r;i<=q;i++){
        l=read(),r=read();
        Q[r].pb(node(l,i));
    }
    for(int i=1;i<=n;i++){
        if(i==1||a[i]<0){
            ++top;
            L[top]=R[top]=i;
            sum[top]=a[i];
        }
        else{
            int x=a[i];
            while(top>1&&calc(x,R[top]-L[top]+1)+sum[top]>=0){
                x=sum[top]+calc(x,R[top]-L[top]+1);
                sum[top--]=0;
            }
            _mod(sum[top],calc(x,R[top]-L[top]+1));
            R[top]=i;
        }
        psum[top]=(psum[top-1]+sum[top])%Mod;
        for(unsigned j=0;j<Q[i].size();j++){
            int pos=Q[i][j].x;
            int l=1,r=top,t=top+1;
            while(l<=r){
                int mid=(l+r)/2;
                if(pos<=L[mid])t=mid,r=mid-1;
                else l=mid+1;
            }
            int s=(psum[top]-psum[min(top,t)])*2;
            s+=sum[t]*(pos<L[t]?2:1);
            _mod(s,(pre[R[t-1]]-pre[pos-1]+Mod)*inv(p2[pos-1]));
            ans[Q[i][j].y]=s;
        }
    }
    for(int i=1;i<=q;i++)_mod(ans[i],Mod),_wri(ans[i]);
    return 0;
}

