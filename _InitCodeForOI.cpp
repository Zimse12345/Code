// Author: Zimse
// Data: 2023-03-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)

namespace Zimse{const int INF=1.01e9,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y)
{if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int& x,int y){if(x<y)x=y;}
inline void _min(int& x,int y){if(y<x)x=y;}
inline void addmod(int& x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=1.01e6;


signed main(){
    
    return 0;
}

