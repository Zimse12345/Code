// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
// #define int long long
#define Lid ch[id][0]
#define Rid ch[id][1]
#define M ((L+R)/2)
#define lnum (num*2)
#define rnum (num*2+1)
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
int n,q;
int ch[N*16][2],rt[N],tot,t[N*4],fa[N*16],_rt[N*16];

void build(int &id,int L,int R,int num){
    id=++tot,t[num]=id;
    if(L!=R)build(Lid,L,M,lnum),build(Rid,M+1,R,rnum),fa[Lid]=fa[Rid]=id;
    return;
}

void split(int &id,int L,int R,int l,int r,int &_id,int num){
    if(!id)return;
    if(l<=L&&r>=R){
        swap(_id,id);
        return;
    }
    if(r<L||R<l)return;
    _id=++tot;
    split(Lid,L,M,l,r,ch[_id][0],lnum);
    split(Rid,M+1,R,l,r,ch[_id][1],rnum);
    if(!ch[_id][0]&&!ch[_id][1])_id=0;
    if(_id)fa[ch[_id][0]]=fa[ch[_id][1]]=_id;
    if(_id&&t[num]==id)t[num]=_id;
    if(!Lid&&!Rid)id=0;
    return;
}

int merge(int id,int _id,int L,int R,int num){
    if(!id||!_id)return id|_id;
    Lid=merge(Lid,ch[_id][0],L,M,lnum);
    Rid=merge(Rid,ch[_id][1],M+1,R,rnum);
    fa[Lid]=fa[Rid]=id;
    return id;
}

int find(int id,int L,int R,int l,int r){
    if(!id)return 0;
    if(l<=L&&r>=R)return 1;
    if(r<L||R<l)return 0;
    return find(Lid,L,M,l,r)|find(Rid,M+1,R,l,r);
}

int query(int num,int L,int R,int l,int r){
    if(l<=L&&r>=R){
        int pos=t[num];
        while(fa[pos])pos=fa[pos];
        return _rt[pos];
    }
    if(r<L||R<l)return 0;
    return max(query(lnum,L,M,l,r),query(rnum,M+1,R,l,r));
}

signed main(){
    n=read(),q=read();
    build(rt[0],1,n,1);
    int mx=0;
    while(q--){++mx;
        int op=read(),l=read(),r=read(),x=0;
        if(op==1){
            x=read();
            int m=0;
            split(rt[x],1,n,l,r,m,1);
            rt[x+1]=merge(rt[x+1],m,1,n,1);
            _rt[rt[x]]=x;
            _rt[rt[x+1]]=x+1;
        }
        if(op==2){
            x=query(1,1,n,l,r);
            _wri(x);
        }
    }
    return 0;
}

