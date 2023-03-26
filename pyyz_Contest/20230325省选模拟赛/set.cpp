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
#define Lid ch[id][0]
#define Rid ch[id][1]

namespace Zimse{
const int INF=1000000000000114514,Mod=998244353;//1000000007
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

const int N=500007;

int V,n,a[N],m,RR,mn[N*40],tag[N*40];
signed ch[N*40][2],tot,rt;
set<int> s;

void pushdown(signed id){
    if(tag[id]==INF)return;
    if(!Lid)Lid=++tot,mn[tot]=tag[tot]=INF;
    if(!Rid)Rid=++tot,mn[tot]=tag[tot]=INF;
    _min(tag[Lid],tag[id]);
    _min(tag[Rid],tag[id]);
    _min(mn[id],tag[id]),tag[id]=INF;
    return;
}

void update(signed &id,int L,int R,int l,int r,int v){
    if(!id)id=++tot,mn[id]=tag[id]=INF;
    pushdown(id);
    if(l<=L&&r>=R)tag[id]=v,pushdown(id);
    else{
        if(l<=M)update(Lid,L,M,l,r,v);
        if(r>M)update(Rid,M+1,R,l,r,v);
        mn[id]=min(mn[Lid],mn[Rid]);
    }
    return;
}

int query(signed id,int L,int R,int l,int r){
    if(!id)return INF;
    pushdown(id);
    if(l<=L&&r>=R)return mn[id];
    if(r<=M)return query(Lid,L,M,l,r);
    if(l>M)return query(Rid,M+1,R,l,r);
    return min(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

int ck(int i,int j){
    int res=(i^j);
    update(rt,0,RR,0,RR,res);
    for(int w=0;w<V+1;w++){
        int p=(1ll<<w);
        if((i&p)&&(!(j&p))){
            int a=i%p,b=j%p;
            if(b>a){
                int v=p-b;
                _min(res,(i+v)^(j+v));
                update(rt,0,RR,v,v,res);
            }
        }
        if((j&p)&&(!(i&p))){
            int a=i%p,b=j%p;
            if(a>b){
                int v=p-a;
                _min(res,(i+v)^(j+v));
                update(rt,0,RR,v,v,res);
            }
        }
    }
    return res;
}

signed main(){
    // ifile("set.in");
    // ofile("set.out");

    mn[0]=INF;
    V=read(),n=read();
    RR=(1ll<<V)-1;
    s.insert(-INF),s.insert(INF);
    for(int i=1;i<=n;i++){
        int op=read(),w=read();
        if(op==1){
            set<int>::iterator it=s.upper_bound(w);
            int R=*it;
            --it;
            int L=*it;
            if(R!=INF)ck(w,R);
            if(L!=-INF)ck(L,w);
            s.insert(w);
        }
        else{
            _write(query(rt,0,RR,0,w));
        }
    }
    return 0;
}
