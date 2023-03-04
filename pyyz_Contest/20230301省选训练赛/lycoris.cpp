/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514;
const int Mod=993244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
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

const int N=1000007,M=256;

int n,f[1024][512][2][10];
const char s[2][10]={{'s','a','k','a','n','a',' ',' ',' ',' '},{'c','h','i','n','a','n','a','g','o',' '}};
const int len[2]={6,9};
char str[N];

signed main(){
    n=read();
    scanf("%s",str+1);
    f[0][M][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=M-i/6;j<=M+i/6;j++){
            for(int c=0;c<26;c++)if(c==str[i]-'a'||str[i]=='?'){
                for(int t=0;t<2;t++){
                    for(int l=0;l<len[t];l++){
                        if(c+'a'==s[t][l]){
                            if(l+1==len[t]){
                                if(t==0)addmod(f[i][j+1][0][0],f[i-1][j][t][l]);
                                else addmod(f[i][j-1][0][0],f[i-1][j][t][l]);
                            }
                            else{
                                addmod(f[i][j][t][l+1],f[i-1][j][t][l]);
                            }
                        }
                        else if(c+'a'=='s'){
                            addmod(f[i][j][0][1],f[i-1][j][t][l]);
                        }
                        else if(c+'a'=='c'){
                            addmod(f[i][j][1][1],f[i-1][j][t][l]);
                        }
                        else{
                            addmod(f[i][j][0][0],f[i-1][j][t][l]);
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<2;i++)for(int j=0;j<len[i];j++)addmod(ans,f[n][M][i][j]);
    _write(ans);
    return 0;
}
