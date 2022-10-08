/********************************
*FileName:
*Author: Zimse
*Data:
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

const int N=1e6+7;

int Len,n,_c,_w;
int _l[N],_r[N],_v[N],_op[N],f[N];
int sav[N],cutcost[N],tl[N],sum[5010][5010];

signed main(){
    ifile("bee.in");
    ofile("bee.out");
    Len=read(),n=read(),_c=read(),_w=read();
    for(int i=1;i<=n;i++){
        _l[i]=read(),_r[i]=read(),_v[i]=read(),_op[i]=read();
        for(int j=_l[i];j<_r[i];j++)cutcost[j]+=max(0,_v[i]);
        if(_op[i]>0){
            for(int j=_l[i];j<_r[i];j++)sav[j]=1;
        }
        if(_op[i]==1){
            if(!tl[_r[i]])tl[_r[i]]=_l[i];
            else _min(tl[_r[i]],_l[i]);
        }
        sum[1][_r[i]]+=_v[i];
        sum[_l[i]+1][_r[i]]-=_v[i];
    }
    for(int i=1;i<=Len;i++){
        for(int j=1;j<=Len;j++){
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    // for(int i=1;i<=Len;i++)printf("cost(%d)=%d\n",i,cutcost[i]);
    for(int i=1;i<=Len;i++){
        if(!tl[i])f[i]=f[i-1];
        else f[i]=-INF;
        for(int j=i;j>=1;j--){
            if(sav[i]||sav[j-1])continue;
            if(tl[i]&&j>tl[i])continue;
            int tot=sum[j][i]-cutcost[j-1]-cutcost[i]-_w-_c*(i-j+1);
            // if(tot==-20||tot==-11)printf("(%d,%d) [%d -%d -%d -%d -%d]\n",j,i,sum[j][i],cutcost[j-1],cutcost[i],_w,_c*(i-j+1));
            _max(f[i],f[j-1]+tot);
        }
        // printf("f[%d]=%d tl=%d\n",i,f[i],tl[i]);
    }
    _write(f[Len]);
    return 0;
}
