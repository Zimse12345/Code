/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-26
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
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

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
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=4e6+7;

int n,m,k,hd[N],nxt[N],to[N],ec;
int stk[N],tp,vis[N],ins[N],E,ans,_e;
vector<int> A;
int ring[N],rc;

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void tarjan(int u,int from){
    stk[++tp]=u,ins[u]=1,vis[u]=1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        if(ins[v]){
        	++E;
            int sz=1;
            for(int j=tp;stk[j]!=v;--j)++sz;//printf("(u=%d stk[j]=%d)\n",u,stk[j]);
            A.push_back(sz);
//            printf("(%d -> %d sz=%d)\n",u,v,sz);
        }
        else if(!vis[v])tarjan(v,u),++E;
    }
    ins[u]=0,--tp;
    return;
}

signed main(){
     ifile("desert.in");
     ofile("desert.out");
    n=read(),m=read(),k=read();
    for(int i=1,u,v;i<=m;i++){
        u=read(),v=read();
        add(u,v),add(v,u);
    }
    for(int i=1;i<=n;i++)if(!vis[i]){
        tarjan(i,0),++ans;
        for(unsigned j=0;j<A.size();j++)E-=A[j],ring[++rc]=A[j];//printf("ring(%d)\n",ring[rc]);
        A.resize(0);
        // printf("E(%d)\n",E);
        _e+=E,E=0;
    }
    int tot=_e;
    for(int i=1;i<=rc;i++)tot+=ring[i];
//    printf("(%d (%d + %d) %d)\n",tot,_e,tot-_e,m);
    int p=min(k,_e);
    k-=p,ans+=p;
    if(k){
    	sort(ring+1,ring+rc+1);
        for(int i=rc;i>=1;i--){
            --k,--ring[i];
            p=min(k,ring[i]);
            k-=p,ans+=p;
            if(!k)break;
        }
    }
    _write(ans);
//    _write(ec); 
    return 0;
}

