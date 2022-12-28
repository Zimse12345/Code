/********************************
*FileName:
*Author: Zimse
*Data: 2022-12-
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
#define pb push_back
#define ll long long
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

using namespace std;

namespace Zimse{
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
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1000007;

int n,_n,s[N],cnt,sumred[N],pre[N],suf[N],ans,nxt[N],f[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};
node op[N];

signed main(){
    n=read();
    for(int i=1;i<=n;i++){
        int ty=read();
        if(ty<=2)op[++_n]=node(ty,read());
        else s[++cnt]=_n;
    }
    s[++cnt]=_n;
    for(int i=1;i<=cnt;i++){
        for(int j=s[i-1]+1;j<=s[i];j++){
            if(op[j].x==2)sumred[i]+=op[j].y;
        }
        pre[i]=sumred[i]+pre[i-1];
    }
    nxt[cnt+1]=cnt+1;
    for(int i=cnt;i>=1;i--){
        suf[i]=sumred[i]+suf[i+1];
        nxt[i]=nxt[i+1];
        if(pre[i]!=pre[i+1])nxt[i]=i+1;
    }
    int exred=0;
    for(int i=1;i<=cnt;i++){
        int rred=suf[i];
        for(int j=s[i-1]+1;j<=s[i];j++){
            if(op[j].x==2)rred-=op[j].y;
            else{
                int val=op[j].y-rred;
                if(val<=0)continue;
                int I=i;
                if(pre[I]-pre[i-1]==0)I=min(cnt,nxt[I]);
                int p=fpow(2,I-i);
                addmod(ans,p);
                int mx=-1;
                for(int ii=0;ii<32&&ii+I<cnt;ii++){
                    mx=ii;
                    if(ii==0)f[ii]=pre[ii+I]-pre[i-1];
                    else f[ii]=f[ii-1]*2+(pre[ii+I]-pre[i-1])-(pre[ii+I-1]-pre[i-1]);
                    _min(f[ii],INF*2);
                }
                for(int ii=mx;ii>=0;ii--){
                    if(val>f[ii])val-=f[ii],addmod(ans,p*(1ll<<ii));
                }
            }
        }
        exred=min(INF,exred+sumred[i])*2;
        pre[i]-=exred;
    }
    _write(ans);
    return 0;
}
