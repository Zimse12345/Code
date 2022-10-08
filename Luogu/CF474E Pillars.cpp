/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-27
*Description:
*Other:
********************************/

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
#define ll long long
#define int long long
#define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||c>57){if(c==45)y=-1;c=gc();}while(c>=48&&c<=57)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000000000000000;
}using namespace Zimse;

const int N=1e6+7;

int n,d,a[N],Mx[N],pre[N];
int ch[N*4][2],rt,tot;

struct node{
    int mx,id;
    node(int mx=0,int id=0):mx(mx),id(id){}
    bool operator < (const node& _)const{return mx<_.mx;}
}t[N*4];

void update(int L,int R,int& id,int x,node p){
    if(!id)id=++tot;
    if(L==R){
        if(t[id]<p)t[id]=p;
    }
    else{
        if(x<=M)update(L,M,Lid,x,p);
        else update(M+1,R,Rid,x,p);
        t[id]=max(t[Lid],t[Rid]);
    }
    return;
}

node query(int L,int R,int id,int l,int r){
    if(!id||(r<L||R<l))return node(0,0);
    if(l<=L&&r>=R)return t[id];
    return max(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

int o[N],T;

signed main(){
    n=read(),d=read();
    for(int i=1;i<=n;i++)a[i]=read();
    int ans=0,pos=0;
    for(int i=1;i<=n;i++){
        node p=max(query(1,INF,rt,1,a[i]-d),query(1,INF,rt,a[i]+d,INF));
        Mx[i]=p.mx+1,pre[i]=p.id;
        ++p.mx,p.id=i;
        update(1,INF,rt,a[i],p);
        if(Mx[i]>ans)ans=Mx[i],pos=i;
    }
    _write(ans);
    while(pos)o[++T]=pos,pos=pre[pos];
    for(int i=T;i>=1;i--)write_(o[i]);
    pc(10);
    return 0;
}
