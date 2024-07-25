// Author:Zimse  Data:2024-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
// #define int long long
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e6;
int n,t[N];
char s[N];

int hs(char x,char y){
    return (y-'a')*10+x-'0';
}

void clr(){
    for(int i=1;i<=1000;i++)t[i]=0;
    return;
}

bool ck1(){
    clr();
    int p=1;
    for(int i=1;i<=14;i++){
        int v=hs(s[p],s[p+1]);
        t[v]++;
        p+=2;
    }
    if(t[hs('1','s')]&&t[hs('9','s')]&&t[hs('1','m')]&&t[hs('9','m')]&&t[hs('1','p')]&&t[hs('9','p')]){
        bool tag=true;
        for(int i=1;i<=7;i++)if(t[hs(i+'0','z')]==0)tag=false;
        return tag;
    }
    return false;
}

bool ck2(){
    clr();
    int p=1;
    for(int i=1;i<=14;i++){
        int v=hs(s[p],s[p+1]);
        t[v]++;
        p+=2;
    }
    for(int i=1;i<=1000;i++)if(t[i]!=0&&t[i]!=2)return false;
    return true;
}

signed main(){
    n=read();
    while(n--){
        scanf("%s",s+1);
        if(ck1())printf("Thirteen Orphans\n");
        else if(ck2())printf("7 Pairs\n");
        else printf("Otherwise\n");
    }
    return 0;
}

