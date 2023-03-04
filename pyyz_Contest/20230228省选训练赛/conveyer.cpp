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
// #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

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

const int N=1000007;

int n,limM,limS,a[N],typ[N],tot,id[N],_id[N],sum,SZ;
vector<int> v[N],b[N];

void ckB(){
    vector<int> t;
    for(int i=1;i<=n;i++){
        for(unsigned j=0;j<b[id[i]].size();j++){
            if(b[id[i]][j]==i){
                b[id[i]][j]=0;
                t.pb(i),++sum;
                break;
            }
        }
    }
    if(t.size()){
        typ[++tot]=2,v[tot]=t;
    }
    return;
}

void Rot(int x){
    for(int i=1;i<=n;i++)_id[(i+x)>n?i+x-n:i+x]=id[i];
    for(int i=1;i<=n;i++)id[i]=_id[i];
    typ[++tot]=-x;
    return;
}

void solve1(){
    for(int i=1;i<=n;i++)id[i]=i;
    for(int i=0;i<SZ;i++){
        vector<int> t;
        for(int j=1;j<=n;j++)if(a[j]!=j&&((a[j]<j?a[j]+n:a[j])-j)%SZ==(SZ-i==SZ?0:SZ-i))t.pb(j);
        if(t.size()){
            for(unsigned j=0;j<t.size();j++){
                b[id[t[j]]].pb(a[t[j]]);
                t[j]=a[t[j]];
            }
            typ[++tot]=1,v[tot]=t;
        }
        Rot(1);
    }
    for(int i=0;i<=SZ;i++)ckB(),Rot(SZ);
    return;
}

void solve2(){
    for(int i=0;i<18;i++){
        vector<int> t;
        for(int j=1;j<=n;j++)if(((a[j]<j?a[j]+n:a[j])-j)&(1<<i))t.pb(a[j]);
        if(t.size()){
            typ[++tot]=1,v[tot]=t;
            Rot(1<<i);
            typ[++tot]=2,v[tot]=t;
        }
    }
    return;
}

signed main(){
    n=read(),limM=read(),limS=read();
    SZ=sqrt(n);
    for(int i=1;i<=n;i++)a[i]=read()+1;
    if(limM>=2048&&limS>=2*n)solve1();
    else solve2();
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++){
        if(typ[i]>0){
            printf("%d %llu ",typ[i],v[i].size());
            for(unsigned j=0;j<v[i].size();j++)printf("%d ",v[i][j]-1);
            pc(10);
        }
        else printf("%d %d\n",3,-typ[i]);
    }
    return 0;
}
