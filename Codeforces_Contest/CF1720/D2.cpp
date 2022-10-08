/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-20
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

int T,n,a[N],f[N],ans;
int ch[N*16][4],mx[N*16],tot;

signed main(){
    T=read();
    while(T--){
        n=read(),ans=0;
        for(int i=1;i<=n;i++){
            a[i]=read(),f[i]=0;
            for(int j=30,p=0,v=0;j>=0;j--){
                v=((a[i]&(1<<j))?2:0)^(((i-1)&(1<<j))?1:0);
                if(v==0){
                    _max(f[i],mx[ch[p][1]]);
                    p=ch[p][0];
                }
                if(v==1){
                    _max(f[i],mx[ch[p][3]]);
                    p=ch[p][1];
                }
                if(v==2){
                    _max(f[i],mx[ch[p][0]]);
                    p=ch[p][1];
                }
                if(v==3){
                    _max(f[i],mx[ch[p][2]]);
                    p=ch[p][0];
                }
                if(!p)break;
            }
            ++f[i];
            for(int j=30,p=0,v=0;j>=0;j--){
                v=((a[i]&(1<<j))?2:0)^(((i-1)&(1<<j))?1:0);
                if(!ch[p][v])ch[p][v]=++tot;
                _max(mx[ch[p][v]],f[i]);
                v=((a[i]&(1<<j))?1:0)^(((i-1)&(1<<j))?1:0);
                if(!ch[p][v])ch[p][v]=++tot;
                p=ch[p][v];
            }
            _max(ans,f[i]);
        }
        _write(ans);
        for(int i=0;i<=tot;i++){
            ch[i][0]=ch[i][1]=ch[i][2]=ch[i][3]=0;
            mx[i]=0;
        }
        tot=0;
    }
	return 0;
}
