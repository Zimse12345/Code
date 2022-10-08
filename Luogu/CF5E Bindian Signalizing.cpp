/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-25
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

const int N=2e6+7;

int n,a[N],stk[N],l=1,r,ans;

signed main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=a[i+n]=read();
    int _ans=0;
    for(int i=1;i<=n*2;i++){
        while(l<=r&&i-stk[l]>=n)++l;
        while(l<=r&&a[i]>a[stk[r]])++ans,--r;
        if(l<=r){
            int mid=r,L=l,R=r;
            while(L<=R){
                if(a[stk[M]]>a[i])mid=M,L=M+1;
                else R=M-1;
            }
            if(a[stk[l]]==a[i])mid=l;
            ans+=r-mid+1;
        }
        stk[++r]=i;
        if(i==n)_ans=ans;
    }
    ans-=_ans;
    int mx=0,cnt=0,se,secnt;
    for(int i=1;i<=n;i++){
        if(a[i]==mx)++cnt;
        else if(a[i]==se)++secnt;
        else if(a[i]>mx)se=mx,secnt=cnt,mx=a[i],cnt=1;
        else if(a[i]>se)se=a[i],secnt=1;
    }
    if(cnt==1)ans-=secnt;
    else ans-=cnt*(cnt-1)/2;
    _write(ans);
    return 0;
}
