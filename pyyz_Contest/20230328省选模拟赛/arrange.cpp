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

const int N=1000007;

int n,q,A[N],P[N],vis[N],s[N],tot;
char opt[16];
set<int> pos[N],Sz;

struct node{
    int l,r,fa,sz,ky,mn;
    node(int l=0,int r=0,int fa=0,int sz=0,int ky=0,int mn=0):l(l),r(r),fa(fa),sz(sz),ky(ky),mn(mn){}
}t[N];

inline void maintain(int id){
    t[id].sz=t[t[id].l].sz+t[t[id].r].sz+1;
    t[id].fa=0,t[id].mn=id;
    if(t[id].l)t[t[id].l].fa=id,_min(t[id].mn,t[t[id].l].mn);
    if(t[id].r)t[t[id].r].fa=id,_min(t[id].mn,t[t[id].r].mn);
    return;
}

void split(int id,int x,int &l,int &r){
    if(!id){l=r=0;return;}
    if(t[t[id].l].sz<x)l=id,split(t[id].r,x-t[t[id].l].sz-1,t[id].r,r);
    else r=id,split(t[id].l,x,l,t[id].l);
    maintain(id);
    return;
}

int merge(int l,int r){
    if(!l||!r)return l|r;
    if(t[l].ky<t[r].ky){
        t[l].r=merge(t[l].r,r);
        maintain(l);
        return l;
    }
    t[r].l=merge(l,t[r].l);
    maintain(r);
    return r;
}

inline int qrank(int x){
    int res=t[x].sz-t[t[x].r].sz;
    while(t[x].fa){
        int p=t[x].fa;
        if(t[p].r==x)res+=1+t[t[p].l].sz;
        x=p;
    }
    return res;
}

int kth(int id,int k){
    if(k<=t[t[id].l].sz)return kth(t[id].l,k);
    if(k>t[t[id].l].sz+1)return kth(t[id].r,k-t[t[id].l].sz-1);
    return id;
}

inline void Ins(int sz,int mn){
    if(pos[sz].empty()){
        pos[sz].insert(mn);
        Sz.insert(mn);
    }
    else{
        if(mn<*pos[sz].begin()){
            Sz.erase(*pos[sz].begin());
            Sz.insert(mn);
        }
        pos[sz].insert(mn);
    }
    return;
}

inline void Era(int sz,int mn){
    pos[sz].erase(mn);
    if(pos[sz].empty()){
        Sz.erase(mn);
    }
    else if(mn<*pos[sz].begin()){
        Sz.erase(mn);
        Sz.insert(*pos[sz].begin());
    }
    return;
}

signed main(){
    srand(time(0));
    srand(rand());
    n=read(),q=read();
    for(int i=1;i<=n;i++)A[i]=P[i]=i,t[i]=node(0,0,0,1,rand(),i),Ins(1,i);
    while(q--){
        scanf("%s",opt+1);
        int x=read(),y=read();
        if(opt[1]=='s'){
            if(opt[6]=='a')swap(A[x],A[y]);
            else{
                int rx=x,ry=y;
                while(t[rx].fa)rx=t[rx].fa;
                while(t[ry].fa)ry=t[ry].fa;
                if(rx==ry){
                    Era(t[rx].sz,t[rx].mn);
                    int rk=qrank(x);
                    int l,r;
                    split(rx,rk,l,r);
                    rx=merge(r,l);
                    rk=qrank(y);
                    split(rx,rk,l,r);
                    if(l)Ins(t[l].sz,t[l].mn);
                    if(r)Ins(t[r].sz,t[r].mn);
                }
                else{
                    Era(t[rx].sz,t[rx].mn);
                    Era(t[ry].sz,t[ry].mn);
                    int l,r,rk,p;
                    rk=qrank(x),split(rx,rk,l,r),rx=merge(r,l);
                    rk=qrank(y),split(ry,rk,l,r),ry=merge(r,l);
                    p=merge(rx,ry);
                    Ins(t[p].sz,t[p].mn);
                }
            }
        }
        else{
            int tag=1;
            for(set<int>::iterator it=Sz.begin();it!=Sz.end();it++){
                int p=*it;
                while(t[p].fa)p=t[p].fa;
                int sz=t[p].sz;
                if(x%sz==y%sz)continue;
                while(t[p].fa)p=t[p].fa;
                int mn=t[p].mn,l,r,rk=qrank(mn);
                split(p,rk-1,l,r),p=merge(r,l);
                l=A[kth(p,(x-1)%sz+1)],r=A[kth(p,(y-1)%sz+1)];
                if(l<r)printf("<\n");
                else printf(">\n");
                tag=0;
                break;
            }
            if(tag)printf("=\n");
        }
    }
    return 0;
}
