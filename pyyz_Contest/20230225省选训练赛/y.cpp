/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
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
#define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
#define Lid ch[id][0]
#define Rid ch[id][1]

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

const int N=100007;

int n,m,val[N],ty[N],tot=1,ch[N*4][2];
char str[64];

struct Node{
    int A[2][2][76],B[2][2],mid[2],res[2],len[2][2],w,tag;
    void clear(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<76;k++)A[i][j][k]=0;
                B[i][j]=len[i][j]=0;
            }
            mid[i]=res[i]=0;
        }
        w=tag=0;
        return;
    }
    void MakeNode(int id){
        clear();
        if(ty[id])mid[0]=mid[1]=val[id];
        else B[0][0]=B[0][1]=B[1][0]=B[1][1]=val[id],mid[0]=mid[1]=-1;
        return;
    }
}t[N*4];
int rtag[N*4];

void Merge(Node& p,const Node& l,const Node& r,int id){
    if(p.w)rtag[id]^=1;
    int _w=rtag[id];
    p.clear();
    for(int w=0;w<2;w++){
        int lw=l.w^w,rw=r.w^w;
        for(int i=0;i<76;i++)p.A[w][0][i]=l.A[lw][0][i],p.A[w][1][i]=r.A[rw][1][i]; 
        p.len[w][0]=l.len[lw][0]+r.len[rw][0];
        p.len[w][1]=l.len[lw][1]+r.len[rw][1];
        p.len[w][w^_w]++;
        p.res[w]=l.res[lw]+r.res[rw];
        p.B[w][0]=l.B[lw][0],p.B[w][1]=r.B[rw][1];
        p.mid[w]=-1;
        if(_w^w){
            for(int i=0;i<l.B[lw][1];i++)p.res[w]+=r.A[rw][0][i];
            if(!l.len[lw][0])for(int i=l.B[lw][1];i<76;i++)p.A[w][0][i]+=r.A[rw][0][i];
            if(!r.len[rw][0])_max(p.B[w][1],l.B[lw][1]);
            if(r.mid[rw]!=-1){
                if(l.B[lw][1]>r.mid[rw])++p.res[w];
                else if(!l.len[lw][0])p.mid[w]=r.mid[rw];
                else p.A[w][1][r.mid[rw]]++;
            }
            if(l.mid[lw]!=-1)p.A[w][0][l.mid[lw]]++;
        }
        else{
            for(int i=0;i<r.B[rw][0];i++)p.res[w]+=l.A[lw][1][i];
            if(!r.len[rw][1])for(int i=r.B[rw][0];i<76;i++)p.A[w][1][i]+=l.A[lw][1][i];
            if(!l.len[lw][1])_max(p.B[w][0],r.B[rw][0]);
            if(l.mid[lw]!=-1){
                if(r.B[rw][0]>l.mid[lw])++p.res[w];
                else if(!r.len[rw][1])p.mid[w]=l.mid[lw];
                else p.A[w][0][l.mid[lw]]++;
            }
            if(r.mid[rw]!=-1)p.A[w][1][r.mid[rw]]++;
        }
    }
    return;
}

void Pushdown(int id){
    if(t[id].tag){
        t[id].tag=0,t[id].w^=1;
        if(Rid)t[Lid].tag^=1,t[Rid].tag^=1;
    }
    return;
}

void Build(int id,int L,int R){
    if(L==R)t[id].MakeNode(L);
    else{
        Lid=++tot,Rid=++tot;
        Build(Lid,L,M),Build(Rid,M+1,R);
        Merge(t[id],t[Lid],t[Rid],id);
    }
    return;
}

void Rev(int id,int L,int R,int l,int r){
    Pushdown(id);
    if(l<=L&&r>=R)t[id].tag=1,Pushdown(id);
    else if(R<l||r<L)return;
    else{
        Rev(Lid,L,M,l,r),Rev(Rid,M+1,R,l,r);
        if(l<=M&&r>=M+1)rtag[id]^=1;
        Merge(t[id],t[Lid],t[Rid],id);
    }
    return;
}

void Upt(int id,int L,int R,int x){
    Pushdown(id);
    if(L==R)t[id].MakeNode(L);
    else{
        if(x<=M)Upt(Lid,L,M,x),Pushdown(Rid);
        else Upt(Rid,M+1,R,x),Pushdown(Lid);
        Merge(t[id],t[Lid],t[Rid],id);
    }
    return;
}

signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        val[i]=read();
        char c=gc();
        while(c!='A'&&c!='B')c=gc();
        if(c=='A')ty[i]=1;
    }
    Build(1,1,n);
    while(m--){
        scanf("%s",str);
        if(str[0]=='R'){
            int l=read(),r=read();
            Rev(1,1,n,l,r);
        }
        else{
            int x=read(),y=read();
            val[x]=y,Upt(1,1,n,x);
        }
        _write(t[1].res[t[1].w]);
    }
    return 0;
}
