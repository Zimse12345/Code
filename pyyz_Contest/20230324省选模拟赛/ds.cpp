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
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=131072,P=100043;

struct node{
    int l,r,v;
    node(int l=0,int r=0,int v=0):l(l),r(r),v(v){}
    bool operator < (const node& _)const{
        if(l==_.l){
            if(r==_.r)return v<_.v;
            return r<_.r;
        }
        return l<_.l;
    }
}p[N];
int n,m,val[N],ans[N],V[32][32];

struct HashTable{
    int hd[P],nxt[N],tot,val1[N],val2[N],stk[N],top;

    inline void ins(const node p,const int v){
        int h1=(p.l*1019+(p.r+1)*100057+p.v*1000171)%P;
        int h2=(p.l*107+(p.r+1)*100019+p.v*1000000087)%1000000000000000177;
        int pos=hd[h1];
        if(!pos)stk[++top]=h1;
        while(pos&&val1[pos]!=h2)pos=nxt[pos];
        if(pos&&val1[pos]==h2)val2[pos]+=v;
        else nxt[++tot]=hd[h1],hd[h1]=tot,val1[tot]=h2,val2[tot]=v;
        return;
    }

    inline int qry(const node p){
        int h1=(p.l*1019+(p.r+1)*100057+p.v*1000171)%P;
        int h2=(p.l*107+(p.r+1)*100019+p.v*1000000087)%1000000000000000177;
        int pos=hd[h1];
        while(pos&&val1[pos]!=h2)pos=nxt[pos];
        if(val1[pos]==h2)return val2[pos];
        return 0;
    }

    inline void clear(){
        while(top)hd[stk[top--]]=0;
        tot=0;
        return;
    }
}ht;

signed main(){
    n=read(),m=read();
    int sum=0;
    for(int i=1;i<=n;i++){
        int typ=read(),l=read(),r=read(),k=read(),t=read();
        int B=m-1;
        while(B>=k&&(1<<B)>=(r-l+1))--B;
        if(typ==1)val[i]=read();
        p[i]=node(k,B,l|t);
        sum+=val[i]*((r-l+1)/(1ll<<k));
    }
    for(int l=0;l<=m;l++){
        for(int r=l-1;r<=m;r++){
            V[l][r+1]=(1<<m)-1;
            for(int i=l;i<=min(m-1,r);i++)V[l][r+1]^=(1<<i);
        }
    }
    for(int l=0;l<=m;l++){
        for(int r=l-1;r<=m;r++){
            ht.clear();
            for(int i=1;i<=n;i++){
                if(val[i]){
                    node _p=p[i];
                    _p.v&=V[l][r+1];
                    ht.ins(_p,val[i]*(1ll<<max(0ll,min(r,_p.r)-max(l,_p.l)+1)));
                }
                else if(p[i].l==l&&p[i].r==r){
                    for(int _l=0;_l<=m;_l++){
                        for(int _r=_l-1;_r<=m;_r++){
                            ans[i]+=ht.qry(node(_l,_r,p[i].v&V[_l][_r+1]));
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)if(!val[i])_write(ans[i]);
    return 0;
}
