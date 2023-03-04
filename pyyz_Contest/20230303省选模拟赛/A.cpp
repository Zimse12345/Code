/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
#define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
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

const int N=300007;

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{
        if(x==_.x)return y<_.y;
        return x<_.x;
    }
};

struct Node{
    int *ptr,val;
    Node(int *ptr=NULL):ptr(ptr),val(ptr==NULL?0:*ptr){}
};

map<node,int> pre;
vector<node> t[N*4];
int n,ans,fx[N],fy[N],sx[N],sy[N],px[N],py[N],top;
Node stk[N*16];

void update(int id,int L,int R,int l,int r,node x){
    if(l<=L&&r>=R)t[id].pb(x);
    else if(r<L||R<l)return;
    else update(Lid,L,M,l,r,x),update(Rid,M+1,R,l,r,x);
    return;
}

int Fx(int x){
    return fx[x]==x?x:Fx(fx[x]);
}

int Fy(int x){
    return fy[x]==x?x:Fy(fy[x]);
}

void addnode(int x,int y){
    int a=Fx(x),b=Fy(y);
    if(py[a]==b)return;
    else if(!py[a]&&!px[b]){
        stk[++top]=Node(&py[a]),stk[++top]=Node(&px[b]);
        py[a]=b,px[b]=a,++ans;
    }
    else if(!py[a]){
        stk[++top]=Node(&fx[x]),stk[++top]=Node(&sx[px[b]]),stk[++top]=Node(&py[a]);
        fx[x]=px[b],py[a]=b,ans+=sy[b],sx[px[b]]++;
    }
    else if(!px[b]){
        stk[++top]=Node(&fy[y]),stk[++top]=Node(&sy[py[a]]),stk[++top]=Node(&px[b]);
        fy[y]=py[a],px[b]=a,ans+=sx[a],sy[py[a]]++;
    }
    else{
        int ax=a,ay=py[a],bx=px[b],by=b;
        ans+=(sx[ax]+sx[bx])*(sy[ay]+sy[by])-sx[ax]*sy[ay]-sx[bx]*sy[by];
        if(sx[ax]<sx[bx])swap(ax,bx);
        if(sy[ay]<sy[by])swap(ay,by);
        stk[++top]=Node(&py[ax]),stk[++top]=Node(&px[ay]);
        stk[++top]=Node(&fx[bx]),stk[++top]=Node(&sx[ax]);
        stk[++top]=Node(&fy[by]),stk[++top]=Node(&sy[ay]);
        py[ax]=ay,px[ay]=ax;
        fx[bx]=ax,sx[ax]+=sx[bx];
        fy[by]=ay,sy[ay]+=sy[by];
    }
    return;
}

void solve(int id,int L,int R){
    int _top=top;
    stk[++top]=Node(&ans);
    for(unsigned i=0;i<t[id].size();i++)addnode(t[id][i].x,t[id][i].y);
    if(L==R)write_(ans);
    else solve(Lid,L,M),solve(Rid,M+1,R);
    while(top>_top)*stk[top].ptr=stk[top].val,--top;
    return;
}

signed main(){
	// ifile("A.in");
	// ofile("A.out");
	
    for(int i=1;i<=300000;i++)fx[i]=fy[i]=i,sx[i]=sy[i]=1;
    n=read();
    for(int i=1,x,y;i<=n;i++){
        x=read(),y=read();
        if(!pre[node(x,y)])pre[node(x,y)]=i;
        else{
            update(1,1,n,pre[node(x,y)],i-1,node(x,y));
            pre[node(x,y)]=0;
        }
    }
    for(map<node,int>::iterator it=pre.begin();it!=pre.end();it++){
        if(it->second)update(1,1,n,it->second,n,it->first);
    }
    solve(1,1,n),pc(10);
    return 0;
}
