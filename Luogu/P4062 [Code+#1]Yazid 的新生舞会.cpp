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

const int N=1000007;

int n,typ,a[N],p[N],p1[N],p2[N],ans,lp[N],rp[N],rv[N],val[N],tr[N];
vector<int> pos[N];

inline void ub(int &x){x+=(x&(-x));return;}
inline void db(int &x){x-=(x&(-x));return;}
inline void add(int x,int y){for(;x<N;ub(x))tr[x]+=y;return;}
inline int sum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}

signed main(){
    n=read(),typ=read();
    for(int i=1;i<=n;i++)a[i]=read(),pos[a[i]].pb(i);
    for(int v=0;v<n;v++)if(pos[v].size()){
        int psum=0,pre=0,mn=0,tot=0,tot1=0,tot2=0,cnt=0;
        pos[v].pb(n+1);
        for(unsigned i=0;i<pos[v].size();i++){
            if(i){
                if(cnt&&psum+1>rv[cnt]){
                    p2[++tot2]=rp[cnt],val[rp[cnt]]=rv[cnt];
                    --rp[cnt],++rv[cnt];
                    if(rp[cnt]<lp[cnt])--cnt;
                }
                p1[++tot1]=pre+1,val[++pre]=++psum;
            }
            int len=pos[v][i]-pre-1;
            while(pre&&len){
                --psum,++pre,--len;
                if(psum>mn)p1[++tot1]=pre,val[pre]=psum;
                else break;
            }
            if(psum<=mn)lp[++cnt]=pre,rp[cnt]=pre+len,rv[cnt]=psum-len;
            pre+=len,psum-=len;
            _min(mn,psum);
        }
        sort(p2+1,p2+tot2+1);
        int s1=1,s2=1;
        while(s1<=tot1||s2<=tot2){
            if(s1<=tot1&&(s2>tot2||p1[s1]<p2[s2]))p[++tot]=p1[s1++];
            else p[++tot]=p2[s2++];
        }
        for(int i=1;i<=tot;i++){
            ans+=sum(val[p[i]]+499999);
            add(val[p[i]]+500000,1);
        }
        for(int i=1;i<=tot;i++)add(val[p[i]]+500000,-1);
    }
    _write(ans);
    return 0;
}
