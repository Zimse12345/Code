/************************
*FileName:
*Author: Zimse
*Data: 2023-01-
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
const int INF=2000000000000114514;
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

const int N=200007;

int L,R,n,len[N],_len[N],c[N],to[N][32];
vector<char> s[N];
vector<int> prelen[N];
char str[N];

void sol(int p,int l,int r){
    // printf("(%d %d %d)\n",p,l,r);
    if(p==n){
        for(int i=l;i<=r;i++)pc(s[p][i-1]+'a');
        return;
    }
    int ll_=0,rr=len[p]-1,res=-1;
    while(ll_<=rr){
        int mm=(ll_+rr)/2;
        if(prelen[p][mm]<l)res=mm,ll_=mm+1;
        else rr=mm-1;
    }
    int pre=0;
    if(res>=0)pre=prelen[p][res];
    for(int i=res+1;i<len[p];i++){
        int _l=pre+1,_r=pre+_len[to[p][s[p][i]]];
        if(!to[p][s[p][i]])_r=_l;
        // printf("[ %d %d %d %d]\n",l,r,_l,_r);
        if(_l>r)break;
        if(to[p][s[p][i]])sol(to[p][s[p][i]],max(_l,l)-_l+1,min(_r,r)-_l+1);
        else pc(s[p][i]+'a');
        pre=_r;
    }
    return;
}

signed main(){
    L=read(),R=read(),n=read();
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        c[i]=str[0]-'a';
        scanf("%s",str);
        len[i]=strlen(str);
        for(int j=0;j<len[i];j++)s[i].pb(str[j]-'a');
    }
    len[0]=_len[0]=1,s[0].pb(0);
    for(int i=n;i>=0;i--){
        for(int j=0;j<26;j++)to[i][j]=to[i+1][j];
        if(i<n){
            to[i][c[i+1]]=i+1;
            if(len[i+1]==1&&to[i+1][s[i+1][0]])to[i][c[i+1]]=to[i+1][s[i+1][0]];
        }
        int sum=0;
        for(int j=0;j<len[i];j++)sum=min(INF,sum+_len[to[i][s[i][j]]]),prelen[i].pb(sum);
        _len[i]=sum;
        // printf("_len[%d]=%d\n",i,_len[i]);
    }
    sol(0,L,R);
    pc(10);
    return 0;
}
