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

const int N=1.01e5,M=2.01e5,B=270,Lim=100;
int n,q,a[N],pos[N],m[M],s[N];
int L[N],R[N],cnt,bel[N];
long long ans[M];
vector<int> ql[M],qr[M],presum[M];

struct Fenwick{
    int v[N];
    inline void ub(int &x){x+=(x&(-x));return;}
    inline void db(int &x){x-=(x&(-x));return;}
    inline void add(int x){for(;x<N;ub(x))v[x]++;return;}
    inline int sum(int x){int y=0;for(;x;db(x))y+=v[x];return y;}
    inline void clear(){for(int i=0;i<N;i++)v[i]=0;return;}
}fenwick,t;

struct qry{
    int l,id,v;
    qry(int l=0,int id=0,bool v=false):l(l),id(id),v(v){}
};
vector<qry> b[N];

signed main(){
//    iF("tears.in");
//    oF("tears.out");
    
    n=read(),q=read();
    for(int i=1;i<=n;i++)a[i]=read(),pos[a[i]]=i;
    for(int i=1,l,r;i<=q;i++){
        m[i]=read();
        if(m[i]>Lim){
            while(m[i]--){
                l=read(),r=read();
                for(int j=l;j<=r;j++)ans[i]+=fenwick.sum(a[j]);
                for(int j=l;j<=r;j++)fenwick.add(a[j]);
            }
            fenwick.clear();
            continue;
        }
        for(int j=0;j<m[i];j++)ql[i].pb(read()),qr[i].pb(read()),presum[i].pb(0);
        for(int x=0;x<m[i];x++)for(int y=x+1;y<m[i];y++){
            b[qr[i][y]].pb(qry(qr[i][x],i,true));
            b[qr[i][y]].pb(qry(ql[i][x]-1,i,false));
            b[ql[i][y]-1].pb(qry(qr[i][x],i,false));
            b[ql[i][y]-1].pb(qry(ql[i][x]-1,i,true));
        }
    }
    for(int l=1,r=0;l<=n;l=r+1){
        r=min(n,l+B-1);
        ++cnt,L[cnt]=l,R[cnt]=r;
        for(int i=l;i<=r;i++)bel[i]=cnt;
        for(int i=1;i<=n;i++)s[i]=s[i-1]+((l<=a[i]&&a[i]<=r)?1:0);
        for(int i=1;i<=q;i++){
            for(int j=1;j<m[i];j++)ans[i]+=1ll*(s[qr[i][j]]-s[ql[i][j]-1])*presum[i][j-1];
            for(int j=0,sumv=0;j<m[i];j++)sumv+=s[qr[i][j]]-s[ql[i][j]-1],presum[i][j]+=sumv;
        }
    }
    for(int i=1;i<=n;i++){
        int I=bel[a[i]];
        for(int j=L[I];j<a[i];j++)if(pos[j]<i)t.add(pos[j]);
        for(unsigned j=0;j<b[i].size();j++)ans[b[i][j].id]+=t.sum(b[i][j].l)*(b[i][j].v?1:-1);
    }
    for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
    return 0;
}

