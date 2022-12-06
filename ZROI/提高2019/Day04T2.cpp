/********************************
*FileName:
*Author: Zimse
*Data: 2022-10-
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
//#define int long long
#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

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

const int N=1000007,V=1000000;

int n,a[N],vis[N],p[N],m,pre[N],ansl,ansr,stk[N],top;
vector<int> pos[N];

signed main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read(),pos[a[i]].pb(i);
    for(int i=2;i<=V;i++)if(!vis[i]){
        m=top=0;
        for(int j=i;j<=V;j+=i)vis[j]=1;
        for(int j=i;j<=V;j+=i){
            for(unsigned k=0;k<pos[j].size();k++)p[++m]=pos[j][k];
        }
        sort(p+1,p+m+1);
        
        for(int j=1;j<=m;j++){
            pre[j]=pre[j-1]-(p[j]-p[j-1]-1)+1;
            int L=1,R=top,s=j;
            while(L<=R){
                if(0<=pre[j]-pre[stk[M]]+1)s=stk[M],R=M-1;
                else L=M+1;
            }
            L=p[s],R=p[j];
            int cnt=(pre[j]-pre[s]+1+(R-L+1))/2;
            while(cnt*2>R-L+1&&L>1)--L;
            while(cnt*2>R-L+1&&R<n)++R;
            if(R-L+1>ansr-ansl+1)ansl=L,ansr=R;
            if(R-L+1==ansr-ansl+1&&L<ansl)ansl=L,ansr=R;
            if(!top||pre[j]<pre[stk[top]])stk[++top]=j;
        }
    }
    write_(ansl),_write(ansr);
    return 0;
}
