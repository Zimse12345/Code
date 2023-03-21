/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <algorithm>
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
#include <bitset>

#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
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

const int N=1048576,SZ=512;

int n,q,a[N],v[32],V[32],f[32],vis[32];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return y>_.y;};
};

struct block{
    int l,r,s;
    bitset<N> vis;
    
    void ReBuild(int x=0,int y=0){
        s=0;
        if(x){
            for(int i=l;i<=r;i++)s^=a[i],vis[s]=0;
            a[x]=y,s=0;
        }
        for(int i=l;i<=r;i++)s^=a[i],vis[s]=1;
        return;
    }

    int findnext(int L,int val){
        for(int i=l,s=0;i<=r;i++){
            s^=a[i];
            if(i>=L&&s==val)return i;
        }
        return 0;
    }
}B[256];
int cnt,Id[N];

int FindNext(int L,int val){
    for(int i=1,s=0;i<=cnt;i++){
        if(L<=B[i].r&&B[i].vis[val^s]){
            int p=B[i].findnext(L,val^s);
            if(p)return p;
        }
        s^=B[i].s;
    }
    return n+1;
}

signed main(){
    // ifile("three.in");
    // ofile("three.out");

    n=read(),q=read();
    int s=0;
    for(int i=1;i<=n;i++)a[i]=read(),s^=a[i];
    for(int l=1,r=0;l<=n;l=r+1){
        r=min(n,l+SZ-1);
        B[++cnt].l=l,B[cnt].r=r;
        B[cnt].ReBuild();
        for(int i=l;i<=r;i++)Id[i]=cnt;
    }
    while(q--){
        int typ=read();
        if(typ==1){
            int x=read(),y=read();
            s^=a[x]^y;
            B[Id[x]].ReBuild(x,y);
        }
        else{
            int k=read(),ans=0;
            for(int i=0;i<k;i++)v[i]=read();
            for(int i=0;i<(1<<k);i++){
                f[i]=n+1,V[i]=vis[i]=0;
                for(int j=0;j<k;j++)if(i&(1<<j))V[i]^=v[j];
            }
            priority_queue<node> q;
            f[0]=0,q.push(node(0,0));
            while(!q.empty()){
                int u=q.top().x;
                q.pop();
                if(vis[u]++)continue;
                for(int i=0;i<k;i++){
                    int to=u^(1<<i),pos=FindNext(f[u]+1,V[to]);
                    if(pos<f[to])f[to]=pos,q.push(node(to,f[to]));
                    if(pos<=n&&V[to]==s){
                        ans=1;
                        break;
                    }
                }
                if(ans)break;
            }
            if(ans)printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}
