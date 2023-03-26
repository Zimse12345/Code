/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)

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
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int n,a[N],f[N],presum[N],lpos[N],rpos[N],sum,mn[N*4],pre[N];

void update(int id,int L,int R,int x,int y){
    if(L==R)mn[id]=y;
    else{
        if(x<=M)update(Lid,L,M,x,y);
        else update(Rid,M+1,R,x,y);
        mn[id]=min(mn[Lid],mn[Rid]);
    }
    return;
}

int query(int id,int L,int R,int x){
    if(mn[id]>=x)return 0;
    if(L==R)return L;
    int l=query(Lid,L,M,x);
    return l?l:query(Rid,M+1,R,x);
}

signed main(){
    // ifile("lamp.in");
    // ofile("lamp.out");

    n=read();
    f[0]=presum[0]=1;
    for(int i=1;i<=n;i++){
        a[i]=read();
        update(1,0,n,a[i],i),pre[a[i]]=i;
        if(lpos[0])++rpos[0];
        else lpos[0]=rpos[0]=i;
        if(lpos[a[i]]){
            for(int r=rpos[a[i]],l=r+1;r>=lpos[a[i]];r=l-1){
                int mex=query(1,0,n,r);
                l=max(lpos[a[i]],pre[mex]+1);
                if(!lpos[mex])lpos[mex]=l;
                rpos[mex]=r;
                addmod(sum,(mex-a[i])*(presum[r-1]-(l>1?presum[l-2]:0)));
            }
            lpos[a[i]]=rpos[a[i]]=0;
        }
        f[i]=sum,presum[i]=(presum[i-1]+f[i])%Mod;
    }
    addmod(f[n],Mod);
    _write(f[n]);
    return 0;
}
