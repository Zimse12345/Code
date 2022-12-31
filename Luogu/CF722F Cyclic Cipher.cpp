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
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1000007;

int n,m,k[N],ans[N],pos[64],tot[64];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};
vector<node> p[N];

signed main(){
	n=read(),m=read();
    for(int i=1;i<=n;i++){
        k[i]=read();
        for(int j=0,x;j<k[i];j++){
            x=read();
            p[x].pb(node(i,j));
        }
    }
    for(int i=1;i<=m;i++){
        unsigned pr=0;
		int x,y;
        for(unsigned j=0;j<p[i].size();j++){
            x=k[p[i][j].x],y=p[i][j].y;
            if(j==0||p[i][j].x!=p[i][j-1].x+1){
                pr=j;
                for(int len=1;len<=40;len++)tot[len]=pos[len]=0;
            }
            if(pos[x]!=y){
            	while(tot[x])--tot[k[p[i][pr].x]],++pr;
			}
			pos[x]=y,++tot[x];
			while(1){
				int tag=1;
				for(int a=1;a<=40;a++)if(tot[a]){
					for(int b=a+1;b<=40;b++)if(tot[b]){
						int g=_gcd(a,b);
						if(pos[a]%g!=pos[b]%g){
							tag=0;
							break;
						}
					}
				}
				if(tag)break; 
				--tot[k[p[i][pr].x]],++pr;
			}
			_max(ans[i],j-pr+1);
        }
        _write(ans[i]);
    }
    return 0;
}

