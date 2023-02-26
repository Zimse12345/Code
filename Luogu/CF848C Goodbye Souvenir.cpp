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

const int N=2000007;

int n,m,_a[N],tot,ans[N],isq[N],tr[N];
set<int> pos[N];

struct node{
    int x,y,z,v;
    node(int x=0,int y=0,int z=0,int v=0):x(x),y(y),z(z),v(v){}
}p[N];

bool cmp_z(const node& a,const node& b){return a.z<b.z;}
bool cmp_x(const node& a,const node& b){return a.x<b.x;}
inline void ub(int& x){x+=(x&(-x));}
inline void db(int& x){x-=(x&(-x));}
inline void add(int x,int y){for(;x<N;ub(x))tr[x]+=y;return;}
inline int sum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}

void AddRec(int l,int r,int t,int v){
    v*=(r-l);
    if(l==-INF||l==INF||r==-INF||r==INF)return;
    p[++tot]=node(1,r,t,v);
    p[++tot]=node(l+1,r,t,-v);
    return;
}

void cdq(int L,int R){
    int M=(L+R)/2;
    if(L<R)cdq(L,M),cdq(M+1,R);
    int pos=L;
    for(int i=M+1;i<=R;i++){
        while(pos<=M&&p[pos].x<=p[i].x){
            if(p[pos].v<INF)add(p[pos].y,p[pos].v);
            ++pos;
        }
        if(p[i].v==INF)ans[p[i].z]+=sum(p[i].y);
    }
    for(int i=L;i<pos;i++)if(p[i].v<INF)add(p[i].y,-p[i].v);
    sort(p+L,p+R+1,cmp_x);
    return;
}

signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        _a[i]=read(),pos[_a[i]].insert(i);
        pos[i].insert(-INF),pos[i].insert(INF);
    }
    for(int i=1;i<=n;i++){
        int l=0,r=0;
        for(set<int>::iterator it=pos[i].begin();it!=pos[i].end();it++){
            r=*it,AddRec(l,r,0,1),l=r;
        }
    }
    for(int i=1,a,b,c;i<=m;i++){
        a=read(),b=read(),c=read();
        if(a==1){
            set<int>::iterator it;
            int l,r;
            it=pos[_a[b]].upper_bound(b);
            r=*it,--it,--it,l=*it,pos[_a[b]].erase(b);
            AddRec(l,b,i,-1),AddRec(b,r,i,-1),AddRec(l,r,i,1);
            it=pos[c].lower_bound(b);
            r=*it,--it,l=*it,pos[c].insert(b);
            AddRec(l,b,i,1),AddRec(b,r,i,1),AddRec(l,r,i,-1);
            _a[b]=c;
        }
        else{
            p[++tot]=node(b,c,i,INF);
            isq[i]=1;
        }
    }
    sort(p+1,p+tot+1,cmp_z);
    cdq(1,tot);
    for(int i=1;i<=m;i++)if(isq[i])_write(ans[i]);
    return 0;
}
