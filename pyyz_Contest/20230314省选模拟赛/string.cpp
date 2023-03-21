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
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
}using namespace Zimse;using namespace std;

const int N=300007,SZ=1100;

int n,m,A,B,C,val[N],len[N],Len,g[N];
int ans[N],G[N],gl[N],gr[N],sum;
int bl[N],br[N],Id[N],cnt,tot;
int *ptr[N*4],data[N*4],cur;
char str[N];
vector<char> s[N];
inline int calc(const int x){return x*(x+1)/2;}

struct query{
    int l,r,id;
    query(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
    bool operator < (const query& _)const{
        if(Id[l]==Id[_.l])return r>_.r;
        return l<_.l;
    }
}q[N];

struct node{
    int to[26],sz;
}trie[N];

void Clear(){
    memset(trie,0,sizeof (node)*(tot+1));
    memset(G,0,sizeof (int)*Len+1);
    for(int i=1;i<=Len;i++)gl[i]=i-1,gr[i]=i+1;
    tot=sum=0;
    return;
}

void ins(int& x){
    ptr[++cur]=&x,data[cur]=x;
    return;
}

void del(int x){
    sum+=calc(gr[x]-gl[x]-1)-calc(x-gl[x]-1)-calc(gr[x]-x-1);
    gr[gl[x]]=gr[x],gl[gr[x]]=gl[x];
    return;
}

void Add(int i,int t,int tag=0){
    for(int j=0,c=0,x=0,p=0;j<len[i];j++){
        c=s[i][j];
        if(!trie[p].to[c])trie[p].to[c]=++tot;
        if(tag)ins(trie[trie[p].to[c]].sz);
        p=trie[p].to[c],trie[p].sz+=val[i]*t,x=B*trie[p].sz+A*(j+1);
        if(t==1&&x>=C&&(trie[p].sz==val[i]*t||x-val[i]*B<C))++G[g[j+1]];
        if(t==-1&&(trie[p].sz==0||x<C)&&x+val[i]*B>=C){
            if(tag)ins(G[g[j+1]]);
            --G[g[j+1]];
            if(!G[g[j+1]]){
                if(tag)ins(gr[gl[g[j+1]]]),ins(gl[gr[g[j+1]]]);
                del(g[j+1]);
            }
        }
    }
    return;
}

signed main(){
    n=read(),A=read(),B=read(),C=read();
    for(int i=1;i<=n;i++)val[i]=read();
    for(int i=1;i<=n;i++){
        scanf("%s",str),len[i]=strlen(str),_max(Len,len[i]);
        for(int j=0;j<len[i];j++)s[i].pb(str[j]-'a');
    }
    for(int i=1;i<=Len;i++)g[i]=read();
    for(int l=1,r=0,sumlen=0;l<=n;){
        while(r<n&&(sumlen+len[r+1]<=SZ||!sumlen))sumlen+=len[++r];
        bl[++cnt]=l,br[cnt]=r;
        for(int i=l;i<=r;i++)Id[i]=cnt;
        l=r+1,sumlen=0;
    }
    m=read();
    for(int i=1,l,r;i<=m;i++){
        l=read(),r=read();
        q[i]=query(l,r,i);
    }
    sort(q+1,q+m+1);
    for(int l=1,r=0;l<=m;){
        Clear();
        while(Id[q[r+1].l]==Id[q[l].l])++r;
        int L=bl[Id[q[r].l]],R=n;
        for(int i=L;i<=R;i++)Add(i,1);
        for(int i=1;i<=Len;i++)if(!G[i])del(i);
        for(int i=l;i<=r;i++){
            while(R>q[i].r)Add(R,-1),--R;
            int _sum=sum;
            for(int j=L;j<q[i].l;j++)Add(j,-1,1);
            ans[q[i].id]=sum,sum=_sum;
            while(cur)*ptr[cur]=data[cur],--cur;
        }
        l=r+1;
    }
    for(int i=1;i<=m;i++){
        int Q=calc(Len),P=Q-ans[i],gcd=_gcd(P,Q);
        P/=gcd,Q/=gcd;
        WRI(P),pc('/'),_write(Q);
    }
    return 0;
}
