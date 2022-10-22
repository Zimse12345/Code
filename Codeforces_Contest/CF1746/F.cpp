/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-
*Description:
*Other:
********************************/

#include<bits/stdc++.h>

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define ll long long
// #define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
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
const int INF=1000114514;
}using namespace Zimse;

const int N=1e6+7;

int n,q,a[N],_a[N],qt[N],ql[N],qr[N],qx[N];
int tag[N],tr[N],v[N],vt,cnt,ans[N];
map<int,int> mp;


ll seed=chrono::system_clock::now().time_since_epoch().count();
mt19937_64 rnd(seed);
inline ll rm(ll x,ll y){return (ll)(rnd()%(y-x+1ll)+x);}

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x,int y){for(;x<N;ub(x))tr[x]+=y;return;}
inline int sum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}

signed main(){
    // srand(114514);
    n=read(),q=read();
    for(int i=1;i<=n;i++)a[i]=read(),v[++vt]=a[i];
    for(int i=1;i<=q;i++){
        qt[i]=read(),ql[i]=read(),qr[i]=read();
        if(qt[i]==2){
            qx[i]=read();
            if((qr[i]-ql[i]+1)%qx[i]==0)ans[i]=1;
        }
        else v[++vt]=qr[i];
    }
    sort(v+1,v+vt+1);
    for(int i=1;i<=vt;i++)if(v[i]!=v[i-1])mp[v[i]]=++cnt;
    for(int i=1;i<=n;i++)a[i]=mp[a[i]];
    for(int i=1;i<=q;i++)if(qt[i]==1)qr[i]=mp[qr[i]];
    for(int I=1;I<=24;I++){
        for(int i=1;i<=cnt;i++)tag[i]=rm(0,1);
        for(int i=1;i<=n;i++){
            add(i,tag[a[i]]);
            _a[i]=a[i];
        }
        for(int i=1;i<=q;i++){
            if(qt[i]==1){
                add(ql[i],-tag[_a[ql[i]]]);
                _a[ql[i]]=qr[i];
                add(ql[i],tag[_a[ql[i]]]);
            }
            else{
                if((sum(qr[i])-sum(ql[i]-1))%qx[i]!=0)ans[i]=0;
            }
        }
        for(int i=1;i<=n;i++)add(i,-tag[_a[i]]);
    }
    for(int i=1;i<=q;i++)if(qt[i]==2)_ck(ans[i]);
    return 0;
}
