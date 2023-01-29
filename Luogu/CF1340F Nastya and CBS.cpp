/************************
*FileName:
*Author: Zimse
*Data: 2023-01-
*Description:
************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define pb push_back
#define ll long long
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007,SZ=512,B=43;

int n,m,q,a[N],cnt,In[N],stk[N],rm[N],p43[N];

struct block{
    int L,R,lh[SZ+2],tot,rh,rtot,tag;

    void build(){
        tot=rh=rtot=tag=0;
        for(int i=L;i<=R;i++){
            if(a[i]>0)stk[++tot]=a[i];
            else{
                if(tot&&a[i]==-stk[tot])--tot;
                else if(!tot)rh=(rh*B-a[i]+Mod)%Mod,++rtot;
                else tag=1;
            }
        }
        lh[tot+1]=0;
        for(int i=tot;i>=1;i--)lh[i]=(lh[i+1]*B+stk[i])%Mod;
    }
}b[512];

signed main(){
    p43[0]=1;
    for(int i=1;i<N;i++)p43[i]=p43[i-1]*B%Mod;
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int l=1,r=0;l<=n;){
        r=min(l+SZ-1,n),++cnt;
        b[cnt].L=l,b[cnt].R=r;
        b[cnt].build();
        for(int i=l;i<=r;i++)In[i]=cnt;
        l=r+1;
    }
    q=read();
    while(q--){
        int op=read(),l=read(),r=read();
        if(op==1){
            a[l]=r;
            b[In[l]].build();
        }
        else{
            int L=In[l],R=In[r];
            if(L==R){
                b[cnt+1].L=l,b[cnt+1].R=r;
                b[cnt+1].build();
                _ck(b[cnt+1].tot==0&&b[cnt+1].rtot==0);
            }
            else{
                b[cnt+1].L=l,b[cnt+1].R=b[L].R,b[cnt+1].build();
                b[cnt+2].L=b[R].L,b[cnt+2].R=r,b[cnt+2].build();
                int tag=1,top=0;
                for(int i=L,id=0;i<=R;i++){
                    if(i==L)id=cnt+1;
                    else if(i==R)id=cnt+2;
                    else id=i;
                    if(b[id].tag){
                        tag=0;
                        break;
                    }
                    int s=0,lh=0;
                    while(s<b[id].rtot){
                        if(!top){
                            lh=-1;
                            break;
                        }
                        int len=min(b[id].rtot-s,rm[top]),t=stk[top];
                        int h=(b[t].lh[rm[top]-len+1]-b[t].lh[rm[top]+1]*p43[len]%Mod+Mod)%Mod;
                        lh=(lh*p43[len]+h)%Mod;
                        rm[top]-=len,s+=len;
                        if(!rm[top])--top;
                    }
                    if(lh!=b[id].rh){
                        tag=0;
                        break;
                    }
                    if(b[id].tot)stk[++top]=id,rm[top]=b[id].tot;
                }
                if(top)tag=0;
                _ck(tag);
            }
        }
    }
    return 0;
}
